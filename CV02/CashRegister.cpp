#include "CashRegister.h"
#include <exception>

int CashRegister::idCounter = 1000;


CashRegister::CashRegister() {
    receipts = new Receipt[10];
    receiptsCount = 0;
}
CashRegister::~CashRegister() {

}
    Receipt& CashRegister::CreateReceipt(double cost, double dph)
    {
        if (receiptsCount == 10)
            throw new std::exception("Cash register is full");

        receipts[receiptsCount].SetId(idCounter + receiptsCount);
        receipts[receiptsCount].SetCost(cost);
        receipts[receiptsCount].SetDPH(dph);
        receiptsCount++;
        return receipts[receiptsCount -1];
    }

    
    Receipt& CashRegister::FindReceipt(unsigned id)
    {
        for (size_t i = 0; i < receiptsCount; i++)
        {
            if (id == receipts[i].GetId())
            {
                return receipts[i];
            }
        }
        throw new std::exception("Receipt not found");
    }

    double CashRegister::ReturnReceiptsValue() const
    {
        double totalCost = 0;
        for (size_t i = 0; i < receiptsCount; i++)
        {           
            totalCost += receipts[i].GetCost();
        }
        return totalCost;
    }
    
    double CashRegister::ReturnReceiptsValueDPH() const
    {
        double totalCostDPH = 0;
        for (size_t i = 0; i < receiptsCount; i++)
        {
            double a = receipts[i].GetCost();
            double b = receipts[i].GetDPH();            
            totalCostDPH += (a*(1+b));
        }
        return totalCostDPH;
    }
    