set(INCLUDE_DIR "${BasicRayTracer_SOURCE_DIR}/include/BasicRayTracer")

set(SRC 
	"${INCLUDE_DIR}/RayTracer.h"
	"RayTracer.cpp"
 )

add_library(BasicRayTracer ${SRC})

# include dir
target_include_directories(BasicRayTracer PUBLIC "${INCLUDE_DIR}/..")

target_link_libraries(BasicRayTracer PixelWindow)
target_link_libraries(BasicRayTracer LeptonMath)