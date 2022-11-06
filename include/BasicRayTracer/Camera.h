#pragma once

#include <LeptonMath/Vector.h>

#include "Ray.h"

namespace brt {

	class Camera {
	private:
		int viewportWidth;
		int viewportHeight;
		float fov;

		lm::Vector3f origin;
		lm::Vector3f lookAt;
		lm::Vector3f vUp;
	public:
		explicit Camera(int width, int height, float fov, lm::Vector3f lookFrom, lm::Vector3f lookAt, lm::Vector3f vUp);
		explicit Camera(int width, int height, float fov);
			
		const Ray getRay(float x, float y) const;

		const int getViewportWidth() const;
		const int getViewportHeight() const;
	};


}
