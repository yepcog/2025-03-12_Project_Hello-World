#include "odrGeometry.h"

float odrGeometry::odrPi{ 3.14 };
float odrGeometry::odrCircumference(float Diameter) {
	return Diameter * odrPi;
}

// - anonymous namespaces
float otherfPi{ 3.14 };

namespace {
	float annmsPi{ 3.1415 };
}
float annmsGetPi() { return annmsPi; }