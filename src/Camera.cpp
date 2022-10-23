#include "BasicRayTracer/Camera.h"


namespace brt {

	Camera::Camera(int width, int height, lm::Vector3f origin, float filmZ) : viewportWidth(width), viewportHeight(height), origin(origin), filmZ(filmZ) {}

	Camera::Camera(int width, int height) : viewportWidth(width), viewportHeight(height), origin({ 0,0,1 }), filmZ(0) {}

	const Ray Camera::getRay(float x, float y) const {
		// TODO
		static float aspectRatio = float(this->viewportWidth) / float(this->viewportHeight);

		float filmX = (2.0f * x / float(this->viewportWidth) - 1.0)/ aspectRatio;
		float filmY = -(2.0f * y / float(this->viewportHeight) - 1.0);

		lm::Vector3f filmPos = { filmX, filmY, this->filmZ };
		lm::Vector3f direction = filmPos - this->origin;

		return Ray(filmPos, direction);
	}

	const int Camera::getViewportWidth() const {
		return this->viewportWidth;
	}

	const int Camera::getViewportHeight() const {
		return this->viewportHeight;
	}

}
