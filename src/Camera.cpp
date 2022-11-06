#include "BasicRayTracer/Camera.h"


namespace brt {

	Camera::Camera(int width, int height, float fov, lm::Vector3f lookFrom, lm::Vector3f lookAt, lm::Vector3f vUp) : 
		viewportWidth(width), viewportHeight(height), fov(fov), origin(lookFrom), lookAt(lookAt), vUp(vUp) {}

	Camera::Camera(int width, int height, float fov) : 
		Camera(width, height, fov, { 0, 0, 0 }, { 0,0,-1 }, { 0,1,0 }) {}

	const Ray Camera::getRay(float x, float y) const {

		static auto aspectRatio = float(this->viewportWidth) / float(this->viewportHeight);
		static auto rad = this->fov / 180 * 3.141592f;
		static auto h = std::tanf(rad/2);
		static auto vpHeight = 2.0f * h;
		static auto vpWidth = aspectRatio * vpHeight;
		
		static auto w = (this->origin - this->lookAt).getNormalized();
		static auto u = (lm::cross(this->vUp, w)).getNormalized();
		static auto v = lm::cross(w, u).getNormalized();

		static auto horizontal = vpWidth * u;
		static auto vertical = vpHeight * v;

		float s = x / float(this->viewportWidth);
		float t = y / float(this->viewportHeight);

		auto filmX = s * horizontal - 0.5f * horizontal;
		auto filmY = -(t * vertical - 0.5f * vertical);

		auto filmPos = origin + filmX + filmY - w;

		return Ray(origin, filmPos - origin);
	}

	const int Camera::getViewportWidth() const {
		return this->viewportWidth;
	}

	const int Camera::getViewportHeight() const {
		return this->viewportHeight;
	}

}
