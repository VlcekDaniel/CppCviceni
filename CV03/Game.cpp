#include "Game.h"
#include "StaticObject.h"
#include "MovableObject.h"
#include "Object.h"
#include <iostream>
using namespace std;

Game::Game() {
	objects = new Object*[10];
	counter = 0;
	maxObjects = 10;
}

Game::~Game() {
	delete[] objects;
}

void Game::InsertObject(Object* o) {
	objects[counter] = o;
	counter++;
}
int* Game::FindIdStaticObjects(double xmin, double xmax, double ymin, double ymax) {	

	int ObjectsInArray = 0;

	for (size_t i = 0; i < counter; i++)
	{
		double x = objects[i]->GetX();
		double y = objects[i]->GetY();
		if (dynamic_cast<StaticObject*>(objects[i])!=nullptr && x >= xmin && x<=xmax && y>=ymin && y <= ymax) {
			ObjectsInArray++;
		}		 
	}

	int* ids = new int[ObjectsInArray];
	int j = 0;

	for (size_t i = 0; i < counter; i++)
	{
		double x = objects[i]->GetX();
		double y = objects[i]->GetY();
		if (dynamic_cast<StaticObject*>(objects[i]) != nullptr && x >= xmin && x <= xmax && y >= ymin && y <= ymax) {
			ids[j] = objects[i]->GetId();
			j++;
		}
	}

	return ids;
}
MovableObject** Game::FindMovableObjectInArea(double x, double y, double r) {
	int ObjectsInArray = 0;

	for (size_t i = 0; i < counter; i++)
	{
		if (dynamic_cast<MovableObject*>(objects[i]) != nullptr && pow(objects[i]->GetX() - x, 2) + pow(objects[i]->GetY() - y, 2) <= pow(r, 2)) {
			ObjectsInArray++;
		}
	}

	MovableObject** ids = new MovableObject * [ObjectsInArray];
	int j = 0;

	for (size_t i = 0; i < counter; i++)
	{
		if (dynamic_cast<MovableObject*>(objects[i]) != nullptr && pow(objects[i]->GetX() - x, 2) + pow(objects[i]->GetY() - y, 2) <= pow(r, 2)) {
			ids[j] = dynamic_cast<MovableObject*>(objects[i]);
			j++;
		}
	}

	return ids;
}

	MovableObject** Game::FindMovableObjectInArea(double x, double y, double r, double umin, double umax){

	int ObjectsInArray = 0;

	for (size_t i = 0; i < counter; i++)
	{
		
		if (dynamic_cast<MovableObject*>(objects[i]) != nullptr && pow(objects[i]->GetX() - x, 2) + pow(objects[i]->GetY() - y, 2) <= pow(r, 2)) {
			ObjectsInArray++;
		}
	}

	MovableObject** ids = new MovableObject * [ObjectsInArray];

	

	int j = 0;

	for (int i = 0; i < counter; i++)
	{	
		MovableObject* moveObj = dynamic_cast<MovableObject*>(objects[i]);
		if(moveObj != nullptr){
			if (pow(moveObj->GetX() - x, 2) + pow(moveObj->GetY() - y, 2) <= pow(r, 2) && moveObj->GetAngle() > umin && moveObj->GetAngle() < umax) {
				ids[j] = moveObj;
				j++;
			}
		}
	}

	return ids;
}
