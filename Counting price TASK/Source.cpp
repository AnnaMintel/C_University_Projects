#include <iostream>
using namespace std;

int sum(int cost, int result, int price) // прописываем
{
	int the_whole_price;
	the_whole_price = cost + result + price;
	return the_whole_price;
}

int main()
{
	int cats = 12, x, y, Price_X, Price_Y, common_price, cost; // задаем все переменные для кота
	cout << "One cat needs animal feed a day "; // прописываем в консоли, сколько еды нужно коту в день
	cin >> x;
	cout << "One cat needs milk a day "; // прописываем, сколько молока нужно в день
	cin >> y;
	cout << "All feed costs "; // прописываем, сколько стоит еда для кота
	cin >> Price_X;
	cout << "All milk costs "; // ... и сколько стоит молоко
	cin >> Price_Y;
	cout << "Common price for one cat "; // подсчитаем, сколько денег уходит на 1 кота в 1 день
	common_price = Price_X + Price_Y;
	cout << Price_X << '+' << Price_Y << '=' << common_price << endl; // расписываем формулу для подсчета стоимости еды для 1 кота
	cout << "One cat needs animal feed a day ";
	cost = common_price * cats;
	cout << common_price << '*' << cats << '=' << cost << endl; // прописываем, сколько в общем уйдет денег на 12 котов в день

	int dogs = 1, z, Price_Z, result; // задаем переменные, с которыми будем работать
	cout << endl << "One dog needs to eat a day "; // прописываем запрос, который будет в консоли (с отступом от прошлой строки)
	cin >> z;
	cout << "It will cost "; // в консоли будем вводить значение после этой строки
	cin >> Price_Z;
	result = Price_Z * dogs;
	cout << Price_Z << '*' << dogs << '=' << result << endl; // итоговая формула для подсчета стоимости еды для 1 собаки на 1 день

	int rabbits = 1, t, m, Price_T, Price_M, price;
	cout << endl << "One rabbit needs to eat grass a day "; // отступ, затем пропишем в консоли количество травы для кролика
	cin >> t;
	cout << "One rabbit needs to eat carrots a day "; // ...... и количество морковки
	cin >> m;
	cout << "The whole cost of grass "; // подсчитываем стоимость травы для 1 кролика
	cin >> Price_T;
	cout << "The whole cost of carrot "; //.... и подсчитываем стоимость морковки
	cin >> Price_M;
	price = (Price_T + Price_M) * rabbits; // суммируем стоимость морковки и травы и сразу же умножаем на количество кроликов
	cout << '(' << Price_T << '+' << Price_M << ')' << '*' << rabbits << '=' << price << endl;

	int the_whole_price;
	the_whole_price = sum(cost, result, price);
	cout << the_whole_price << endl;


	cin.get();
	return 0;
}