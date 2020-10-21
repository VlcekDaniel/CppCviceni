#include <iostream>
#include "Game.h"
#include "StaticObject.h"
#include "MovableObject.h"
#include "Monster.h"

using namespace std;

int main(int argc, char** argv) {

	Game* game = new Game;
	Object* obj1 = new StaticObject(1,smallPlant);
	obj1->SetX(1);
	obj1->SetY(2);
	Object* obj2 = new StaticObject(2, bigPlant);
	obj2->SetX(1);
	obj2->SetY(2);
	Object* obj3 = new MovableObject(3,2);
	obj3->SetX(1);
	obj3->SetY(1);
	Object* obj4 = new MovableObject(4,2);
	obj4->SetX(1);
	obj4->SetY(1);
	Object* obj5 = new MovableObject(5,2);
	obj5->SetX(1);
	obj5->SetY(1);
	Object* obj6 = new Monster(6, 2, 2, 2);
	obj6->SetX(1);
	obj6->SetY(1);

	game->InsertObject(obj1);
	game->InsertObject(obj2);
	game->InsertObject(obj3);
	game->InsertObject(obj4);
	game->InsertObject(obj5);


	cout << "Id hledaneho je: " << game->FindIdStaticObjects(0, 3, 0, 3)[0] << endl;
	cout << "Id hledaneho je: " << game->FindIdStaticObjects(0, 3, 0, 3)[1] << endl;

	//cout << "Id hledaneho je: " << game->FindMovableObjectInArea(0, 0, 10)[0]->GetId() << endl;
	//cout << "Id hledaneho je: " << game->FindMovableObjectInArea(0, 0, 10)[1]->GetId() << endl;

	cout << "Id hledaneho je: " << game->FindMovableObjectInArea(0, 0,10,0,10)[0]->GetId() << endl;
	cout << "Id hledaneho je: " << game->FindMovableObjectInArea(0, 0, 10, 0, 10)[1]->GetId() << endl;
	cout << "Id hledaneho je: " << game->FindMovableObjectInArea(0, 0, 10, 0, 10)[2]->GetId() << endl;

	delete game;

	return 0;
}