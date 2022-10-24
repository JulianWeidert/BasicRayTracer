#pragma once

#include <memory>
#include <vector>

#include "Primitive.h"

namespace brt {

	class Scene {
	private:
		std::vector<std::unique_ptr<Primitive>> objects;

	public:

		void addObject(std::unique_ptr<Primitive> object);
		lm::Vector3f traceScene(const Ray& ray, float tMin, float tMax) const;

	};

}
