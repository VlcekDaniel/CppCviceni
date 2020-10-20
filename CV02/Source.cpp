#include "Receipt.h"
#include "CashRegister.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	Receipt* receipt1 = new Receipt();
	receipt1->SetId(1001);
	cout << "receipt1 created" << endl;

	Receipt receipt2 =  Receipt();
	receipt2.SetId(1002);
	cout << "receipt2 created" << endl;

	CashRegister* cashRegister = new CashRegister();
	CashRegister* cashRegister2 = new CashRegister();

	cashRegister->CreateReceipt(120,0.20);
	cout << "receipt added" << endl;
	cashRegister->CreateReceipt(150,0.30);
	cout << "receipt added" << endl;
	cashRegister->CreateReceipt(250,0.230);
	cout << "receipt added" << endl;

	cashRegister2->CreateReceipt(300, 0.20);
	cout << "receipt added" << endl;
	cashRegister2->CreateReceipt(200, 0.30);
	cout << "receipt added" << endl;
	cashRegister2->CreateReceipt(150, 0.230);
	cout << "receipt added" << endl;

	cout << "total price of all receipts: " << cashRegister->ReturnReceiptsValue() << endl;
	cout << "total price of all receipts with DPH: " << cashRegister->ReturnReceiptsValueDPH() << endl;

	cout << "total price of all receipts2: " << cashRegister2->ReturnReceiptsValue() << endl;
	cout << "total price of all receipts with DPH2: " << cashRegister2->ReturnReceiptsValueDPH() << endl;

	Receipt receipt = cashRegister->FindReceipt(1000);
	Receipt receiptt = cashRegister2->FindReceipt(1000);

	cout << receipt.GetCost() << endl;
	cout << receiptt.GetCost() << endl;

	delete cashRegister;
	delete cashRegister2;

	return 0;
}