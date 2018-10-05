#pragma once

struct vector4
{
	enum class Plane { XY = 0, XZ = 1, XW = 2, YZ = 3, YW = 4, ZW = 5 };

	double x, y, z, w;
	vector4(const double, const double, const double, const double);
	vector4();

	void rotate(double, Plane);
};
