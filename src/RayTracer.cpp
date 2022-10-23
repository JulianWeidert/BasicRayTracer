
#include <LeptonMath/Vector.h>

#include "BasicRayTracer/RayTracer.h"

#include <iostream>

namespace brt {


	RayTracer::RayTracer(int width, int height) : width(width), height(height)  {
		this->frameBuffer = std::make_unique<int[]>(size_t(width) * height);
	}


	void RayTracer::renderScene(const Scene& scene) {
		// Canvas Coordinates:
		// (-1,1,0)					(1,1,0)
		//				(0,0,0)
		// (-1,-1,0)				(1,-1,0)

		lm::Vector3f origin = { 0,0,1 }; // For testing

		int cnt = 0;

		// for every pixel...
		for (int y = 0; y < this->height; ++y) {
			for (int x = 0; x < this->width; ++x) {
				float canvasX = 2 * float(x) / this->width - 1.0f;
				float canvasY = -(2 * float(y) / this->height - 1.0f);
				float canvasZ = 0;

				lm::Vector3f canvasCoord = { canvasX, canvasY, canvasZ };
				auto dir = canvasCoord - origin;

				auto ray = Ray(origin, dir);
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
