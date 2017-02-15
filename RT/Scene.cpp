#include "Scene.h"
#include "Color.h"
#include "BMPFILE.h"

#include <iostream>

Scene::Scene()
{
}

Scene::~Scene()
{
	//Clean the vector of objects
	for (int i = 0; i < objectVector.size(); i++)
	{
		delete objectVector[i];
		objectVector[i] = NULL;
	}
}

//Draw the scene onto an image by retracing (sending rays for each pixel of the image)
void Scene::RayTracingDraw(string name, int width,int height, int depth)
{
	//Raw data of the output image
	unsigned char* image = new unsigned char[width*height * 3];

	//Go through each pixel of the image
	for (int y= 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//Send a ray
			CRTColor color = OrthographicRayCast((float)x/(float)width, (float)y/(float)height);

			//Id of the cell, we jump [width*3] number of cells each row and 3 cells each column
			int id = x*3 + y*width*3;

			//Store the red, blue and green values as BGR
			image[id] = color.BlueToChar();
			image[id + 1] = color.GreenToChar();
			image[id + 2] = color.RedToChar();
		}
	}

	//Save the image as a BMP
	BMPFile::SaveBmp(name,image,width,height);

	//Clean the pointer
	delete image;
	image = NULL;
}

//Add an object to the scene
void Scene::AddObject(CRTObject* newObject)
{
	objectVector.push_back(newObject);
}

//Send an orthographic ray from (x,y) along the z axis and return the color of the pixel at this position
CRTColor Scene::OrthographicRayCast(float x, float y)
{

	//Create a ray from (x,y,0) pos and send it forward
	CRTRay ray = CRTRay(Vector3(x,y,0),Vector3(0,0,1));

	//Shortest collision with the ray
	float minDistance = RT_INFINITE;
	CRTObject* hitObject = NULL;
	CRTColor hitObjectColor = CRTColor();

	//For each objects in the scene
	for (int i = 0; i < objectVector.size(); i++)
	{
		//Find the intersection of the object and the ray
		float hitDistance = objectVector[i]->IntersectRay(ray);

		//If we hit a object closer to the origin, it's the new hit object
		if (hitDistance < minDistance)
		{
			minDistance = hitDistance;
			hitObject = objectVector[i];
		}
	}
	//If we hit something (when the id isn't -1 anymore)
	if (hitObject!=NULL)
	{
		//Get the color of the hit object
		hitObjectColor = hitObject->GetColor();
	}

	return hitObjectColor;
}
