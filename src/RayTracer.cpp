
#include <ctime>
#include <cstdlib>

#include <LeptonMath/Vector.h>

#include "BasicRayTracer/RayTracer.h"
#include "BasicRayTracer/Util.h"
#include "BasicRayTracer/Random.h"

#include <iostream>

namespace brt {


	RayTracer::RayTracer(int width, int height) : width(width), height(height)  {
		this->frameBuffer = std::make_unique<int[]>(size_t(width) * height);
	}


	void RayTracer::renderScene(Scene& scene, const Camera& camera, int samplesPerPixel) {

		RNG32 rng;

		// for every pixel...
		for (int y = 0; y < this->height; ++y) {
			for (int x = 0; x < this->width; ++x) {
				
				lm::Vector3f color = { 0, 0, 0};

				constexpr unsigned int max = std::numeric_limits<unsigned int>::max();

				for (int s = 0; s < samplesPerPixel; ++s) {
					auto ray = camera.getRay(x + rng.next()/float(max), y + rng.next()/ float(max));
					color = color + scene.traceScene(ray, -1, 1000, 50);
				}

				color = 1.0f / samplesPerPixel * color;

				this->frameBuffer[size_t(y) * this->width + x] = convertColor(color);;
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
