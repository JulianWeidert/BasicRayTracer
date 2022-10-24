#pragma once

#include <LeptonMath/Vector.h>


#include "Material.h"
#include "Random.h"

namespace brt {

	class Lambertian : public Material {
	private:
		lm::Vector3f albedo;
		RNG32 rng;

		lm::Vector3f genPointUnitSphere();
		lm::Vector3f genPointUnitHemisphere(const lm::Vector3f& normal);

	public:
		explicit Lambertian(lm::Vector3f color);
		
		std::optional<std::pair<Ray, lm::Vector3f>> scatter(const Ray& inRay, const HitResult& hitResult) override;
	};


}