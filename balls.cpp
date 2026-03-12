#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;

void PrintArray(int Array[], int LengthOfArray)
{
	for (int i = 0; i < LengthOfArray; i++)
	{
		cout << Array[i] <<  " ";
	}
	cout << '\n';
}

void Fillballs(int Array[], int LengthOfArray)
{
	for (int i = 1; i < (LengthOfArray + 1); i++)
	{
		Array[i-1] = i;
	}
}

void Shuffleballs(int Array[], int LengthOfArray)
{
	//shuffleballs
	for (int i = 0; i < LengthOfArray; i++)
	{
		int FirstNum = rand() % 45;
		int SecNum = rand() % 45;

		int Temp = Array[FirstNum];
		Array[FirstNum] = Array[SecNum];
		Array[SecNum] = Temp;
	}
}

void PickSixRanBalls(int Array[], int Picktimes, int LengthOfArray, int PArray[])
{


	int RandNum = 0;
	for (int i = 0; i < Picktimes; i++)
	{
		RandNum = rand() % 45 + 1;
		
		if (Array[RandNum] == 0)
		{
			i -= 1;
		}
		else if (Array[RandNum] != 0)
		{
			cout << (i+1) << "th Number picked from " << LengthOfArray << " balls is : " << Array[RandNum] << " ";
			PArray[i] = Array[RandNum];
			Array[RandNum] = 0;
		}
	}
	cout << "\n";
	for (int i = 0; i < Picktimes; i++)
	{
		if (i == 0)
		{
			cout << " 6 Lucky numbers are ";
			cout << PArray[i] << " ";
		}
		else
		{
			cout << PArray[i] << " ";
		}
	}
	cout << "\n";
}
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	int Size = 0;
	int PickNumballs = 0;
	cout << "How many balls to pick from? : ";
	cin >> Size;

	int* DArray = new int[Size]{};
	//cout << "Length of Array : " << Size << '\n';
	Fillballs(DArray, Size);

	cout << "How many balls do you want to pick? : ";
	cin >> PickNumballs;

	Shuffleballs(DArray, Size);
	PrintArray(DArray, Size);
	int* PArray = new int[PickNumballs] {};
	PickSixRanBalls(DArray, PickNumballs, Size, PArray);


	delete[] DArray;
	delete[] PArray;
	DArray = nullptr;
	PArray = nullptr;
	return 0;
}












