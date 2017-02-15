#include <iostream>
#include "RT/Scene.h"

using namespace std;

int main()
{
	cout << "Start \n";

	//Create the scene
	Scene scene = Scene();

	cout << "Created Scene \n";

	//Create 3 spheres
	Sphere* sphere_Red = new Sphere(Vector3(0.35f, 0.25f, 0.8f), 0.17f, CRTColor::Red());
	Sphere* sphere_Green = new Sphere(Vector3(0.65f, 0.25f, 0.9f), 0.17f, CRTColor::Green());
	Sphere* sphere_Blue = new Sphere(Vector3(0.5f, 0.55f, 1), 0.17f, CRTColor::Blue());

	cout << "Created Spheres \n";

	//Add 3 spheres to the scene
	scene.AddObject(sphere_Red);
	scene.AddObject(sphere_Green);
	scene.AddObject(sphere_Blue);

	cout << "Added Spheres to scene \n";

	//Draw the image
	scene.RayTracingDraw("SyntheseImage_1.bmp", 360, 240, 0);

	//Delete the spheres
	delete sphere_Red, sphere_Green, sphere_Blue;

	cout << "End \n";


	cin.get();

	return 0;
}
