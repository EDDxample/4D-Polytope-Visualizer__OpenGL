#pragma once
#include "Tetrahedron.h"

struct HyperCube
{
	vector4 model[16];

	HyperCube(const double);

	void render(double);
};