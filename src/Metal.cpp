#include "BasicRayTracer/Metal.h"


namespace brt {


	lm::Vector3f Metal::reflect(const lm::Vector3f& v, const lm::Vector3f& n) const {
		return v - 2 * v * n * n;
	}


	Metal::Metal(lm::Vector3f color) : albedo(color) {}

	std::optional<std::pair<Ray, lm::Vector3f>> Metal::scatter(const Ray& inRay, const HitResult& hitResult) {
		auto reflected = this->reflect(inRay.getDirection(), hitResult.getNormal());

		if ((reflected * hitResult.getNormal()) < 0) return {};
		return std::make_pair(Ray(hitResult.getPosition(), reflected), this->albedo);
	}

}
