#pragma once

#include <memory>

#include <PixelWindow/PixelWindow.h>

#include "Scene.h"


namespace brt {

	class RayTracer {
	private:
		std::unique_ptr<int[]> frameBuffer;
		int width;
		int height;


	public:

		RayTracer(int width, int height);


		void renderScene(const Scene& scene);

		void showOnWindow(pw::PixelWindow& window) const; 

	};


}
