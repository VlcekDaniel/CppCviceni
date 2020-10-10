#pragma once
#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include "Receipt.h"

class CashRegister 
{
private:
    Receipt* receipts;
    int receiptsCount;
    static int idCounter;
public:
    CashRegister();
    ~CashRegister();

    Receipt& CreateReceipt(double cost, double dph);

    Receipt& returnReceipt();

    double dejCastku() const;

    double dejCastkuVcDph() const;
};

#endif // !CASH_REGISTER_H
