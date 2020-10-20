#pragma once
#ifndef MOVABLE_OBJECT_H
#define MOVABLE_OBJECT_H
#include "Object.h"
class MovableObject : public Object
{
private:
	double angle;
public:
	MovableObject(int id,double angle);
	~MovableObject();

	double GetAngle() const;
	void SetAngle(double angle);
};
#endif MOVABLE_OBJECT_H