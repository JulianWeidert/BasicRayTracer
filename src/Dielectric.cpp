#include "BasicRayTracer/Dielectric.h"

namespace brt {


	lm::Vector3f Dielectric::refract(const lm::Vector3f& inDir, const lm::Vector3f& normal, float refractionRatio) const {
		auto cosTheta = std::min((-inDir) * normal, 1.0f);

		auto dirPerp = refractionRatio * (inDir + cosTheta * normal);
		auto dirPar = -std::sqrt(std::abs(1 - dirPerp.getLength() * dirPerp.getLength())) * normal;

		return dirPar + dirPerp;
	}

	lm::Vector3f Dielectric::reflect(const lm::Vector3f& v, const lm::Vector3f& n) const {
		return v - 2 * v * n * n;
	}

	float Dielectric::randomFloat() {
		return float(this->rng.next()) / std::numeric_limits<unsigned int>::max();
	}


	float  Dielectric::reflectance(float cos, float rIndex) const {
		// Use Schlick's approximation for reflectance.
		auto r0 = (1.0f - rIndex) / (1.0f + rIndex);
		r0 = r0 * r0;
		return r0 + (1.0f - r0) * std::powf((1.0f - cos), 5);
	}

	Dielectric::Dielectric(float ir) : ir(ir) {}

	std::optional<std::pair<Ray, lm::Vector3f>> Dielectric::scatter(const Ray& inRay, const HitResult& hitResult) {
		lm::Vector3f color = { 1,1,1 };

		float refractionRatio = hitResult.isFrontFace() ? (1.0f/this->ir) : (this->ir/1.0f); // 1.0f = air

		float cosTheta = std::min((-inRay.getDirection() * hitResult.getNormal()), 1.0f);
		float sinTheta = std::sqrt(1.0f - cosTheta * cosTheta);

		bool canRefract = refractionRatio * sinTheta <= 1.0f;

		if (!canRefract || this->reflectance(cosTheta, refractionRatio) > this->randomFloat()) {
			auto reflected = this->reflect(inRay.getDirection().getNormalized(), hitResult.getNormal());

			return std::make_pair(Ray(hitResult.getPosition(), reflected), color);
		}
		else {
			auto refracted = this->refract(inRay.getDirection().getNormalized(), hitResult.getNormal(), refractionRatio);

			return std::make_pair(Ray(hitResult.getPosition(), refracted), color);
		}

	}

}
