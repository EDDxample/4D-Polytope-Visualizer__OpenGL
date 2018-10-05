#include "Cell_5.h"
#include "GL/freeglut.h"

Cell_5::Cell_5()
	:
	model
	{
		vector4(0.31622, 0.40824, 0.57735, 1),
		vector4(0.31622, 0.40824, 0.57735,-1),
		vector4(0.31622, 0.40824,-1.15470, 0),
		vector4(0.31622,-1.22474, 0, 0),
		vector4(-1.26491, 0, 0, 0)
	}
{
}

#define TETRA(_0, _1, _2, _3) Tetrahedron(renderModel[_0],renderModel[_1],renderModel[_2],renderModel[_3])

static double deg = 0;

void Cell_5::render(double w)
{
	vector4 renderModel[5];

	for (int i = 0; i < 5; ++i)
	{
		renderModel[i] = model[i];
		renderModel[i].rotate(deg, (vector4::Plane)0);
		renderModel[i].rotate(deg, (vector4::Plane)1);
		renderModel[i].rotate(deg, (vector4::Plane)2);
		renderModel[i].rotate(deg, (vector4::Plane)3);
		renderModel[i].rotate(deg, (vector4::Plane)4);
		renderModel[i].rotate(deg, (vector4::Plane)5);
	}

	deg += 1;

	const Tetrahedron mesh[5] = { TETRA(0,1,2,3), TETRA(0,1,2,4), TETRA(0,1,3,4), TETRA(0,2,3,4), TETRA(1,2,3,4) };

	                       //  RED      GREEN     BLUE     YELLOW   MAGENTA
	const int colors[8] = { 0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0xFF00FF };

	glPushMatrix();
	glScalef(6, 6, 6);
	for (int i = 0; i < 5; ++i)  mesh[i].render(w, colors[i]);
	glPopMatrix();
}
