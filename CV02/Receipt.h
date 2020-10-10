#pragma once
#ifndef RECEIPT_H
#define RECEIPT_H

class Receipt
{
private:
    unsigned id;
    double amount;
    double dph;
public:
    void SetId(int id);
    int GetId() const;
};

#endif // !RECEIPT_H

