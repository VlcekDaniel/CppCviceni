#pragma once
#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "MovableObject.h"
class Game
{
private:
	Object** objects;
	int counter;
	int maxObjects;
public:
	Game();
	~Game();
	void InsertObject(Object* o);
	int* FindIdStaticObjects(double xmin, double xmax, double ymin, double ymax);
	MovableObject** FindMovableObjectInArea(double x, double y, double r);
	MovableObject** FindMovableObjectInArea(double x, double y, double r, double umin, double umax);
};
#endif GAME_H




