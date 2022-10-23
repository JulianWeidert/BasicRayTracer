#include <iostream>

#include <memory>

#include <PixelWindow/PixelWindow.h>

#include "BasicRayTracer/RayTracer.h"
#include "BasicRayTracer/Scene.h"
#include "BasicRayTracer/Sphere.h"

int main() {

	std::shared_ptr<pw::PixelWindow> window = std::make_shared<pw::PixelWindow>(640, 640, "Ray Tracer", false);

	brt::RayTracer tracer = brt::RayTracer(640, 640);
	
	brt::Scene scene;
	scene.addObject(std::make_unique<brt::Sphere>(lm::Vector3f({ 0,0,-2 }), 1));
	scene.addObject(std::make_unique<brt::Sphere>(lm::Vector3f({ 1,1,-3 }), 1));

	tracer.renderScene(scene);


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
