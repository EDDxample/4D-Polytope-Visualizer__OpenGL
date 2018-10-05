#pragma once
#include "Tetrahedron.h"

//  1/v10 =  0.31622
//  1/v6  =  0.40824
//  1/v3  =  0.57735
// -2/v3  = -1.15470
// -v3/2  = -1.22474
// -2v2/5 = -1.26491

struct Cell_5
{
	vector4 model[5];
	Cell_5();
	void render(double);
};