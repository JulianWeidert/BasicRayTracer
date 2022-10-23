#pragma once

#include <LeptonMath/Vector.h>

#include "Ray.h"

namespace brt {

	class Camera {
	private:
		int viewportWidth;
		int viewportHeight;

		lm::Vector3f origin;
		float filmZ;
	public:
		explicit Camera(int width, int height, lm::Vector3f origin, float filmZ);
		explicit Camera(int width, int height);
			
		const Ray getRay(float x, float y) const;

		const int getViewportWidth() const;
		const int getViewportHeight() const;
	};


}
