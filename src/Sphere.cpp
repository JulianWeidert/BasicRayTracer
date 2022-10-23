#include "BasicRayTracer/Sphere.h"


namespace brt {

	Sphere::Sphere(lm::Vector3f center, float radius) : center(center), radius(radius) {}

	bool Sphere::hit(const Ray& ray) const {
		auto oc = ray.getOrigin() - this->center; // origin - center
		auto dd = ray.getDirection() * ray.getDirection(); // dir * dir

		auto p = 2 * (ray.getDirection() * oc) / dd; // 2 * dir * (origin - center) / (dir * dir)
		auto q = (oc * oc - this->radius * this->radius) / dd; // ((origin - center) * (origin - center) - r*r) / (dir * dir)  

		auto discriminant = p * p / 4 - q;

		return discriminant >= 0;
	}


	const lm::Vector3f& Sphere::getCenter() const {
		return this->center;
	}

	const float Sphere::getRadius() const {
		return this->radius;
	}

}
