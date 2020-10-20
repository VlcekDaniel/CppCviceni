#include "Monster.h"
#include "MovableObject.h"

Monster::Monster(int id,double angle, int hp, int maxHp) : MovableObject(id,angle) {
	
	this->hp = hp;
	this->maxHp = maxHp;
}
Monster::~Monster() {

}

void Monster::SetHp(int hp) {
	this->hp = hp;
}
int Monster::GetHp() const {
	return this->hp;
}
void Monster::SetMaxHp(int maxHp) {
	this->maxHp = maxHp;
}
int Monster::GetMaxHp() const {
	return this->maxHp;
}