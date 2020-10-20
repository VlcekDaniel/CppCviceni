#include "Object.h"

	Object::Object(int id) {
		this->id = id;
	}
	Object::~Object() {

	}
	void Object::SetX(int x) {
		this->x = x;
	}
	void Object::SetY(int y) {
		this->y = y;
	}
	int Object::GetX() const {
		return this->x;
	}
	int Object::GetY() const {
		return this->y;
	}
	int Object::GetId() const {
		return this->id;
	}
