#pragma once
#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "MovableObject.h"
class Game
{
private:
	Object** objects;
	int counter = 0;
public:
	Game();
	~Game();
	void insertObject(Object* o);
	int* findIdStaticObjects(double xmin, double xmax, double ymin, double ymax);
	MovableObject** findMovableObjectInArea(double x, double y, double r);
	MovableObject** findMovableObjectInArea(double x, double y, double r, double umin, double umax);
};
#endif GAME_H




