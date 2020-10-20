#pragma once
#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include "Object.h"
#include "ObstacleType.h"
class StaticObject : public Object
{
private:
	ObstacleType obstacleType;
public:
	StaticObject(int id,ObstacleType obstacleType);
	~StaticObject();
	ObstacleType GetObstacleType() const;
};
#endif STATIC_OBJECT_H
