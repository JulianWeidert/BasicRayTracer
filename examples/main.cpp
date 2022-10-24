#include <iostream>

#include <memory>

#include <PixelWindow/PixelWindow.h>

#include "BasicRayTracer/RayTracer.h"
#include "BasicRayTracer/Scene.h"
#include "BasicRayTracer/Sphere.h"
#include "BasicRayTracer/Camera.h"
#include "BasicRayTracer/Lambertian.h"
#include "BasicRayTracer/Metal.h"

int main() {

	std::shared_ptr<pw::PixelWindow> window = std::make_shared<pw::PixelWindow>(640, 640, "Ray Tracer", false);

	brt::RayTracer tracer = brt::RayTracer(640, 640);
	
	brt::Camera camera = brt::Camera(window->getWidth(), window->getHeight());

	auto shinyLeft = std::make_shared<brt::Metal>(lm::Vector3f({ 0.8f,0.8f, 0.8f }));
	auto shinyRight = std::make_shared<brt::Metal>(lm::Vector3f({ 0.8f,0.6f, 0.2f }));
	auto mattGround = std::make_shared<brt::Lambertian>(lm::Vector3f({ 0.8f, 0.8f, 0 }));
	auto mattCenter = std::make_shared<brt::Lambertian>(lm::Vector3f({ 0.7f, 0.3f, 0.3f }));

	brt::Scene scene;
	scene.addObject(std::make_unique<brt::Sphere>(lm::Vector3f({ 0,0,-1 }), 0.5f, mattCenter));
	scene.addObject(std::make_unique<brt::Sphere>(lm::Vector3f({ 0,-100.5, -1 }), 100.0f, mattGround));
	scene.addObject(std::make_unique<brt::Sphere>(lm::Vector3f({ 1,0,-1 }), 0.5f, shinyRight));
	scene.addObject(std::make_unique<brt::Sphere>(lm::Vector3f({ -1,0,-1 }), 0.5f, shinyLeft));

	tracer.renderScene(scene, camera, 10);


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
