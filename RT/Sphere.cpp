#include "Sphere.h"
#include <iostream>


Sphere::Sphere() : CRTObject()
{
	radius = 1;
	center = Vector3();
}

Sphere::Sphere(Vector3& center,float radius, CRTColor& color) : CRTObject(color)
{
	this->center = center;
	this->radius = radius;
}

Sphere::~Sphere()
{

}

//Check if the ray collide with the sphere, and return the distance of the intersection
float Sphere::IntersectRay(CRTRay ray)
{
	// The sphere equation: (P-C)² - r² = 0   - With P a point on the sphere, C the center and r the radius
	// The ray equation: P = O + td - With P a point on the line, O the origin, t the linear coordinate, d the direction vector
	// Combining both equations: (O + td - C)² - r² = 0 
	// That is: d²t² + 2(O-C)dt + (O-C)²-r²
	// i.e. an equation of the form Ax² + Bx + C = 0

	// Calculate the solutions of the equation 
	double A = ray.getDirection().GetSquareLength();
	double B = 2 * (ray.getOrigin() - center).Dot(ray.getDirection());
	double C = (ray.getOrigin() - center).GetSquareLength() - radius*radius;

	double delta = B*B - 4 * A*C;

	// If the equation has no solutions, we return the distance of the collision as infinite
	if (delta < 0)
		return RT_INFINITE;

	double sol1 = (-B + sqrt(delta)) / (2 * A);
	double sol2 = (-B - sqrt(delta)) / (2 * A);

	//Otherwise, return the smallest of the solutions
	return std::min(sol1, sol2);
}