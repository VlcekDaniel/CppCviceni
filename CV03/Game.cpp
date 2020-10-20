#include "Game.h"

Game::Game() {
	objects = new Object*[10];
}

void Game::insertObject(Object* o) {
	objects[counter] = o;
	counter++;
}
//int* Game::findIdStaticObjects(double xmin, double xmax, double ymin, double ymax) {
//	return nullptr;
//}
//MovableObject** Game::findMovableObjectInArea(double x, double y, double r) {
//	return nullptr;
//}
//MovableObject** Game::findMovableObjectInArea(double x, double y, double r, double umin, double umax) {
//	return nullptr;
//}
