
#include "BasicRayTracer/Scene.h"


namespace brt {

	void Scene::addObject(std::unique_ptr<Primitive> object) {
		this->objects.push_back(std::move(object));
	}

	int Scene::traceScene(const Ray& ray) const {
		// Just for testing
		for (auto& obj : this->objects) {
			bool hit = obj->hit(ray);
			
			if (hit) return 0xFFFFFFFF; // White if object intersected
		}
		return 0; // Black if no object intersected
	}

}
