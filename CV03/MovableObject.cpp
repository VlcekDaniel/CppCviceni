#include "MovableObject.h"

MovableObject::MovableObject(int id, double angle) : Object(id),angle(angle) {
	this->angle = angle;
}

MovableObject::~MovableObject() {

}

double MovableObject::GetAngle() const {
	return this->angle;
}

void MovableObject::SetAngle(double angle) {
	if (angle > 0 && angle < 2 * 3.1415) {
		this->angle = angle;
	}
}
