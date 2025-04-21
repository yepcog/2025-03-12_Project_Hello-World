#include "addnSquare.h"

// Option 1:
namespace addnGeometry {
	float addnSquare::addnArea() {
		return addnSideLength * addnSideLength;
	}
}

// Option 2:
//type of the member function goes before specification of what class member function belongs to
float addnGeometry::addnSquare::addnPerimeter() {
	return addnSideLength * 4;
}