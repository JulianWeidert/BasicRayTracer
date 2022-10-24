#pragma once

#include <optional>

#include "Ray.h"
#include "HitResult.h"

namespace brt {

	class Primitive {
	public:
		virtual std::optional<HitResult> hit(const Ray& ray, float tMin, float tMax) const = 0;
	};

}
