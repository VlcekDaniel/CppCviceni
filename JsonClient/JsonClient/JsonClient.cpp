
#include "JsonClient.h"
#include "Automobil.h"
#include <iostream>
#include <crtdbg.h>
#include <stdlib.h>
#define _CRTDBG_MAP_ALLOC

using namespace std;
int main(int argc, char** argv) {
	int menu();
	int selection;
	ArrayValue* value = new ArrayValue{};
	JSON json;
	do
	{
		selection = menu();
		switch (selection)
		{			
		case 1: 
		{
			string id, znacka, vykon, jeNaBenzin;
			cout << "Zadejte ID" << endl;
			cin >> id;
			cout << "Zadejte Znacku" << endl;
			cin >> znacka;
			cout << "Zadejte vykon" << endl;
			cin >> vykon;
			cout << "Zadejte zda je na benzin (1/0)" << endl;
			cin >> jeNaBenzin;		
			bool boolJeNaBenzin;
			if (stoi(jeNaBenzin) == 1) {
				boolJeNaBenzin = true;
			}
			else
			{
				boolJeNaBenzin = false;
			}
			Automobil automobil = Automobil(stoi(id),znacka,stoi(vykon),boolJeNaBenzin);
			value->append(json.deserialize(automobil.getString()));
			break;
		}
		case 2:  
		{
			string pozice;
			cout << "Zadejte index na kterem chcete odebrat automobil" << endl;
			cin >> pozice;
			value->removeOnIndex(stoi(pozice));
			break;
		}
		case 3:  
		{		
			string pozice;
			string id, znacka, vykon, jeNaBenzin;
			cout << "Zadejte index na kterem indexu chcete upravit automobil" << endl;
			cin >> pozice;
			cout << "Zadejte ID" << endl;
			cin >> id;
			cout << "Zadejte Znacku" << endl;
			cin >> znacka;
			cout << "Zadejte vykon" << endl;
			cin >> vykon;
			cout << "Zadejte zda je na benzin (1/0)" << endl;
			cin >> jeNaBenzin;
			bool boolJeNaBenzin;
			if (stoi(jeNaBenzin) == 1) {
				boolJeNaBenzin = true;
			}
			else
			{
				boolJeNaBenzin = false;
			}
			Automobil automobil = Automobil(stoi(id), znacka, stoi(vykon),boolJeNaBenzin);
			value->edit(json.deserialize(automobil.getString()), stoi(pozice));
		}
		break;
		case 4:
		{	
			std::string text;
			text = json.readFile("new.json");
			value->append(json.deserialize(text));
			break;
		}
		case 5:
		{
			json.saveFile("new.json",json.serialize(dynamic_cast <Value*>(value)));
		}
		break;
		case 6:
			cout << json.serialize(dynamic_cast <Value*>(value));
			break;
		case 7:
		{
			delete value;
			if (_CrtDumpMemoryLeaks() != 0) {
				printf("Nebyla provedena dealokace");
			}		
			break;
		}
		}
	} while (selection != 7);
}
int menu()
{
	int choice;
	cout << "\nSprava automobilu\n";
	cout << "--------------------------------\n";
	cout << "1) Vloz\n";
	cout << "--------------------------------\n";
	cout << "2) Odeber\n";
	cout << "--------------------------------\n";
	cout << "3) Edituj\n";
	cout << "--------------------------------\n";
	cout << "4) Nacti JSON\n";
	cout << "--------------------------------\n";
	cout << "5) Uloz JSON\n";
	cout << "--------------------------------\n";
	cout << "6) Zobraz JSON\n";
	cout << "--------------------------------\n";
	cout << "7) Exit\n";
	cout << "--------------------------------\n";

	cin >> choice;
	while (choice < 1 || choice > 8)  
	{
		cout << "Invalid Selection. Enter 1, 2, 3, 4, 5, 6 or 7";
		cin >> choice;
	}
	return choice;
}


