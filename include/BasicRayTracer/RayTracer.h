#pragma once

#include <memory>
#include <limits>

#include <PixelWindow/PixelWindow.h>

#include "Scene.h"
#include "Camera.h"


namespace brt {

	class RayTracer {
	private:
		std::unique_ptr<int[]> frameBuffer;
		int width;
		int height;


	public:

		RayTracer(int width, int height);


		void renderScene(Scene& scene, const Camera& camera, int samplesPerPixel);

		void showOnWindow(pw::PixelWindow& window) const; 

	};


}
