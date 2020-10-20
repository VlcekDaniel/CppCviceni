#include "StaticObject.h"
#include "ObstacleType.h"


StaticObject::StaticObject(int id, ObstacleType ObstacleType) : Object(id)
{
	Object* object = new Object(id);
	this->obstacleType = obstacleType;	
}

StaticObject::~StaticObject() {
	
}

ObstacleType StaticObject::GetObstacleType() const{
	return this->obstacleType;
}