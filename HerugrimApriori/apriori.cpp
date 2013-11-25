#include <iostream>
#include "dataset.h"
using namespace std;

int main()
{
	Dataset mainData = Dataset();

	string fileName, junk;

	cout << "Enter name of .input (DO NOT INCLUDE .input):\n";
	getline(cin, fileName);

	while(mainData.getSpecifications(fileName) == false)
	{
		cout << "~Error: Invalid File Name~\n";
		cout << "Enter name of .input (DO NOT INCLUDE .input):\n";
		getline(cin, fileName);
	}



	return 0;
} 