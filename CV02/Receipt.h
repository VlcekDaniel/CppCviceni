#pragma once
#ifndef RECEIPT_H
#define RECEIPT_H

class Receipt
{
private:
    unsigned id;
    double cost;
    double dph;
public:
    void SetId(int id);
    int GetId() const;
    void SetCost(int cost);
    int GetCost() const;
    void SetDPH(double dph);
    double GetDPH() const;
};

#endif // !RECEIPT_H

