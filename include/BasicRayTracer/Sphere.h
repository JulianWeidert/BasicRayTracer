#pragma once

#include <LeptonMath/Vector.h>

#include "Primitive.h"
#include "Material.h"

namespace brt {

	class Sphere : public Primitive {
	private:
		lm::Vector3f center;
		float radius;

		std::shared_ptr<Material> material;

	public:

		explicit Sphere(lm::Vector3f center, float radius, std::shared_ptr<Material> material);

		std::optional<HitResult> hit(const Ray& ray, float tMin, float tMax) const override;


		const lm::Vector3f& getCenter() const;
		const float getRadius() const;

	};

}
