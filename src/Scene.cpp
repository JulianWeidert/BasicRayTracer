
#include <limits>

#include "BasicRayTracer/Scene.h"

#include "BasicRayTracer/Lambertian.h"

#include <iostream>

namespace brt {


	void Scene::addObject(std::unique_ptr<Primitive> object) {
		this->objects.push_back(std::move(object));
	}

	lm::Vector3f Scene::traceScene(const Ray& ray, float tMin, float tMax, int depth) {
		// Just for testing

		HitResult closestHit = HitResult({ 0,0,-10000000 }, {}, {}, nullptr);
		bool hitDetected = false;

		for (auto& obj : this->objects) {
			auto hit = obj->hit(ray, tMin, tMax);
			if (hit.has_value()) {
				const auto& val = hit.value();
				hitDetected = true;
				if ((closestHit.getPosition() - ray.getOrigin()).getLength() > (val.getPosition() - ray.getOrigin()).getLength()) closestHit = val;
			}
		}

		if (depth == 0) return { 0,0,0 };

		if (hitDetected) {

			auto mat = closestHit.getMaterial();
			if (mat != nullptr) {
				auto scatter = mat->scatter(ray, closestHit);
				if (scatter.has_value()) {
					auto res = this->traceScene(scatter.value().first, 0.0001, tMax, depth - 1);
					auto color = scatter.value().second;
					return lm::Vector3f({ res.getX() * color.getX(), res.getY() * color.getY(), res.getZ() * color.getZ() });
				}
			}
			
		}

		return { 210.0f / 255, 240.0f / 255, 1.0f };
	}

}
