#pragma once

namespace brt {

	class RNG32 {
	private:
		unsigned int state; 
	public:

		RNG32();
		RNG32(unsigned int seed);

		unsigned int next();

	};


}
