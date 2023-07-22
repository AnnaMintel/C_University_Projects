#include <iostream>
#include <iomanip>

using namespace std;

int main()
{  
    const int n = 3;
    int MagicSquare[n][n] = {
         { 2, 9, 4 },
         { 7, 5, 3 },
         { 6, 1, 8 }
    }; 
        int sum_array[8]; 
        int pos = 0; 

 
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++)
            {
                sum_array[pos] = sum_array[pos] + MagicSquare[i][j];
            }
            pos++;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum_array[pos] = sum_array[pos] + MagicSquare[j][i];
            }
            pos++;
        }
        
     
        for (int i = n; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    sum_array[pos] = sum_array[pos] + MagicSquare[i][j];
            }
        }
        
  
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    sum_array[pos] += MagicSquare[i][j];
            }
        }
   
        int value = sum_array[0], count = 0; 
        for (int i = 0; i < pos; i++)
        {
            if (sum_array[i] == value) count++;
        }
        if (count == pos) 
            cout<<"IT IS a MAGIC SQUARE!"<<endl;
        else 
            cout<<"IT ISN'T a MAGIC SQUARE"<<endl;
       
	cin.get();
	return 0;
}