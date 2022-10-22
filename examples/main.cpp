#include <iostream>

#include <memory>

#include <PixelWindow/PixelWindow.h>

int main() {

	std::shared_ptr<pw::PixelWindow> window = std::make_shared<pw::PixelWindow>(640, 480, "Ray Tracer", false);

	window->makeCurrent();
	while (window->isActive()) {

		
		window->swapBuffers();

		window->pollEvents();
	}
	
	return 0;
}
