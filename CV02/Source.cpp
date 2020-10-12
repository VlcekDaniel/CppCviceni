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

	cashRegister->CreateReceipt(120,0.20);
	cout << "receipt added" << endl;
	cashRegister->CreateReceipt(150,0.30);
	cout << "receipt added" << endl;
	cashRegister->CreateReceipt(250,0.230);
	cout << "receipt added" << endl;

	cout << "total price of all receipts: " << cashRegister->ReturnReceiptsValue() << endl;
	cout << "total price of all receipts with DPH: " << cashRegister->ReturnReceiptsValueDPH() << endl;

	Receipt receipt = cashRegister->FindReceipt(1001);

	cout << receipt.GetCost() << endl;

	return 0;
}