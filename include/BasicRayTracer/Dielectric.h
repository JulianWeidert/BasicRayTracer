#pragma once

#include <LeptonMath/Vector.h>

#include "Material.h"
#include "Random.h"

namespace brt {

	class Dielectric : public Material {
	private:
		float ir; // Index of refraction
		RNG32 rng;

		lm::Vector3f refract(const lm::Vector3f& inDir, const lm::Vector3f& normal, float refractionRatio) const;
		lm::Vector3f reflect(const lm::Vector3f& v, const lm::Vector3f& n) const;
		float randomFloat();
		float reflectance(float cos, float rIndex) const;
	public:
		explicit Dielectric(float ir);

		std::optional<std::pair<Ray, lm::Vector3f>> scatter(const Ray& inRay, const HitResult& hitResult) override;
	};


}
