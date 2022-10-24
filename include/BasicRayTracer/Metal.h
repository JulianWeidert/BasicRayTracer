#pragma once

#include <LeptonMath/Vector.h>

#include "Material.h"

namespace brt {


	class Metal : public Material {
	private:
		lm::Vector3f albedo;

		lm::Vector3f reflect(const lm::Vector3f& v, const lm::Vector3f& n) const;
	public:
		explicit Metal(lm::Vector3f color);

		std::optional<std::pair<Ray, lm::Vector3f>> scatter(const Ray& inRay, const HitResult& hitResult) override;
	};


}
