
#include <limits>

#include "BasicRayTracer/Scene.h"

#include <iostream>

namespace brt {

	lm::Vector3f Scene::genPointUnitSphere() {
		lm::Vector3f p;
		constexpr unsigned int max = std::numeric_limits<unsigned int>::max();
		do {
			float x = this->rng.next() / float(max/2) - 1;
			float y = this->rng.next() / float(max/2) - 1;
			float z = this->rng.next() / float(max/2) - 1;

			p = { x,y,z };
		} while (p.getLength() >= 1.0f);

		return p.getNormalized();
	}

	lm::Vector3f Scene::genPointUnitHemisphere(const lm::Vector3f& normal) {
		auto p = this->genPointUnitSphere();
		if (p * normal >= 0)
			return p;
		else
			return -p;
	}

	void Scene::addObject(std::unique_ptr<Primitive> object) {
		this->objects.push_back(std::move(object));
	}

	lm::Vector3f Scene::traceScene(const Ray& ray, float tMin, float tMax) {
		// Just for testing

		HitResult closestHit = HitResult({ 0,0,-10000000 }, {} , { 205.0f/255,240.0f/255,1.0f });
		bool hitDetected = false;

		for (auto& obj : this->objects) {
			auto hit = obj->hit(ray, tMin, tMax);
			if (hit.has_value()) {
				const auto& val = hit.value();
				hitDetected = true;
				if ((closestHit.getPosition() - ray.getOrigin()).getLength() > (val.getPosition() - ray.getOrigin()).getLength()) closestHit = val;
			}
		}

		if (hitDetected) {

			auto dir = this->genPointUnitHemisphere(closestHit.getNormal());
			
			// Recursive
			return 0.5f * this->traceScene(Ray(closestHit.getPosition(), dir), 0.0, tMax);
		}

		return closestHit.getColor();
	}

}
