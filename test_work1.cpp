#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;
int main()
{
	int userValue; 
			
	for (int i = 0; i < 25; i++) // create the cycle of 25 attempts
	{
		cout << "Enter the number " << endl; 
		cin >> userValue;

		if ( i < 5) { // from 1 to 5 the numbers are positive
			if (userValue < 0) { // if userValue less than 0 show Error
				cout << "Error, need positive value  " << endl; // cout 
				i = i - 1; //
			}
			
		}
		else if (i >= 5 && i < 10) { // from 5 to 10 the numbers are negative
			if (userValue > 0) { // if userValue more than 0 show Error
				cout << "Error, need negative value  " << endl; 
				i = i - 1;
			}
			
		}
		else if (i >= 10 && i < 15) { // from 10 to 15 the numbers from 10 to 100
			if (userValue > 100 || userValue < 10) { // if userValue more than 10 and less than 100 show Error
				cout << "Error, need value from 10 to 100 " << endl;
				i = i - 1;
			}
		
		}
		else if (i >= 15 && i < 20) { // from 15 to 20 the numbers are even
			if (userValue % 2 != 0) { // if userValue not even show Error
				cout << "Error, need even number " << endl; 
				i = i - 1;
			}
			
		}
		else if (i >= 20 && i < 25) { // from 20 to 25 the numbers 100+
			if (userValue < 100) { // if userValue less than 100 show Error
				cout << "Error, need number 100+ " << endl;
				i = i - 1;
			}
			
		}

	}
	cin.get();
	return 0;
}