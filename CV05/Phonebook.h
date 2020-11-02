#pragma once
#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Person.h"
#include <string>

namespace Model {

	class Phonebook {
	private:
		class Node
		{	
		public:
			Node* next;
			Entity::Person data;
			int key;
			Node(Entity::Person data,int key);
		};
		Node* head;
	public:
		Phonebook();
		~Phonebook();
		void AddPerson(Entity::Person person);
		std::string FindPhone(std::string name) const;
		std::string FindPhone(int id) const;
	};
}

#endif // PHONEBOOK_H
