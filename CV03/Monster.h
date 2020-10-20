#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include "MovableObject.h"

class Monster : public MovableObject
{
private:
	int hp;
	int maxHp;
public:
	Monster(int id,double angle,int hp,int maxHp);
	~Monster();
	void SetHp(int hp);
	int GetHp() const;
	void SetMaxHp(int maxHp);
	int GetMaxHp() const;
};

#endif MONSTER_H