
#include "BasicRayTracer/Scene.h"


namespace brt {

	void Scene::addObject(std::unique_ptr<Primitive> object) {
		this->objects.push_back(std::move(object));
	}

	lm::Vector3f Scene::traceScene(const Ray& ray) const {
		// Just for testing

		HitResult closestHit = HitResult({ 0,0,-10000000 }, {} , { 0,0,0 });

		for (auto& obj : this->objects) {
			auto hit = obj->hit(ray);
			if (hit.has_value()) {
				auto val = hit.value();
				if ((closestHit.getPosition() - ray.getOrigin()).getLength() > (val.getPosition() - ray.getOrigin()).getLength()) closestHit = val;
			}

		}
		return closestHit.getColor();
	}

}
