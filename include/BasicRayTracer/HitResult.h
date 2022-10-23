#pragma once

#include <LeptonMath/Vector.h>

namespace brt {

	class HitResult {
	private:
		lm::Vector3f position;
		lm::Vector3f normal;
		lm::Vector3f color;
	public:
		HitResult() = default;
		explicit HitResult(lm::Vector3f position, lm::Vector3f normal, lm::Vector3f color);

		const lm::Vector3f& getPosition() const;
		const lm::Vector3f& getNormal() const;
		const lm::Vector3f& getColor() const;
	};


}
