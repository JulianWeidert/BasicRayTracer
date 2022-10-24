#pragma once

#include <optional>
#include <utility>

#include <LeptonMath/Vector.h>

#include "Ray.h"
#include "HitResult.h"

namespace brt {

	class Material {
	public:
		virtual std::optional<std::pair<Ray, lm::Vector3f>> scatter(const Ray& inRay, const HitResult& hitResult) = 0;
	};

}
