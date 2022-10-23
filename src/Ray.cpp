#include "BasicRayTracer/Ray.h"

namespace brt {

	Ray::Ray(lm::Vector3f origin, lm::Vector3f dir) : origin(origin), dir(dir) {}

	const lm::Vector3f& Ray::getDirection() const {
		return this->dir;
	}

	const lm::Vector3f& Ray::getOrigin() const {
		return this->origin;
	}

}
