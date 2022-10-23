#include "BasicRayTracer/HitResult.h"


namespace brt {

	HitResult::HitResult(lm::Vector3f position, lm::Vector3f normal, lm::Vector3f color) : position(position), normal(normal), color(color){}

	const lm::Vector3f& HitResult::getPosition() const {
		return this->position;
	}

	const lm::Vector3f& HitResult::getNormal() const {
		return this->normal;
	}

	const lm::Vector3f& HitResult::getColor() const {
		return this->color;
	}


}
