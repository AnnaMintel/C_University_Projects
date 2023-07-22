#include <iostream>
#include <fstream> 

using namespace std;

int main(int args, const char* argv[])
{
	char text[50]; 

	ofstream textfile("text2.txt"); 
	textfile << "Hi! Everything works great!"; 
	textfile.close(); 

	ifstream file("text2.txt"); 
	if (!file.is_open()) 
		cout << "Error! File is not found!" << endl;
	else { 

		file.getline(text, 50); 
		cout << text << endl;
		file.close();

	}


	cin.get();
	return 0;
}