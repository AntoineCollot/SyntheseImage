#ifndef __VECTOR3D_H
#define __VECTOR3D_H

#include <math.h>

class Vector3
{
	public:

		Vector3 (float fX=0.0f,float fY=0.0f,float fZ=0.0f)
			:	x	(fX),
				y	(fY),
				z	(fZ)
		{
		}

		Vector3 (const Vector3 &vVector)
			:	x	(vVector.x),
				y	(vVector.y),
				z	(vVector.z)
		{
		}

		// Operators
		
		Vector3 operator = (const Vector3 &v)
		{
			x=v.x ;
			y=v.y ;
			z=v.z ;
			return *this ;
		}
		
		Vector3 operator + (const Vector3 &v) const
		{
			return Vector3 (x+v.x,y+v.y,z+v.z) ;
		}
		
		Vector3 operator - (const Vector3 &v) const
		{
			return Vector3 (x-v.x,y-v.y,z-v.z) ;
		}

		Vector3 operator - ()                  const
		{
			return Vector3 (-x,-y,-z) ;
		}
		
		Vector3 operator * (float k)           const
		{
			return Vector3 (k*x,k*y,k*z) ;
		}
		
		Vector3 operator / (float k)           const
		{
			return Vector3 (x/k,y/k,z/k) ;
		}
		
		float Dot (const Vector3 &v) const
		{
			return ( (x*v.x) + (y*v.y) + (z*v.z) ) ;
		}
		
		Vector3 Cross (const Vector3 &v) const
		{
			return Vector3 (y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x) ;
		}
		
		Vector3 & operator += (const Vector3 & v)
		{
			x+=v.x;
			y+=v.y;
			z+=v.z;
			return *this;
		}

		Vector3 & operator /= (float fFactor)
		{
			x/=fFactor ;
			y/=fFactor ;
			z/=fFactor ;
			return *this;
		}

		float GetLength ()
		{
			return ( (float) sqrt (x*x+y*y+z*z) ) ;
		}

		float GetSquareLength()
		{
			return ((float)x*x + y*y + z*z);
		}
		
		void Normalize ()
		{
			float fLength=GetLength ();
			
			if (fLength>0)
			{
				x/=fLength;
				y/=fLength;
				z/=fLength;
			}
		}

		Vector3 Unit ()
		{
			Vector3 v(*this) ;
			v.Normalize () ;
			return v ;
		}

		struct
		{
			float x , y , z ;
		};
};

#endif
