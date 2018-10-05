#pragma once
#include "vector4.h"

struct Tetrahedron
{
	vector4 verts[4];
	
	Tetrahedron(vector4&, vector4&, vector4&, vector4&);
	Tetrahedron(vector4*, vector4*, vector4*, vector4*);

	void rotate(const double, vector4::Plane);
	void render(const double, const int) const;
};