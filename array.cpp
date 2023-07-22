#include <iostream>

using namespace std;

int main(int args, const char* argv[])
{
	int arr[3][2] = {{23, 34}, {1, 2}, {5, 7}};

	for (int i = 0; i < 3; i++) { 
		for (int j = 0; j < 2; j++) { 
			cout << " " << arr[i][j]; 
		}
		cout << endl; 
	}

	cin.get();
	return 0;

}
