
#include <LeptonMath/Vector.h>

#include "BasicRayTracer/RayTracer.h"

#include <iostream>

namespace brt {


	RayTracer::RayTracer(int width, int height) : width(width), height(height)  {
		this->frameBuffer = std::make_unique<int[]>(size_t(width) * height);
	}


	void RayTracer::renderScene(const Scene& scene, const Camera& camera) {

		// for every pixel...
		for (int y = 0; y < this->height; ++y) {
			for (int x = 0; x < this->width; ++x) {
				
				auto ray = camera.getRay(x, y);
				int color = scene.traceScene(ray);

				this->frameBuffer[size_t(y) * this->width + x] = color;
			}
		}
	}

	void RayTracer::showOnWindow(pw::PixelWindow& window) const {
		int minWidth = std::min(window.getWidth(), this->width);
		int minHeight = std::min(window.getHeight(), this->height);

		for (int y = 0; y < minHeight; ++y) {
			for (int x = 0; x < minWidth; ++x) {
				int pixel = y * this->width + x;

				window.setPixel(x, y, frameBuffer[pixel]);
			}
		}

	}

}
