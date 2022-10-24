#include "BasicRayTracer/HitResult.h"


namespace brt {

	HitResult::HitResult(lm::Vector3f position, lm::Vector3f normal, std::shared_ptr<Material> material) : position(position), normal(normal), material(material){}

	const lm::Vector3f& HitResult::getPosition() const {
		return this->position;
	}

	const lm::Vector3f& HitResult::getNormal() const {
		return this->normal;
	}

	std::shared_ptr<Material>& HitResult::getMaterial() {
		return this->material;
	}


}
