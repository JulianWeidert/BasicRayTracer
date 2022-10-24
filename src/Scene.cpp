
#include "BasicRayTracer/Scene.h"


namespace brt {

	lm::Vector3f genPointUnitSphere() {
		lm::Vector3f p;
		do {
			float x = std::rand() / float(RAND_MAX/2) - 1;
			float y = std::rand() / float(RAND_MAX/2) - 1;
			float z = std::rand() / float(RAND_MAX/2) - 1;

			p = { x,y,z };
		} while (p.getLength() >= 1.0f);

		return p.getNormalized();
	}

	lm::Vector3f genPointUnitHemisphere(const lm::Vector3f& normal) {
		auto p = genPointUnitSphere();
		if (p * normal >= 0)
			return p;
		else
			return -p;
	}

	void Scene::addObject(std::unique_ptr<Primitive> object) {
		this->objects.push_back(std::move(object));
	}

	lm::Vector3f Scene::traceScene(const Ray& ray, float tMin, float tMax) const {
		// Just for testing

		HitResult closestHit = HitResult({ 0,0,-10000000 }, {} , { 0.5f,0.9f,1.0f });
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

			auto dir = genPointUnitHemisphere(closestHit.getNormal());
			
			// Recursive
			return 0.5f * this->traceScene(Ray(closestHit.getPosition(), dir), 0.0, tMax);
		}

		return closestHit.getColor();
	}

}
