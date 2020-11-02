#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
namespace Entity 
{
class Person {
	private:
		int id;
		std::string name;
		std::string phone;
		
public:
	Person(std::string name, std::string phone, int id);
	Person();
	int GetId()const;
	string GetPhone() const;
	string GetName() const;
	};
}
#endif //PERSON_H
