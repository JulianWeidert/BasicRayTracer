#include "BasicRayTracer/Lambertian.h"

namespace brt {

	lm::Vector3f Lambertian::genPointUnitSphere() {
		lm::Vector3f p;
		constexpr unsigned int max = std::numeric_limits<unsigned int>::max();
		do {
			float x = this->rng.next() / float(max / 2) - 1;
			float y = this->rng.next() / float(max / 2) - 1;
			float z = this->rng.next() / float(max / 2) - 1;

			p = { x,y,z };
		} while (p.getLength() >= 1.0f);

		return p.getNormalized();
	}

	lm::Vector3f Lambertian::genPointUnitHemisphere(const lm::Vector3f& normal) {
		auto p = this->genPointUnitSphere();
		if (p * normal >= 0)
			return p;
		else
			return -p;
	}


	Lambertian::Lambertian(lm::Vector3f color) : albedo(color) {}

	std::optional<std::pair<Ray, lm::Vector3f>> Lambertian::scatter(const Ray& inRay, const HitResult& hitResult)  {
		auto dir = this->genPointUnitHemisphere(hitResult.getNormal());
		return std::make_pair(Ray(hitResult.getPosition(), dir), this->albedo);
	}


}
