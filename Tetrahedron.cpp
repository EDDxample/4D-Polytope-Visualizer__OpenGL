#include "GL\freeglut.h"
#include "Tetrahedron.h"

//---------------------------------
#define xyz(v) v.x, v.y, v.z
#define TRIANGLE(_0,_1,_2)\
glPushMatrix();\
	glBegin(GL_TRIANGLES);\
		glVertex3f(xyz(_0));\
		glVertex3f(xyz(_1));\
		glVertex3f(xyz(_2));\
	glEnd();\
glPopMatrix();
#define LINE(_0,_1)\
glPushMatrix();\
	glBegin(GL_LINES);\
		glVertex3f(xyz(_0));\
		glVertex3f(xyz(_1));\
	glEnd();\
glPopMatrix();
//---------------------------------

Tetrahedron::Tetrahedron(vector4 &_0, vector4 &_1, vector4 &_2, vector4 &_3)
{
	verts[0] = _0; verts[1] = _1; verts[2] = _2; verts[3] = _3;
}
Tetrahedron::Tetrahedron(vector4 *_0, vector4 *_1, vector4 *_2, vector4 *_3)
{
	verts[0] = *_0; verts[1] = *_1; verts[2] = *_2; verts[3] = *_3;
}

void Tetrahedron::rotate(const double d, vector4::Plane p)
{
	for (int i = 0; i < 4; ++i) verts[i].rotate(d, p);
}

void Tetrahedron::render(const double w, const int color) const
{
	const int pairs[12] = { 0,1, 0,2, 0,3, 1,2, 1,3, 2,3 };
	vector4 A, B, list[4];
	int inside[4] = { 0,0,0,0 }, count = 0;

	for (int i = 0; i < 12; i += 2)
	{
		A = verts[pairs[i]];
		B = verts[pairs[i + 1]];

		/* RENDER WHITE MESH */
		//glColor3f(1, 1, 1); LINE(A, B)

		// No intersection
		if ((A.w > w && B.w > w) || (A.w < w && B.w < w)) continue;

		//Fully inside
		if (A.w == w && B.w == w)
		{
			if (count < 4 && !inside[  i  ]) { list[count] = A; count++; inside[  i  ] = 1; }
			if (count < 4 && !inside[i + 1]) { list[count] = B; count++; inside[i + 1] = 1; }
			continue;
		}

		// Intersection
		if (count < 4)
		{
			double t = (w - A.w) / (B.w - A.w);
			list[count] = vector4
			(
				A.x + (B.x - A.x)*t,
				A.y + (B.y - A.y)*t,
				A.z + (B.z - A.z)*t,
			w);

			count++;
			continue;
		}
	}

	glColor3ubv((BYTE*)(&color));

	if (count == 3)
	{
		vector4 _a = list[0], _b = list[1], _c = list[2];
		TRIANGLE(_a, _b, _c)

	}
	if (count == 4)
	{
		const int order[] = { 0,1,2, 3,0,1, 3,1,2, 3,2,0 };
		for (int i = 0; i < 4; ++i)
		{
			vector4 _a = list[order[i * 3]];
			vector4 _b = list[order[i * 3 + 1]];
			vector4 _c = list[order[i * 3 + 2]];
			TRIANGLE(_a, _b, _c)
		}
		//glColor3f(0, 0, 0); LINE(list[0], list[1]) LINE(list[0], list[2]) LINE(list[0], list[3]) LINE(list[1], list[2]) LINE(list[1], list[3]) LINE(list[2], list[3])
	}
}

#undef TRIANGLE
#undef xyz