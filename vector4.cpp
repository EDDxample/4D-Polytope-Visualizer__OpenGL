#include "vector4.h"
#include <math.h>

const double fix(const double d) { return (int)(d * 100000) / 100000.0; }

vector4::vector4(const double _0, const double _1, const double _2, const double _3)
{
	x = fix(_0), y = fix(_1), z = fix(_2), w = fix(_3);
}
vector4::vector4() { vector4(0, 0, 0, 0); }

void vector4::rotate(double d, Plane p)
{
	d += d > 360 ? -360 : d < 0 ? -d : 0;
	// to Radians
	double deg = d * 3.14159265 / 180.0;
	double s = sin(deg);
	double c = cos(deg);

	double a0, a1;

	switch (p)
	{
	case Plane::XY: a0 = c * x + s * y; a1 = -s * x + c * y; x = a0; y = a1; return;
	case Plane::YZ: a0 = c * y + s * z; a1 = -s * y + c * z; y = a0; z = a1; return;
	case Plane::ZW: a0 = c * z + s * w; a1 = -s * z + c * w; z = a0; w = a1; return;
	case Plane::XW: a0 = c * x + s * w; a1 = -s * x + c * w; x = a0; w = a1; return;
	case Plane::XZ: a0 = c * x - s * z; a1 =  s * x + c * z; x = a0; z = a1; return;
	case Plane::YW: a0 = c * y - s * w; a1 =  s * y + c * w; y = a0; w = a1; return;
	}
}



