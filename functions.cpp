#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int  payments_per_year, term_of_credit;
	double credit_percent, credit_sum, payment; 

	cout << "Credit percent  ";
	cin >> credit_percent;
	cout << "The whole credit sum ";
	cin >> credit_sum;
	cout << "Payments per year ";
	cin >> payments_per_year;
	cout << "The tearm of credit ";
	cin >> term_of_credit;

	payment = (credit_percent / 100) * (credit_sum / payments_per_year) / (1 - pow(((credit_percent / 100) / payments_per_year) + 1), (payments_per_year * term_of_credit));
	cout << "One credit payment " << payment << endl;

	cin.get();
	return 0;
}




