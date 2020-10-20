#pragma once
#ifndef OBJECT_H
#define OBJECT_H
class Object
{
private:
	int id;
	int x;
	int y;
public:
    Object(int id);
    virtual ~Object();
    void SetX(int x);
    int GetX() const;
    void SetY(int y);
    int GetY() const;
    int GetId() const;
};
#endif OBJECT_H