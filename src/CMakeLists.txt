set(INCLUDE_DIR "${BasicRayTracer_SOURCE_DIR}/include/BasicRayTracer")

set(SRC 
	"${INCLUDE_DIR}/RayTracer.h"
	"RayTracer.cpp"
 )

add_library(BasicRayTracer ${SRC})

# include dir
target_include_directories(BasicRayTracer PUBLIC "${INCLUDE_DIR}/..")
