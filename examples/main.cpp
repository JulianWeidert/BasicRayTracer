#include <iostream>

#include <memory>

#include <PixelWindow/PixelWindow.h>

#include "BasicRayTracer/RayTracer.h"
#include "BasicRayTracer/Scene.h"
#include "BasicRayTracer/Sphere.h"
#include "BasicRayTracer/Camera.h"

int main() {

	std::shared_ptr<pw::PixelWindow> window = std::make_shared<pw::PixelWindow>(640, 640, "Ray Tracer", false);

	brt::RayTracer tracer = brt::RayTracer(640, 640);
	
	brt::Camera camera = brt::Camera(window->getWidth(), window->getHeight());

	brt::Scene scene;
	scene.addObject(std::make_unique<brt::Sphere>(lm::Vector3f({ 0,0,-1 }), 0.5f));

	tracer.renderScene(scene, camera);


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
