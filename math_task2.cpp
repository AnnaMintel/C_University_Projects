#include <iostream>
#include <conio.h>
#include <math.h> 

using namespace std;

int main()
{
	cout << "Student Anna Mintel" << endl;

	double x = 14.26;
	double y = -1.22;
	double z = 3.5 * (10 ^ -2);
	double t;
	const double PI = 3.14;

	t = (2 * cos(x - (PI / 6))) / (0.5 + pow(sin(y), 2)) * (1 + ((pow(z, 2) / (3 - pow(z, 2) / 5))));

	cout << "Value t = " << t << endl;

	cin.get();
	return 0;
}
