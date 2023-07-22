#include <iostream>
#include <conio.h>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	cout << "Student Anna Mintel" << endl;

	double x = 2.92;
	double y = 6.96 * pow(10, (-2));
	double i;
	double F;
	
	for (int j = 0; j < 3; j++) 
	{
		cout << "Enter i ";
		cin >> i;
		if (i < 1.5) 
			F = (i + y);
		else if (i >= 1.5) 
			F = (i + (pow(x, 2))); 
		else
			cout << "The result is not found!";
	
		cout << "i= " << setw(5) << i << setw(15) << F << endl; 
		i = i + 0.2;
	}

	cin.get();
	return 0;
}