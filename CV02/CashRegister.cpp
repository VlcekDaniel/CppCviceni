#include "CashRegister.h"
#include <exception>

int CashRegister::idCounter = 1000;


CashRegister::CashRegister() {

}
CashRegister::~CashRegister() {

}
    Receipt& CashRegister::CreateReceipt(double cost, double dph)
    {
        if (receiptsCount == 10)
            throw new std::exception("Cash registe is full");

        receipts[receiptsCount - 1].SetId(idCounter + receiptsCount);
        receiptsCount++;
        return receipts[receiptsCount -1];
    }
