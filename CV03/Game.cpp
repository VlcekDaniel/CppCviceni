#include "Game.h"

Game::Game() {
	objects = new Object*[10];
}

void Game::InsertObject(Object* o) {
	objects[counter] = o;
	counter++;
}
int* Game::FindIdStaticObjects(double xmin, double xmax, double ymin, double ymax) {
	int* ids = new int[counter];

	for (size_t i = 0; i < counter; i++)
	{
		double x = objects[i]->GetX();
		double y = objects[i]->GetY();

		if (x > xmin && x<xmax && y>ymin && y < ymax) {
			ids[i] = objects[i]->GetId();
		}		 
	}
	return ids;
}
MovableObject** Game::FindMovableObjectInArea(double x, double y, double r) {
	return nullptr;
}
//MovableObject** Game::findMovableObjectInArea(double x, double y, double r, double umin, double umax) {
//	return nullptr;
//}
