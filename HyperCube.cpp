#include "HyperCube.h"



HyperCube::HyperCube(const double s)
	:
	model {
		vector4(-s, -s, -s, -s),
		vector4(+s, -s, -s, -s),
		vector4(-s, +s, -s, -s),
		vector4(+s, +s, -s, -s),
		vector4(-s, -s, +s, -s),
		vector4(+s, -s, +s, -s),
		vector4(-s, +s, +s, -s),
		vector4(+s, +s, +s, -s),

		vector4(-s, -s, -s, +s),
		vector4(+s, -s, -s, +s),
		vector4(-s, +s, -s, +s),
		vector4(+s, +s, -s, +s),
		vector4(-s, -s, +s, +s),
		vector4(+s, -s, +s, +s),
		vector4(-s, +s, +s, +s),
		vector4(+s, +s, +s, +s)
	}
{
}

#define _cube2tetrahedra(a0,a1,a2,a3,a4,a5,a6,a7)\
Tetrahedron(renderModel[a1],renderModel[a2],renderModel[a4],renderModel[a7]),\
Tetrahedron(renderModel[a0],renderModel[a1],renderModel[a2],renderModel[a4]),\
Tetrahedron(renderModel[a2],renderModel[a4],renderModel[a6],renderModel[a7]),\
Tetrahedron(renderModel[a1],renderModel[a2],renderModel[a3],renderModel[a7]),\
Tetrahedron(renderModel[a1],renderModel[a4],renderModel[a5],renderModel[a7])


static double deg = 0;

void HyperCube::render(double w)
{
	vector4 renderModel[16];

	for (int i = 0; i < 16; ++i)
	{
		renderModel[i] = model[i];
		//renderModel[i].rotate(deg, (vector4::Plane)0);
		renderModel[i].rotate(deg, (vector4::Plane)1);
		renderModel[i].rotate(deg, (vector4::Plane)2);
		renderModel[i].rotate(deg, (vector4::Plane)3);
		renderModel[i].rotate(deg, (vector4::Plane)4);
		renderModel[i].rotate(deg, (vector4::Plane)5);
	}

	deg += 1;

	const Tetrahedron mesh[8*5] =
	{
		_cube2tetrahedra(0, 1, 2, 3, 4, 5, 6, 7),
		_cube2tetrahedra(0, 1, 2, 3, 8, 9,10,11),
		_cube2tetrahedra(4, 5, 6, 7,12,13,14,15),
		_cube2tetrahedra(8, 9,10,11,12,13,14,15),
		_cube2tetrahedra(0, 1, 4, 5, 8, 9,12,13),
		_cube2tetrahedra(0, 2, 4, 6, 8,10,12,14),
		_cube2tetrahedra(1, 3, 5, 7, 9,11,13,15),
		_cube2tetrahedra(2, 3, 6, 7,10,11,14,15)
	};
			              //  RED      GREEN     YELLOW     BLUE    MAGENTA     CYAN     ORANGE     GRAY
	const int colors[8] = { 0xFF0000, 0x00FF00, 0xFFFF00, 0x0000FF, 0xFF00FF, 0x00FFFF, 0xFF8880, 0x808080 };

	for (int i = 0; i < 8; ++i) for (int j = 0; j < 5; ++j) mesh[i * 5 + j].render(w, colors[i]);
	

}

#undef _cube2tetrahedra

