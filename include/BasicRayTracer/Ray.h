#pragma once

#include <LeptonMath/Vector.h>

namespace brt {

	class Ray {
	private:
		lm::Vector3f origin;
		lm::Vector3f dir;
	public:
		
		explicit Ray(lm::Vector3f origin, lm::Vector3f dir);

		const lm::Vector3f& getDirection() const;
		const lm::Vector3f& getOrigin() const;

	};

}
