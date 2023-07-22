#include <iostream>

using namespace std;

struct Date { 
	int year;
};

struct Auto { 
	int wheels;
	float speed;
	char color;

	Date sozdanie; 
};

int main(int args, const char* argv[])
{
	Auto Shkoda; 
	Shkoda.color = 'r'; 
	Shkoda.speed = 315.23;
	Shkoda.wheels = 4;
	Shkoda.sozdanie.year = 1999;

	Auto Audi = { 4, 300.23, 'b' }; 

	cout << "Audi speed = " << Audi.speed << endl << "Shkoda year " << Shkoda.sozdanie.year << endl;

	cin.get();
	return 0;
}
