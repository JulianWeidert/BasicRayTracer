#include "BasicRayTracer/Sphere.h"

#include <iostream>

namespace brt {

	Sphere::Sphere(lm::Vector3f center, float radius, std::shared_ptr<Material> material) : center(center), radius(radius), material(material) {}

	std::optional<HitResult> Sphere::hit(const Ray& ray, float tMin, float tMax) const {
		/*auto oc = ray.getOrigin() - this->center; // origin - center
		auto dd = ray.getDirection() * ray.getDirection(); // dir * dir

		auto p = 2 * (ray.getDirection() * oc) / dd; // 2 * dir * (origin - center) / (dir * dir)
		auto q = (oc * oc - this->radius * this->radius) / dd; // ((origin - center) * (origin - center) - r*r) / (dir * dir)  

		auto discriminant = p * p / 4 - q;

		if (discriminant < 0) return {}; // Not hit return empty optional

		float t0 = (-p / 2 - std::sqrt(discriminant));
		float t1 = (-p / 2 + std::sqrt(discriminant));

		if (t0 > t1) std::swap(t0, t1);
		if (t0 < 0) t0 = t1; 

		auto t = t0;


		if (t >= tMax || t <= tMin) return {}; // This will never happen?

		auto pos = ray.getOrigin() + t * ray.getDirection(); // pos = origin + t * direction
		auto normal = (pos - this->center).getNormalized();

		return HitResult(pos, normal, ray.getDirection(), this->material);*/

		auto oc = ray.getOrigin() - this->center;
		auto a = ray.getDirection() * ray.getDirection();
		auto half_b = oc * ray.getDirection();
		auto c = oc * oc - radius * radius;

		auto discriminant = half_b * half_b - a * c;
		if (discriminant < 0) return {};
		auto sqrtd = sqrt(discriminant);

		// Find the nearest root that lies in the acceptable range.
		auto root = (-half_b - sqrtd) / a;
		if (root < tMin || tMax < root) {
			root = (-half_b + sqrtd) / a;
			if (root < tMin || tMax < root) return {};
		}
		
		auto t = root;

		auto pos = ray.getOrigin() + t * ray.getDirection(); 
		auto normal = (pos - this->center).getNormalized();

		return HitResult(pos, normal, ray.getDirection(), this->material); 


	}


	const lm::Vector3f& Sphere::getCenter() const {
		return this->center;
	}

	const float Sphere::getRadius() const {
		return this->radius;
	}

}
