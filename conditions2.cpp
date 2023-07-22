#include <iostream>
#include <iomanip>
#include <math.h> 

using namespace std;

int main()
{
	float y, x, d, m; 

	cout << "Enter x, please: " << endl;
	cin >> x;
	cout << "Enter y, please: " << endl;
	cin >> y;
	m = (4 * x) - 2; 

	if (x > y)
	{
		d = pow(sqrt(fabs(m - y)), 1 / 3) + tan(m); 
		cout << "d= " << d;
	}
	else if (y < x)
	{
		d = pow((y - m), 2) + cos(m); 
		cout << "d= " << d;
	}
	else if (y = x)
	{
		d = pow((y + m), 2) + pow(x, 3); 
		cout << "d= " << d;
	}

	cin.get();
	return 0;
}