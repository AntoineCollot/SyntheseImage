#ifndef __RAY_H
#define __RAY_H

#include "Vector3d.h"

//Ray that can be send in the scene and collide with objects, used to find the color of a pixel
class CRTRay
{
	public :
		CRTRay();
		CRTRay(Vector3 origin, Vector3 direction);
		~CRTRay();

		Vector3 getDirection() { return direction; }
		Vector3 getOrigin() { return origin; }
		
	protected :
		Vector3 direction;
		Vector3 origin;

} ;

#endif
