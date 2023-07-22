#include <iostream>
#include <conio.h>
#include <math.h> 

using namespace std;

int main()
{
	cout << "Student Anna Mintel" << endl;

	double x = 0.4E4;  

	double y = -0.875;
	double z = -0.475E-3;
	double w;

	w = (pow(fabs(cos(x) - cos(y)), (1 + 2 * pow(sin(y), 2)))) * (1 + z + (pow(z, 2) / 2) + (pow(z, 3) / 3) + (pow(z, 4) / 4));

	cout << "Value w = " << w << endl;

	cin.get();
	return 0;
}

