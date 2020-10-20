#include <iostream>
#include "Game.h"
#include "StaticObject.h"
#include "MovableObject.h"
#include "Monster.h"

using namespace std;

int main(int argc, char** argv) {

	Game* game = new Game;
	Object* obj1 = new StaticObject(1,smallPlant);
	Object* obj2 = new StaticObject(2, bigPlant);
	Object* obj3 = new MovableObject(3,2);
	Object* obj4 = new MovableObject(4,2);
	Object* obj5 = new Monster(4,1,5,3);

	game->insertObject(obj1);
	game->insertObject(obj2);
	game->insertObject(obj3);
	game->insertObject(obj4);

	obj1->SetX(1);
	obj1->SetY(2);

	obj3->SetX(1);
	obj3->SetY(2);

	delete obj1, obj2, obj3, obj4, game;

	return 0;
}