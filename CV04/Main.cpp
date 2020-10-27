#include "Time.h"
#include <time.h>
#include "IComparable.h"
#include <iostream>

#define SIZE 10

using namespace std;

int GetRandom(int min, int max);
void PrintArray(IComparable** arr, int size);
void SortArray(IComparable** arr, int n);

int main(int argc, char** argv) {

	Time** times = new Time * [SIZE];

	
	for (int i = 0; i < SIZE; i++)
	{
		int hours = GetRandom(0, 23);
		int minutes = GetRandom(0, 59);
		int seconds = GetRandom(0, 59);

		Time* time = new Time(hours, minutes, seconds);
		times[i] = time;		
	}
	
	PrintArray((IComparable**)times, SIZE);
	SortArray((IComparable**)times, SIZE);
	cout << "_________________" << endl;
	PrintArray((IComparable**)times, SIZE);

	delete[] times;
	return 0;
}
void SortArray(IComparable** arr, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) 
		for (j = 0; j < n - i - 1; j++)
		{ 
			if ((arr[j]->CompareTo(arr[j + 1]) == 1))
			{
				IComparable* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
}

void PrintArray(IComparable** arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i]->ToString() << endl;
}

int GetRandom(int min, int max) 
{
	static bool first = true;
	if (first)
	{
		srand(time(NULL)); 
		first = false;
	}
	return min + rand() % ((max + 1) - min);
}

