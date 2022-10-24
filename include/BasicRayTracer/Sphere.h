#pragma once

#include <LeptonMath/Vector.h>

#include "Primitive.h"

namespace brt {

	class Sphere : public Primitive {
	private:
		lm::Vector3f center;
		float radius;
	public:

		explicit Sphere(lm::Vector3f center, float radius);

		std::optional<HitResult> hit(const Ray& ray, float tMin, float tMax) const;


		const lm::Vector3f& getCenter() const;
		const float getRadius() const;

	};

}
