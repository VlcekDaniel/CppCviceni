#include "Receipt.h";

void Receipt::SetId(int id)
{
	 this->id = id; 
}

int Receipt::GetId() const
{
	return id;
}

void Receipt::SetCost(int cost)
{
	this->cost = cost;
}

int Receipt::GetCost() const
{
	return cost;
}

void Receipt::SetDPH(double dph)
{
	this->dph = dph;
}

double Receipt::GetDPH() const
{
	return dph;
}

