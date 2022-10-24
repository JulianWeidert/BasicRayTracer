
#include <ctime>
#include "BasicRayTracer/Random.h"


namespace brt {

	RNG32::RNG32() : state(std::time(nullptr)) {};
	RNG32::RNG32(unsigned int seed) : state(seed) {};

	unsigned int RNG32::next() {
		auto x = this->state;
		x ^= x << 13;
		x ^= x >> 17;
		x ^= x << 5;
		this->state = x;
		return x;
	}

}
