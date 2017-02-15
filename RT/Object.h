#ifndef __OBJECT_H
#define __OBJECT_H

#include "Vector3d.h"
#include "Ray.h"
#include "Color.h"

//3D object
class CRTObject
{
	public :
		CRTObject() { color = CRTColor(); }
		CRTObject(CRTColor color) { this->color = color; }

		virtual ~CRTObject() {}

		const CRTColor& GetColor() { return color; }
		virtual float IntersectRay(CRTRay ray) = 0;
		
	protected :
		CRTColor color;

} ;

#endif
