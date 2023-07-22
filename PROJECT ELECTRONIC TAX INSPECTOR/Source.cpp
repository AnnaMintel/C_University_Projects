

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <wchar.h>
#include <locale.h>
#include <math.h>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <clocale>
#include <string>

using namespace std;

// ******* ��������� ��������� ��� ������ *******

struct PAYERS_AND_TAXES
{
    int registration_number; 
    char payers[30]; 
    int taxes_code; 
};

struct PAYERS_DEBT
{
    char payers[30]; 
    int debt; 
};

struct TERM_OF_PAYMENT_AND_TAXES_NAME
{
    int taxes_code; 
    string terms; 
    char taxes_name[20]; 
    int numeration; 
};

struct REQUISITES
{
    int numeration; 
    char requisites[150];
};

struct PROPERTY
{
    int registration_number; 
    char property[50]; 
};

struct  INSPECTOR_AND_MEASURE
{
    int registration_number; 
    char inspector[12]; 
    string measure; 
};


// ******* ��������� ���������� �������� ��� ������ *******


// ******* ���� ���������� ������� *******
void description(); 
void warning(int a, int b); 
int return_to_main_menu(); 
void shutdown(); 

// ******* ��������� ����� ���������� ������� *******

int main()
{
    setlocale(LC_ALL, "Russian_Russia.1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, ".1251");
    setlocale(LC_ALL, "Russian");

    // ******* ���������� ����������, ��������, ���������� � ��. *******

    
    char answer_1 = 0; 
    char answer_2 = 0; 
    char answer_3 = 0; 


    // ������� ��� �������� ������ �� ������

    PAYERS_AND_TAXES array_PAYERS_AND_TAXES[10]; 
    PAYERS_DEBT array_PAYERS_DEBT[10]; 
    TERM_OF_PAYMENT_AND_TAXES_NAME array_TERM_OF_PAYMENT_AND_TAXES_NAME[10]; 
    REQUISITES array_REQUISITES[2]; 
    PROPERTY array_PROPERTY[10]; 
    INSPECTOR_AND_MEASURE array_INSPECTOR_AND_MEASURE[10]; 

    PAYERS_AND_TAXES* p_array_PAYERS_AND_TAXES = array_PAYERS_AND_TAXES; 
    PAYERS_DEBT* p_array_PAYERS_DEBT = array_PAYERS_DEBT; 
    TERM_OF_PAYMENT_AND_TAXES_NAME* p_array_TERM_OF_PAYMENT_AND_TAXES_NAME = array_TERM_OF_PAYMENT_AND_TAXES_NAME; 
    REQUISITES* p_array_REQUISITES = array_REQUISITES; 
    PROPERTY* p_array_PROPERTY = array_PROPERTY;  
    INSPECTOR_AND_MEASURE* p_array_INSPECTOR_AND_MEASURE = array_INSPECTOR_AND_MEASURE; 

    ifstream p_t; 
    ifstream p_d; 
    ifstream t_p_t_n; 
    ifstream req; 
    ifstream prop; 
    ifstream i_m; 

    int a = 0; 
    int b = 0; 
    int c = 0; 
    int d = 0; 
    int e = 0; 
    int f = 0; 
    int gl_menu;


    // ******* ��������� ����� ���������� ����������, ��������, ���������� � ��. *******


    description(); 

    system("pause");
    system("cls");  

    // ������� ���� ���������
    do
    {
        warning(a, b);

        cout << " " << "-----------------------------------" << endl;
        cout << " " << "���� ���������: " << endl;
        cout << " " << "1 - ��������� �����. " << endl;
        cout << " " << "2 - ������� ������ ������ �� �����. " << endl;
        cout << " " << "3 - ������������� ������. " << endl;
        cout << " " << "4 - ��������� ������ ���������. " << endl;
        cout << endl;
        cout << "��� ����� -  ";
        cin >> answer_1;


        switch (answer_1)
        {
        case '1': 

            cout << endl;

            // ******* 1. ������ ����� "1 - REGISTRATION NUMBER, PAYERS, TAXES CODE" *******

            p_t.open("D:/POIS 2021-2022/c++/FINAL PROJECT/MY PROJECT/1 - REGISTRATION NUMBER, PAYERS, TAXES CODE.txt");
            if (!p_t.is_open()) 
            {
                cout << "Can't open 1 - REGISTRATION NUMBER, PAYERS, TAXES CODE.txt!" << endl;
            }
            else
            {
                int i = 0;
                for (int i = 0; i < 10; i++)
                {
                    p_t >> array_PAYERS_AND_TAXES[i].registration_number;
                    p_t >> array_PAYERS_AND_TAXES[i].payers;
                    p_t >> array_PAYERS_AND_TAXES[i].taxes_code;
                }

                if (!p_t.good())
                {
                    cout << "ERROR of reading  1 - REGISTRATION NUMBER, PAYERS, TAXES CODE.txt!" << endl;
                }
                p_t.close();
                a = i; 

                cout << " ���� 1 - REGISTRATION NUMBER, PAYERS, TAXES CODE ��������.txt." << endl;

            }

            // *******1.1 ������ ����� "1.1 - PAYERS, DEBT" *******

            p_d.open("D:/POIS 2021-2022/c++/FINAL PROJECT/MY PROJECT/1.1 - PAYERS, DEBT.txt");
            if (!p_d.is_open()) 
            {
                cout << "Can't open 1.1 - PAYERS, DEBT.txt!" << endl;
            }
            else
            {
                int i = 0;
                for (int i = 0; i < 10; i++)
                {
                    p_d >> array_PAYERS_DEBT[i].payers;
                    p_d >> array_PAYERS_DEBT[i].debt;
                }

                if (p_d.good())
                {
                    cout << "ERROR of reading  1.1 - PAYERS, DEBT.txt!" << endl;
                }
                p_d.close();
                b = i; 

                cout << " ���� 1.1 - PAYERS, DEBT.txt ��������." << endl;

            }

            // *******2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION *******

            t_p_t_n.open("D:/POIS 2021-2022/c++/FINAL PROJECT/MY PROJECT/2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION.txt");
            if (!t_p_t_n.is_open()) 
            {
                cout << "Can't open 2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION.txt!" << endl;
            }
            else
            {
                int i = 0;
                for (int i = 0; i < 10; i++)
                {
                    t_p_t_n >> array_TERM_OF_PAYMENT_AND_TAXES_NAME[i].taxes_code;
                    t_p_t_n >> array_TERM_OF_PAYMENT_AND_TAXES_NAME[i].terms;
                    t_p_t_n >> array_TERM_OF_PAYMENT_AND_TAXES_NAME[i].taxes_name;
                    t_p_t_n >> array_TERM_OF_PAYMENT_AND_TAXES_NAME[i].numeration;
                }

                if (t_p_t_n.good())
                {
                    cout << "ERROR of reading  2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION.txt!" << endl;
                }
                t_p_t_n.close();
                c = i; 

                cout << " ���� 2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION.txt ��������." << endl;

            }

            // *******1.1 ������ ����� "2.1 - REQUISITES, NUMERATION" *******

            req.open("D:/POIS 2021-2022/c++/FINAL PROJECT/MY PROJECT/2.1 - REQUISITES, NUMERATION.txt");
            if (!req.is_open()) 
            {
                cout << "Can't open 2.1 - REQUISITES, NUMERATION.txt!" << endl;
            }
            else
            {
                int i = 0;
                for (int i = 0; i < 2; i++)
                {
                    req >> array_REQUISITES[i].numeration;
                    req >> array_REQUISITES[i].requisites;
                }

                if (!req.good())
                {
                    cout << "ERROR of reading  2.1 - REQUISITES, NUMERATION.txt!" << endl;
                }
                req.close();
                d = i; 

                cout << " ���� 2.1 - REQUISITES, NUMERATION.txt ��������." << endl;
            }

            // ******* ������ ����� 3 - REGISTRATION NUMBER, PROPERTY, CASH *******

            prop.open("D:/POIS 2021-2022/c++/FINAL PROJECT/MY PROJECT/3 - REGISTRATION NUMBER, PROPERTY, CASH.txt");
            if (!prop.is_open()) 
            {
                cout << "Can't open 3 - REGISTRATION NUMBER, PROPERTY, CASH.txt!" << endl;
            }
            else
            {
                int i = 0;
                for (int i = 0; i < 10; i++)
                {
                    prop >> array_PROPERTY[i].registration_number;
                    prop >> array_PROPERTY[i].property;
                }

                if (!prop.good())
                {
                    cout << "ERROR of reading  3 - REGISTRATION NUMBER, PROPERTY, CASH.txt!" << endl;
                }
                prop.close();
                e = i; 

                cout << " ���� 3 - REGISTRATION NUMBER, PROPERTY, CASH.txt ��������." << endl;

            }

            // *******������ ����� "4 - INSPECTOR, REGISTRATION NUMBER, MEASURE *******

            i_m.open("D:/POIS 2021-2022/c++/FINAL PROJECT/MY PROJECT/4 - INSPECTOR, REGISTRATION NUMBER, MEASURE.txt");
            if (!i_m.is_open()) 
            {
                cout << "Can't open 4 - INSPECTOR, REGISTRATION NUMBER, MEASURE.txt!" << endl;
            }
            else
            {
                int i = 0;
                for (int i = 0; i < 10; i++)
                {
                    i_m >> array_INSPECTOR_AND_MEASURE[i].registration_number;
                    i_m >> array_INSPECTOR_AND_MEASURE[i].inspector;
                    i_m >> array_INSPECTOR_AND_MEASURE[i].measure;
                }

                if (!i_m.good())
                {
                    cout << "ERROR of reading  4 - INSPECTOR, REGISTRATION NUMBER, MEASURE.txt!" << endl;
                }
                i_m.close();
                f = i;

                cout << " ���� 4 - INSPECTOR, REGISTRATION NUMBER, MEASURE.txt ��������." << endl;

            }

            cout << endl;
            a = 1; b = 1;
            break;

        case '2': 

            cout << endl;

            if (a == 0 || b == 0)
            {
                warning(a, b);
                break;
            }

            cout << " " << "-----------------------------------" << endl;
            cout << " " << "��������, ������� �� ������ �� ������ ������� �� �����: " << endl;
            cout << " " << "1 - REGISTRATION NUMBER, PAYERS, TAXES CODE" << endl;
            cout << " " << "2 - PAYERS, DEBT" << endl;
            cout << " " << "3 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION " << endl;
            cout << " " << "4 - REQUISITES, NUMERATION " << endl;
            cout << " " << "5 - REGISTRATION NUMBER, PROPERTY, CASH " << endl;
            cout << " " << "6 - INSPECTOR, REGISTRATION NUMBER, MEASURE " << endl;
            cout << " " << "7 - ��������� � ������� ���� ��� ��������� ������ ���������. " << endl;
            cout << endl;
            cout << " " << "�������� ������ ����� ����: ";
            cin >> answer_2;
            cout << " " << "-----------------------------------" << endl;

            switch (answer_2)
            {
            case '1':
                // ����� �� ����� ����� "1 - REGISTRATION NUMBER, PAYERS, TAXES CODE"
                cout << endl;
                cout << " " << "������� 1 - REGISTRATION NUMBER, PAYERS, TAXES CODE" << endl; 
                cout << endl;
                cout << setw(5) << "������� �����" << ' ' << setw(20) << "������������ ��/��" << setw(15) << "��� ������" << endl;
                cout << setw(5) << "-------------" << setw(20) << "-------------------" << setw(15) << "----------" << endl;

                for (int i = 0; i < 10; i++) 
                {
                    cout << setw(5) << array_PAYERS_AND_TAXES[i].registration_number
                        << setw(20) << array_PAYERS_AND_TAXES[i].payers
                        << setw(15) << array_PAYERS_AND_TAXES[i].taxes_code << endl;
                }
                cout << endl;

                break;

            case '2':
                // ����� �� ����� ������� 2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION

                cout << endl;
                cout << " " << "������� 1.1 - PAYERS, DEBT" << endl; 
                cout << endl;
                cout << setw(10) << "������������ �����������" << setw(30) << "����� �������������" << endl; 
                cout << setw(10) << "------------------------" << setw(30) << "--------------------" << endl;

                for (int n = 0; n < 10; n++) 
                {
                    cout << setw(10) << array_PAYERS_DEBT[n].payers
                        << setw(30) << array_PAYERS_DEBT[n].debt << endl;

                }
                cout << endl;

                break;

            case '3':
                // ����� �� ����� ������� 1.1 - PAYERS, DEBT

                cout << endl;
                cout << " " << "������� 2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION" << endl;
                cout << endl;
                cout << setw(8) << "��� ������" << setw(14) << "���� ������" << setw(18) << "�������� ������" << ' ' << setw(5) << "���������" << endl;
                cout << setw(8) << "------------" << setw(14) << "-------------------" << setw(15) << "-------------------" << setw(5) << "-------" << endl;

                for (int j = 0; j < 10; j++) 
                {
                    cout << setw(10) << array_TERM_OF_PAYMENT_AND_TAXES_NAME[j].taxes_code
                        << setw(15) << array_TERM_OF_PAYMENT_AND_TAXES_NAME[j].terms
                        << setw(15) << array_TERM_OF_PAYMENT_AND_TAXES_NAME[j].taxes_name
                        << setw(2) << array_TERM_OF_PAYMENT_AND_TAXES_NAME[j].numeration << endl;
                }
                cout << endl;

                break;

            case '4':
                // ����� �� ����� ������� 2.1 - REQUISITES, NUMERATION

                cout << endl;
                cout << " " << "������� 2.1 - REQUISITES, NUMERATION" << endl; 
                cout << endl;
                cout << setw(2) << "���������" << setw(10) << "���������" << endl; 
                cout << setw(2) << "-------" << setw(10) << "----------------------------" << endl;

                for (int b = 0; b < 2; b++) 
                {
                    cout << setw(2) << ' ' << array_REQUISITES[b].numeration
                        << setw(7) << ' ' << array_REQUISITES[b].requisites << endl;
                }
                cout << endl;

                break;

            case '5':
                // ����� �� ����� ������� 3 - REGISTRATION NUMBER, PROPERTY, CASH

                cout << endl;
                cout << " " << "������� 3 - REGISTRATION NUMBER, PROPERTY, CASH" << endl; 
                cout << endl;
                cout << setw(10) << "���" << setw(30) << "�������������" << endl; 
                cout << setw(10) << "--------------" << setw(30) << "-------------------------" << endl;

                for (int c = 0; c < 10; c++) 
                {
                    cout << setw(5) << array_PROPERTY[c].registration_number
                        << setw(25) << array_PROPERTY[c].property << endl;
                }
                cout << endl;

                break;

            case '6':
                // ����� �� ����� ������� 4 - INSPECTOR, REGISTRATION NUMBER, MEASURE

                cout << endl;
                cout << " " << "������� 4 - INSPECTOR, REGISTRATION NUMBER, MEASURE" << endl; 
                cout << endl;
                cout << setw(5) << "���" << setw(21) << "���������" << setw(30) << "�����������" << endl; 
                cout << setw(5) << "------------" << setw(20) << "---------------" << setw(30) << "-------------------------" << endl;

                for (int a = 0; a < 10; a++) 
                {
                    cout << setw(5) << array_INSPECTOR_AND_MEASURE[a].registration_number
                        << setw(15) << array_INSPECTOR_AND_MEASURE[a].inspector
                        << setw(37) << array_INSPECTOR_AND_MEASURE[a].measure << endl;
                }
                cout << endl;

                break;

            case '7':
                
                break;

            default:
              
                cout << " " << "�� ����� ������������ ������, ����������, ���������� ��� ���" << endl;
                cout << endl;
                break;
            }
            break;

        case '3': // 3. ������ ������ �� ���� ��� �����������

            if (a == 0 || b == 0)
            {
                warning(a, b);
                break;
            }


            do
            {
            

                cout << " " << "-----------------------------------" << endl;
                cout << " " << "����� 3. ��� 1. ��������, ��� �� ������ �������: " << endl;
                cout << " " << "1 - ������ ������������ ����������� �� ��� � ��� ������ " << endl;
                cout << " " << "2 - ������ ����� ������������� " << endl;
                cout << " " << "3 - ���������� ������ ���� " << endl;
                cout << " " << "4 - ������ ��������� ��� ������ " << endl;
                cout << " " << "5 - ���������, ����� ������������� �������� �� ��/�� " << endl;
                cout << " " << "6 - ������ � �����������, ������� ����������� ����������� � ��������� ��/�� " << endl;
                cout << " " << "7 - ��������� � ������� ���� ��� ��������� ������ ���������. " << endl;
                cout << endl;
                cout << " " << "�������� ������ ����� ����: ";
                cin >> answer_2;

                switch (answer_2)
                {
                case '1': 
                    int unp;
                    cout << "������� ��� ������� �����, ����� ������ ������������ � ��� ������" << endl;
                    cin >> unp;
                    for (int i = 0; i < 10; i++)
                    {
                        if (unp == array_PAYERS_AND_TAXES[i].registration_number)
                            cout << array_PAYERS_AND_TAXES[i].payers << "   " << array_PAYERS_AND_TAXES[i].taxes_code << endl;
                    } break;

                case '2': 
                    int name;
                    cout << " " << "-----------------------------------" << endl;
                    cout << "������� ��� ��� , ����� ������ ����� �������������" << endl;
                    cin >> name;
                    for (int i = 0; i < 10; i++)
                    {
                        if (name == array_PAYERS_AND_TAXES[i].registration_number)
                            cout << array_PAYERS_DEBT[i].payers << ' ' << array_PAYERS_DEBT[i].debt << endl; 

                    } break;

                case '3': 

                {
                    int i = 0;
                    double pow;
                    double pr = 0.0215;
                    int payer_name;
                    int dni_prosrochki;
                    cout << "������� ��� ���, ����� ������ ����� ������������� � ���������� ������ ����" << endl;
                    cin >> payer_name;
                    cout << "������� ���������� ���� ���������, ����� ���������� ������ ����" << endl;
                    cin >> dni_prosrochki;

                    for (int i = 0; i < 10; i++)
                    {
                        if (payer_name == array_PAYERS_AND_TAXES[i].registration_number)
                            cout << array_PAYERS_DEBT[i].payers << ' ' << array_PAYERS_DEBT[i].debt << endl;
                    }

                    pow = array_PAYERS_DEBT[i].debt * dni_prosrochki * pr;
                    cout << array_PAYERS_DEBT[i].debt << "*" << dni_prosrochki << "*" << pr << "=" << pow << endl;
                }

                break;

                case '4': 
                    int num;
                    cout << " " << "-----------------------------------" << endl;
                    cout << "���� ��� ����� ��������� �������� ������� - ������� 1, ���� ���������������� - 2" << endl;
                    cin >> num;
                    for (int i = 0; i < 2; i++)
                    {
                        if (num == array_REQUISITES[i].numeration)
                            cout << array_REQUISITES[i].requisites << endl;
                    }break;

                case '5': 
                    int property;
                    cout << " " << "-----------------------------------" << endl;
                    cout << "������� �������������, ������� �������� �� ������������. ������� ��� ���." << endl;
                    cin >> property;
                    for (int i = 0; i < 10; i++)
                    {
                        if (property == array_PROPERTY[i].registration_number)
                            cout << array_PROPERTY[i].property << endl;

                    }break;

                case '6': 
                    int measure;
                    cout << " " << "-----------------------------------" << endl;
                    cout << "����� ������ ������ ���������� � ����������� ����������� �� �����������, ������� ���." << endl;
                    cin >> measure;
                    for (int i = 0; i < 10; i++)
                    {
                        if (measure == array_INSPECTOR_AND_MEASURE[i].registration_number)
                            cout << array_INSPECTOR_AND_MEASURE[i].inspector << ' ' << array_INSPECTOR_AND_MEASURE[i].measure << endl;
                    }break;

                case '7': 
                    shutdown();


                default:

                    cout << " " << "�� ����� ������������ ������, ����������, ���������� ��� ���" << endl;
                    cout << endl;
                    break;
                }

                gl_menu = return_to_main_menu(); 

            } while (gl_menu);

            cin.get();
            return 0;
        }

        // ******************* ���� � ������������� ������� ***********************************
        gl_menushka = return_to_main_menu();
        // ���������� ������ ���������
    } while (gl_menushka);
}
void warning(int a, int b)
{
    if ((a == 0) || (b == 0)) 
    {
        cout << endl;
        cout << " " << "��������������: ������� ���� ��� �� �������� ������," << endl;
        cout << " " << "������� �� �� ������� ������� �� �� ����� ��� ����������������." << endl;
        cout << " " << "� ������� ���� �������� �.1, ����� ��������� ������ �� ������." << endl;
        cout << endl;
        return;
    }
}
void shutdown()
{
    cout << " " << "���������� ������ ���������. �������, ��� ����������� ����� ��������!" << endl;
    cout << endl;
    exit(0);
    return;
}

void description()
{
    // �������� ������� 
    cout << " �������� ������  ������� ����, ������ ��2-20��" << endl;
    cout << " ���� ������� - ����������� ��������� ���������" << endl;
    cout << " ��������� ������� ��� ������� �������� 6 ������, � ������� ���������� ��������� ����������: " << endl;
    cout << " ��� �����������, ��� ������������, ������������ �����, ����� �������������, ����� ������, " << endl;
    cout << " ��������� ��� ������ �������, ��� �������� �����������, ��� ��������� �� ������� ����������� " << endl;
    cout << " � ����� ������ ����������� ����������� ����������� �� ��������� ������������� " << endl;
    cout << endl;
    cout << " � ��������� ������������ ����� �����������:" << endl;
    cout << " 1. ������ ������ � ��������� ����� ���������� ������ � ����;" << endl;
    cout << " 2. ������� �� ����� �������;" << endl;
    cout << " 3. ������ ��������� ����������:" << endl;
    cout << " 3.1. ������������ ����������� �� ��� � ��� ������;" << endl;
    cout << " 3.2. ����� �������������;" << endl;
    cout << " 3.3. ���������� ������ ����;" << endl;
    cout << " 3.4. ����� ������ � ������ ������������ ������;" << endl;
    cout << " 3.5. ��������� ��� ������;" << endl;
    cout << " 3.6. ���������, ����� ������������� �������� �� ��/��;" << endl;
    cout << " 3.7. �����������, ������� ����������� ����������� � ��������� ��/��;" << endl;
    cout << endl;
}
int return_to_main_menu()
{
    char answer_return;
    cout << " " << "������� ��������� � ������� ����? Y - ���������, N - ��������� ������ ���������: ";
    cin >> answer_return;

    do 
    {
        if ((answer_return == 'Y') || (answer_return == 'y') || (answer_return == 'N') || (answer_return == 'n')) 
        {
            if ((answer_return == 'N') || (answer_return == 'n'))
            {
                cout << endl;
                cout << " " << "�� ������� ��������� ������ ���������" << endl;
                cout << endl;
                return 0;
            }
        }
        else
        {
            cout << " " << "������ ������������ ������, ���������� ��� ���. Y - ���������, N - ��������� ������ ���������: ";
            cin >> answer_return;
        }

    } while ((answer_return != 'Y') && (answer_return != 'y') && (answer_return != 'N') && (answer_return != 'n')); 
    system("cls");  
    return 1;
}