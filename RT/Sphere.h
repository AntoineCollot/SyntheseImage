#ifndef __SPHERE_H
#define __SPHERE_H

#include "Object.h"
#include "Common.h"
#include <algorithm>

//Particular 3D object of shape sphere
class Sphere : public CRTObject
{
public:
	Sphere();
	Sphere(Vector3& center, float radius, CRTColor& color);
	~Sphere();

	float IntersectRay(CRTRay ray);

protected:
	Vector3 center;
	float radius;
};

#endif
