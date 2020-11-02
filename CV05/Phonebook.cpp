#include "Phonebook.h"
#include "Person.h"

using namespace Entity;
using namespace Model;

	Model::Phonebook::Node::Node(Person data,int key)
	{
		this->data = data;
		this->key = key;
	}
	Model::Phonebook::Phonebook()
	{
		head = nullptr;
	}
	void Phonebook::AddPerson(Person person)
	{
		Node* newNode = new Node(person,person.GetId());
		if (head == nullptr)
		{
			head = newNode;
		}
		else {
			Node* n = head;
			while (n->next != nullptr&& n->key!=person.GetId()){
				n = n->next;
			}
			if(n->key != person.GetId())
			n->next = newNode;
		}
	}
	std::string Phonebook::FindPhone(std::string name) const
	{
		if (head == nullptr)
		{
			throw std::exception();
		}
		else {
			Node* n = head;
			while (true) {
				if ( n->data.GetName()==name)
					return n->data.GetPhone();
				if(n->next!=nullptr)
				n = n->next;
			}
			throw exception("");
		}
	}
	std::string Phonebook::FindPhone(int id) const
	{
		if (head == nullptr)
		{
			throw std::exception();
		}
		else {
			Node* n = head;
			while (true) {
			
				if (id == n->key)
					return n->data.GetPhone();			
				if (n->next != nullptr) {
					n = n->next;
				}
			}
			throw exception("");
		}
	}
