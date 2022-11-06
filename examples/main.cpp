#include <iostream>

#include <memory>

#include <PixelWindow/PixelWindow.h>

#include "BasicRayTracer/RayTracer.h"
#include "BasicRayTracer/Scene.h"
#include "BasicRayTracer/Sphere.h"
#include "BasicRayTracer/Camera.h"
#include "BasicRayTracer/Lambertian.h"
#include "BasicRayTracer/Metal.h"
#include "BasicRayTracer/Dielectric.h"

int main() {

	std::shared_ptr<pw::PixelWindow> window = std::make_shared<pw::PixelWindow>(640, 360, "Ray Tracer", false);

	brt::RayTracer tracer = brt::RayTracer(640, 360);
	
	brt::Camera camera = brt::Camera(window->getWidth(), window->getHeight(), 90, lm::Vector3f({ -2,2,1 }), { 0,0,-1 }, { 0,1,0 });
	//brt::Camera camera = brt::Camera(window->getWidth(), window->getHeight(), 90);

	auto shinyLeft = std::make_shared<brt::Metal>(lm::Vector3f({ 0.8f,0.8f, 0.8f }));
	auto shinyGold = std::make_shared<brt::Metal>(lm::Vector3f({ 0.8f,0.6f, 0.2f }));
	auto mattGround = std::make_shared<brt::Lambertian>(lm::Vector3f({ 0.8f, 0.8f, 0 }));
	auto mattBlue = std::make_shared<brt::Lambertian>(lm::Vector3f({ 0.1f, 0.2f, 0.5f }));
	auto mattGold = std::make_shared<brt::Lambertian>(lm::Vector3f({ 0.8f, 0.6f, 0.2f }));

	auto dielc1 = std::make_shared<brt::Dielectric>(1.5f);
	auto dielc2 = std::make_shared<brt::Dielectric>(1.5f);

	brt::Scene scene;
	scene.addObject(std::make_unique<brt::Sphere>(lm::Vector3f({ 0,0,-1 }), 0.5f, mattBlue));
	scene.addObject(std::make_unique<brt::Sphere>(lm::Vector3f({ 0,-100.5, -1 }), 100.0f, mattGround));
	scene.addObject(std::make_unique<brt::Sphere>(lm::Vector3f({ 1,0,-1 }), 0.5f, shinyGold));
	scene.addObject(std::make_unique<brt::Sphere>(lm::Vector3f({ -1,0,-1 }), 0.5f, dielc1));
	scene.addObject(std::make_unique<brt::Sphere>(lm::Vector3f({ -1,0,-1 }), -0.45f, dielc2));

	tracer.renderScene(scene, camera, 100);


	window->makeCurrent();
	while (window->isActive()) {
		window->beginFrame();

		window->setBackgroundColor(0);
		tracer.showOnWindow(*window);

		window->endFrame();

		window->pollEvents();
	}
	
	return 0;
}
