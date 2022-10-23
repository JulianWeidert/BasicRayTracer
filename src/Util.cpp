#include "BasicRayTracer/Util.h"

namespace brt {

	int convertColor(const lm::Vector3f& color) {
		int r = int(color.getX() * 255) & 0XFF;
		int g = int(color.getY() * 255) & 0xFF;
		int b = int(color.getZ() * 255) & 0xFF;
		int a = 255;

		return a << 24 | b << 16 | g << 8 | r;
	}

}
