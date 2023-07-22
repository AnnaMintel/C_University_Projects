
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int main()
{
	std::string username;
	int password = 1234;
	int passValue;

	cout << "Welcome to the pet shop! Please, enter your name: " << endl;
	cin >> username;
	cout << "Please, enter your password: " << endl;
	cin >> passValue;
	while (passValue != password) {
		cout << "Entered password is not correct. Please, enter your password: " << endl;
		cin >> passValue;
	}
	cout << "Welcome " << username << endl;
	std::string answer;

	int cat = 1, dog = 2, rabbit = 3, pet; 
	int petCost, foodCost;

	cout << "What pet do you want to buy? CAT - enter 1, DOG - enter 2, RABBIT - enter 3" << endl;
	cout << "Your choice: " << endl;
	cin >> pet;

	switch (pet) 
	{
	case 1: petCost = 10; 
		foodCost = 2;
		cout << "Do you want to buy any food? (yes/no) " << endl;
		cin >> answer;
		if (answer == "yes") {
			int result = petCost + foodCost; 
			cout << "Please pay $  " << result << endl; 
			cout << "Thanks for your choice! Good luck! " << endl;
			break;
		}
		else if (answer == "no") {
			cout << "Please pay $  " << petCost << endl;
			cout << "Thanks for your choice! Good luck! " << endl;
			break;
		}
		else { cout << "ERROR, enter the correct answer! " << endl; }

	case 2: petCost = 15; 
		foodCost = 3;
		cout << "Do you want to buy any food? (yes/no) " << endl;
		cin >> answer;
		if (answer == "yes") { 
			int result = petCost + foodCost; 
			cout << "Please pay $  " << result << endl; 
			cout << "Thanks for your choice! Good luck! " << endl;
			break;
		}
		else if (answer == "no") {
			cout << "Please pay $  " << petCost << endl;
			cout << "Thanks for your choice! Good luck! " << endl;
			break;
		}
		else { cout << "ERROR, enter the correct answer! " << endl; }

	case 3: petCost = 20; 
		foodCost = 5;
		cout << "Do you want to buy any food? (yes/no) " << endl;
		cin >> answer;
		if (answer == "yes") { 
			int result = petCost + foodCost; 
			cout << "Please pay $  " << result << endl; 
			cout << "Thanks for your choice! Good luck! " << endl;
			break;
		}
		else if (answer == "no") {
			cout << "Please pay $  " << petCost << endl;
			cout << "Thanks for your choice! Good luck! " << endl;
			break;
		}
		else { cout << "ERROR, enter the correct answer! " << endl; }
	default: 
		break;
	}

	cin.get();
	return 0;
}