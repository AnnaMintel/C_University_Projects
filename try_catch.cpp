#include <iostream>

using namespace std;

int main(int args, const char* argv[]) {

	int num1;
	int num2;

	cout << "Enter num1: ";
	cin >> num1;
	cout << "Enter num2: ";
	cin >> num2;

	cout << "num1 + num2 = " << num1 + num2 << endl;
	cout << "num1 / num2 = ";

	try { 
		if (num2 == 0)
			throw 123; 
		cout << num1 / num2 << endl; 
	}
	catch (int i) { 
		cout << "Error k" << i << " - divide by 0!!!" << endl;
	}

	cin.get();
	return 0;
}
