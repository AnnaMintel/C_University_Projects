#include <iostream>
using namespace std;

int sum (int cost, int result, int price)
{
	int the_whole_price;
	the_whole_price = cost + result + price;
	return the_whole_price;
}

int main()
{
	int cats = 12, x, y, Price_X, Price_Y, common_price, cost; 
	cout << "One cat needs animal feed a day "; 
	cin >> x;
	cout << "One cat needs milk a day "; 
	cin >> y;
	cout << "All feed costs "; 
	cin >> Price_X;
	cout << "All milk costs "; 
	cin >> Price_Y;
	cout << "Common price for one cat "; 
	common_price = Price_X + Price_Y;
	cout << Price_X << '+' << Price_Y << '=' << common_price << endl; 
	cout << "One cat needs animal feed a day ";
	cost = common_price * cats;
	cout << common_price << '*' << cats << '=' << cost << endl; 

	int dogs = 1, z, Price_Z, result; 
	cout << endl << "One dog needs to eat a day ";
	cin >> z;
	cout << "It will cost "; 
	cin >> Price_Z;
	result = Price_Z * dogs;
	cout << Price_Z << '*' << dogs << '=' << result << endl; 

	int rabbits = 1, t, m, Price_T, Price_M, price;
	cout << endl << "One rabbit needs to eat grass a day "; 
	cin >> t;
	cout << "One rabbit needs to eat carrots a day "; 
	cin >> m;
	cout << "The whole cost of grass "; 
	cin >> Price_T;
	cout << "The whole cost of carrot "; 
	cin >> Price_M;
	price = (Price_T + Price_M) * rabbits; 
	cout << '(' << Price_T << '+' << Price_M << ')' << '*' << rabbits << '=' << price << endl;

	int the_whole_price;
	the_whole_price = sum (cost, result, price);
	cout << the_whole_price << endl;
	

	cin.get();
	return 0;
}
