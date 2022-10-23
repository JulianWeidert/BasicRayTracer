#pragma once

#include "Ray.h"

namespace brt {

	class Primitive {
	public:
		virtual bool hit(const Ray& ray) const = 0;
	};

}
