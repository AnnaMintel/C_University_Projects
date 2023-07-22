#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int const j = 12;
	int month[j]; 
	int plan;
	int compare;

	cout << "Enter profit values for each month of the year: " << endl; 
	for (int i = 0; i < 12; i++) {
		cout << "Month [" << i + 1 << "]:= ";
		cin >> month[i];
	}
	cout << endl;
	cout << "Enter planned revenue: "; 
	cin >> plan;
	int x = 0; 
	for (int i = 0; i < 12; i++) { 
		
		
		if (month[i] < plan) { 
			x++;
			cout << i+1 << endl;
		}
	}
	if (x == 0) { 
	cout << "Plan is completed!" << endl;
		}
	cin.get();
	return 0;
}