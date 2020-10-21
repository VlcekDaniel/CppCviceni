#include "StaticObject.h"
#include "ObstacleType.h"


StaticObject::StaticObject(int id, ObstacleType ObstacleType) : Object(id), obstacleType(obstacleType)
{
	this->obstacleType = obstacleType;	
}

StaticObject::~StaticObject() {
	
}

ObstacleType StaticObject::GetObstacleType() const{
	return this->obstacleType;
}