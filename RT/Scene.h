#ifndef __SCENE_H
#define __SCENE_H

#include <string>
#include <vector>
#include "Color.h"
#include "Object.h"
#include "Ray.h"
#include "Common.h"
#include "Sphere.h"

using namespace std;

//Scene that countains 3D objects and can be rendered
class Scene
{
	public :
		Scene();
		~Scene();
		void RayTracingDraw(string name,int width,int height,int depth);
		CRTColor OrthographicRayCast(float x, float y);
		void AddObject(CRTObject* newObject);

	protected :
		vector<CRTObject*> objectVector;
};

#endif
