#include "BasicRayTracer/HitResult.h"


namespace brt {

	HitResult::HitResult(lm::Vector3f position, lm::Vector3f normal, lm::Vector3f rayDir, std::shared_ptr<Material> material) : position(position), material(material){
		this->frontFace = (rayDir * normal) < 0;
		this->normal = this->frontFace ? normal : -normal;
	}

	const lm::Vector3f& HitResult::getPosition() const {
		return this->position;
	}

	const lm::Vector3f& HitResult::getNormal() const {
		return this->normal;
	}

	std::shared_ptr<Material>& HitResult::getMaterial() {
		return this->material;
	}

	bool HitResult::isFrontFace() const {
		return this->frontFace;
	}

}
