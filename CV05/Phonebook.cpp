#include "Phonebook.h"
#include "Person.h"
#include <stdexcept>

using namespace Entity;
using namespace Model;
using namespace std;

	Model::Phonebook::Node::Node(Person data,int key)
	{
		this->data = data;
		this->key = key;
	}
	Model::Phonebook::Phonebook()
	{
		head = nullptr;
	}
	Model::Phonebook::~Phonebook()
	{
		Node* node = head;
		while (node != nullptr) {
			Node* tmp = node->next;
			delete node;
			node = tmp;
		}
	}
	void Phonebook::AddPerson(Person person)
	{
		Node* newNode = new Node(person,person.GetId());
		if (head == nullptr)
		{
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}
	std::string Phonebook::FindPhone(std::string name) const
	{
		if (head == nullptr)
		{
			throw invalid_argument("Phonebook is empty");
		}
			Node* n = head;
			while (true) {
				if ( n->data.GetName()==name)
					return n->data.GetPhone();
				if(n->next!=nullptr)
				n = n->next;
			}
			throw invalid_argument("Name not found");
	}
	std::string Phonebook::FindPhone(int id) const
	{
		if (head == nullptr)
		{
			throw invalid_argument("Phonebook is empty");
		}
			Node* n = head;
			while (true) {
			
				if (id == n->key)
					return n->data.GetPhone();			
				if (n->next != nullptr) {
					n = n->next;
				}
			}
			throw invalid_argument("Id not found");
	}

