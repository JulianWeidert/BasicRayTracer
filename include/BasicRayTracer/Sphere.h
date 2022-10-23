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

		bool hit(const Ray& ray) const;


		const lm::Vector3f& getCenter() const;
		const float getRadius() const;

	};

}
