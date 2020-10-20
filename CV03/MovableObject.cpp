#include "MovableObject.h"

MovableObject::MovableObject(int id, double angle) : Object(id) {
	Object* object = new Object(id);
	this->angle = angle;
}

MovableObject::~MovableObject() {

}

double MovableObject::GetAngle() const {
	return this->angle;
}

void MovableObject::SetAngle(double angle) {
	this->angle = angle;
}
