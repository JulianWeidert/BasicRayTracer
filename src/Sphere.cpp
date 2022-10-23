#include "BasicRayTracer/Sphere.h"

#include <iostream>

namespace brt {

	Sphere::Sphere(lm::Vector3f center, float radius) : center(center), radius(radius) {}

	std::optional<HitResult> Sphere::hit(const Ray& ray) const {
		auto oc = ray.getOrigin() - this->center; // origin - center
		auto dd = ray.getDirection() * ray.getDirection(); // dir * dir

		auto p = 2 * (ray.getDirection() * oc) / dd; // 2 * dir * (origin - center) / (dir * dir)
		auto q = (oc * oc - this->radius * this->radius) / dd; // ((origin - center) * (origin - center) - r*r) / (dir * dir)  

		auto discriminant = p * p / 4 - q;

		if (discriminant < 0) return {}; // Not hit return empty optional

		auto pos = ray.getOrigin() + (-p / 2 - std::sqrt(discriminant)) * ray.getDirection(); // pos = origin + t * direction
		auto normal = (pos - this->center).getNormalized();
		auto color = 0.5f * (normal + lm::Vector3f({ 1,1,1 }));

		return HitResult(pos, normal, color);
	}


	const lm::Vector3f& Sphere::getCenter() const {
		return this->center;
	}

	const float Sphere::getRadius() const {
		return this->radius;
	}

}
