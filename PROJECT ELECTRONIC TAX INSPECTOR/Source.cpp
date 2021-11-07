// ИТОГОВЫЙ ПРОЕКТ МИНТЕЛЬ АННА

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

// ******* Объявляем структуры для таблиц *******

struct PAYERS_AND_TAXES
{
    int registration_number; // унп плательщика
    char payers[30]; // наименование
    int taxes_code; // код налога
};

struct PAYERS_DEBT
{
    char payers[30]; // наименование
    int debt; // сумма задолженности
};

struct TERM_OF_PAYMENT_AND_TAXES_NAME
{
    int taxes_code; // код налога
    string terms; // сроки оплаты
    char taxes_name[20]; // название налога
    int numeration; // немерация для реквизитов
};

struct REQUISITES
{
    int numeration; // нумерация
    char requisites[150]; // соответствующие реквизиты
};

struct PROPERTY
{
    int registration_number; // унп
    char property[50]; // что есть в собственности
};

struct  INSPECTOR_AND_MEASURE
{
    int registration_number; // унп
    char inspector[12]; // инспектор
    string measure; // проведенные административные мероприятия
};


// ******* Окончание объявления структур для таблиц *******


// ******* Блок прототипов функций *******
void description(); // описание проекта
void warning(int a, int b); // для проверки, если в таблице какая-то строка = 0
int return_to_main_menu(); // возврат в главное меню
void shutdown(); // для завершения программы

// ******* Окончание блока прототипов функций *******

int main()
{
    setlocale(LC_ALL, "Russian_Russia.1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, ".1251");
    setlocale(LC_ALL, "Russian");

    // ******* Объявление переменных, массивов, указателей и пр. *******

    // переменные для получения ответа от пользователя, сразу объявляем и инициализируем, чтобы не появлялось ошибок, связанных с использованием неинициализированных переменных
    char answer_1 = 0; // объявляем переменную для получения ответа от пользователя 
    char answer_2 = 0; // еще одна переменная, чтобы принимать ответ пользователя
    char answer_3 = 0; // еще одна переменная, чтобы принимать ответ пользователя


    // массивы для хранения данных из таблиц

    PAYERS_AND_TAXES array_PAYERS_AND_TAXES[10]; // создаем массив для 10 строк (таблица 1 - REGISTRATION NUMBER, PAYERS, TAXES CODE)
    PAYERS_DEBT array_PAYERS_DEBT[10]; // создаем массив для 10 строк (таблица 1.1 - PAYERS, DEBT)
    TERM_OF_PAYMENT_AND_TAXES_NAME array_TERM_OF_PAYMENT_AND_TAXES_NAME[10]; // создаем массив для 10 строк (таблица 2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION)
    REQUISITES array_REQUISITES[2]; // создаем массив для 2 строк (таблица 2.1 - REQUISITES, NUMERATION)
    PROPERTY array_PROPERTY[10]; // создаем массив для 10 строк (таблица 3 - REGISTRATION NUMBER, PROPERTY, CASH)
    INSPECTOR_AND_MEASURE array_INSPECTOR_AND_MEASURE[10]; // создаем массив для 10 строк (таблица 4 - INSPECTOR, REGISTRATION NUMBER, MEASURE)

    PAYERS_AND_TAXES* p_array_PAYERS_AND_TAXES = array_PAYERS_AND_TAXES; // объявляем указатель и инициализируем ссылкой на 1ый элемент массива array_PAYERS_AND_TAXES
    PAYERS_DEBT* p_array_PAYERS_DEBT = array_PAYERS_DEBT; // объявляем указатель и инициализируем ссылкой на 1ый элемент массива array_PAYERS_DEBT
    TERM_OF_PAYMENT_AND_TAXES_NAME* p_array_TERM_OF_PAYMENT_AND_TAXES_NAME = array_TERM_OF_PAYMENT_AND_TAXES_NAME; // объявляем указатель и инициализируем ссылкой на 1ый элемент массива array_TERM_OF_PAYMENT_AND_TAXES_NAME
    REQUISITES* p_array_REQUISITES = array_REQUISITES; // объявляем указатель и инициализируем ссылкой на 1ый элемент массива array_REQUISITES
    PROPERTY* p_array_PROPERTY = array_PROPERTY;  // объявляем указатель и инициализируем ссылкой на 1ый элемент массива array_PROPERTY
    INSPECTOR_AND_MEASURE* p_array_INSPECTOR_AND_MEASURE = array_INSPECTOR_AND_MEASURE; // объявляем указатель и инициализируем ссылкой на 1ый элемент массива array_INSPECTOR_AND_MEASURE

    ifstream p_t; // создаем экземпляр потока с именем p_t для считывания данных из таблицы 1 - REGISTRATION NUMBER, PAYERS, TAXES CODE
    ifstream p_d; // создаем экземпляр потока с именем p_d для считывания данных из таблицы 1.1 - PAYERS, DEBT
    ifstream t_p_t_n; // создаем экземпляр потока с именем t_p_t_n для считывания данных из таблицы 2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION
    ifstream req; // создаем экземпляр потока с именем req для считывания данных из таблицы 1.1 - PAYERS, 2.1 - REQUISITES, NUMERATION
    ifstream prop; // создаем экземпляр потока с именем prop для считывания данных из таблицы 3 - REGISTRATION NUMBER, PROPERTY, CASH
    ifstream i_m; // создаем экземпляр потока с именем p_d для считывания данных из таблицы 4 - INSPECTOR, REGISTRATION NUMBER, MEASURE

    int a = 0; // объявляем переменную, которая будет использоваться для подсчета количества заполненных строк в таблице 1
    int b = 0; // объявляем переменную, которая будет использоваться для подсчета количества заполненных строк в таблице 1.1
    int c = 0; // объявляем переменную, которая будет использоваться для подсчета количества заполненных строк в таблице 2
    int d = 0; // объявляем переменную, которая будет использоваться для подсчета количества заполненных строк в таблице 2.2
    int e = 0; // объявляем переменную, которая будет использоваться для подсчета количества заполненных строк в таблице 3
    int f = 0; // объявляем переменную, которая будет использоваться для подсчета количества заполненных строк в таблице 4
    int gl_menu;
    int gl_menushka;
    // ******* Окончание блока объявления переменных, массивов, указателеи и пр. *******


    description(); // Вывод описания проекта

    system("pause");
    system("cls");  // Очистка содержимого экран

    // Главное меню программы
    do
    {
        warning(a, b);

        cout << " " << "-----------------------------------" << endl;
        cout << " " << "Меню программы: " << endl;
        cout << " " << "1 - Прочитать файлы. " << endl;
        cout << " " << "2 - Вывести данные таблиц на экран. " << endl;
        cout << " " << "3 - Анализировать данные. " << endl;
        cout << " " << "4 - Завершить работу программы. " << endl;
        cout << endl;
        cout << "Ваш выбор -  ";
        cin >> answer_1;


        switch (answer_1)
        {
        case '1': // 1. Чтение файлов 

            cout << endl;

            // ******* 1. Чтение файла "1 - REGISTRATION NUMBER, PAYERS, TAXES CODE" *******

            p_t.open("D:/POIS 2021-2022/c++/FINAL PROJECT/MY PROJECT/1 - REGISTRATION NUMBER, PAYERS, TAXES CODE.txt");
            if (!p_t.is_open()) // проверка на то, открылся ли файл, если не открылся - сообщение об ошибке
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
                a = i; // Присваиваем счетчику количество считанных строк

                cout << " Файл 1 - REGISTRATION NUMBER, PAYERS, TAXES CODE прочитан.txt." << endl;

            }

            // *******1.1 Чтение файла "1.1 - PAYERS, DEBT" *******

            p_d.open("D:/POIS 2021-2022/c++/FINAL PROJECT/MY PROJECT/1.1 - PAYERS, DEBT.txt");
            if (!p_d.is_open()) // проверка на то, открылся ли файл, если не открылся - сообщение об ошибке
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
                b = i; // Присваиваем счетчику количество считанных строк

                cout << " Файл 1.1 - PAYERS, DEBT.txt прочитан." << endl;

            }

            // *******2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION *******

            t_p_t_n.open("D:/POIS 2021-2022/c++/FINAL PROJECT/MY PROJECT/2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION.txt");
            if (!t_p_t_n.is_open()) // проверка на то, открылся ли файл, если не открылся - сообщение об ошибке
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
                c = i; // Присваиваем счетчику количество считанных строк

                cout << " Файл 2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION.txt прочитан." << endl;

            }

            // *******1.1 Чтение файла "2.1 - REQUISITES, NUMERATION" *******

            req.open("D:/POIS 2021-2022/c++/FINAL PROJECT/MY PROJECT/2.1 - REQUISITES, NUMERATION.txt");
            if (!req.is_open()) // проверка на то, открылся ли файл, если не открылся - сообщение об ошибке
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
                d = i; // Присваиваем счетчику количество считанных строк

                cout << " Файл 2.1 - REQUISITES, NUMERATION.txt прочитан." << endl;
            }

            // ******* Чтение файла 3 - REGISTRATION NUMBER, PROPERTY, CASH *******

            prop.open("D:/POIS 2021-2022/c++/FINAL PROJECT/MY PROJECT/3 - REGISTRATION NUMBER, PROPERTY, CASH.txt");
            if (!prop.is_open()) // проверка на то, открылся ли файл, если не открылся - сообщение об ошибке
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
                e = i; // Присваиваем счетчику количество считанных строк

                cout << " Файл 3 - REGISTRATION NUMBER, PROPERTY, CASH.txt прочитан." << endl;

            }

            // *******Чтение файла "4 - INSPECTOR, REGISTRATION NUMBER, MEASURE *******

            i_m.open("D:/POIS 2021-2022/c++/FINAL PROJECT/MY PROJECT/4 - INSPECTOR, REGISTRATION NUMBER, MEASURE.txt");
            if (!i_m.is_open()) // проверка на то, открылся ли файл, если не открылся - сообщение об ошибке
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
                f = i; // Присваиваем счетчику количество считанных строк

                cout << " Файл 4 - INSPECTOR, REGISTRATION NUMBER, MEASURE.txt прочитан." << endl;

            }

            cout << endl;
            a = 1; b = 1;
            break;

        case '2': // 2. Вывод на таблиц экран

            cout << endl;

            if (a == 0 || b == 0)// Вызов предупреждения о том, что таблицы пустые
            {
                warning(a, b);
                break;
            }

            // Меню выбора, которую из таблиц необходимо вывести на экран
            cout << " " << "-----------------------------------" << endl;
            cout << " " << "Выберите, которую из таблиц вы хотите вывести на экран: " << endl;
            cout << " " << "1 - REGISTRATION NUMBER, PAYERS, TAXES CODE" << endl;
            cout << " " << "2 - PAYERS, DEBT" << endl;
            cout << " " << "3 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION " << endl;
            cout << " " << "4 - REQUISITES, NUMERATION " << endl;
            cout << " " << "5 - REGISTRATION NUMBER, PROPERTY, CASH " << endl;
            cout << " " << "6 - INSPECTOR, REGISTRATION NUMBER, MEASURE " << endl;
            cout << " " << "7 - Вернуться в главное меню или завершить работу программы. " << endl;
            cout << endl;
            cout << " " << "Выберите нужный пункт меню: ";
            cin >> answer_2;
            cout << " " << "-----------------------------------" << endl;

            switch (answer_2)
            {
            case '1':
                // Вывод на экран файла "1 - REGISTRATION NUMBER, PAYERS, TAXES CODE"
                cout << endl;
                cout << " " << "Таблица 1 - REGISTRATION NUMBER, PAYERS, TAXES CODE" << endl; // назввание таблицы
                cout << endl;
                cout << setw(5) << "Учетный номер" << ' ' << setw(20) << "Наименование ЮЛ/ИП" << setw(15) << "Код налога" << endl; // заголовки столбцов
                cout << setw(5) << "-------------" << setw(20) << "-------------------" << setw(15) << "----------" << endl;

                for (int i = 0; i < 10; i++) // выводим данные файла, считанные в массив, на экран
                {
                    cout << setw(5) << array_PAYERS_AND_TAXES[i].registration_number
                        << setw(20) << array_PAYERS_AND_TAXES[i].payers
                        << setw(15) << array_PAYERS_AND_TAXES[i].taxes_code << endl;
                }
                cout << endl;

                break;

            case '2':
                // Вывод на экран таблицы 2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION

                cout << endl;
                cout << " " << "Таблица 1.1 - PAYERS, DEBT" << endl; // назввание таблицы
                cout << endl;
                cout << setw(10) << "Наименование плательщика" << setw(30) << "Сумма задолженности" << endl; // заголовки столбцов
                cout << setw(10) << "------------------------" << setw(30) << "--------------------" << endl;

                for (int n = 0; n < 10; n++) // выводим данные файла, считанные в массив, на экран
                {
                    cout << setw(10) << array_PAYERS_DEBT[n].payers
                        << setw(30) << array_PAYERS_DEBT[n].debt << endl;

                }
                cout << endl;

                break;

            case '3':
                // Вывод на экран таблицы 1.1 - PAYERS, DEBT

                cout << endl;
                cout << " " << "Таблица 2 - TAXES CODE, TERM OF PAYMENT, TAXES NAME, NUMERATION" << endl; // назввание таблицы
                cout << endl;
                cout << setw(8) << "Код налога" << setw(14) << "Срок уплаты" << setw(18) << "Название налога" << ' ' << setw(5) << "Нумерация" << endl; // заголовки столбцов
                cout << setw(8) << "------------" << setw(14) << "-------------------" << setw(15) << "-------------------" << setw(5) << "-------" << endl;

                for (int j = 0; j < 10; j++) // выводим данные файла, считанные в массив, на экран
                {
                    cout << setw(10) << array_TERM_OF_PAYMENT_AND_TAXES_NAME[j].taxes_code
                        << setw(15) << array_TERM_OF_PAYMENT_AND_TAXES_NAME[j].terms
                        << setw(15) << array_TERM_OF_PAYMENT_AND_TAXES_NAME[j].taxes_name
                        << setw(2) << array_TERM_OF_PAYMENT_AND_TAXES_NAME[j].numeration << endl;
                }
                cout << endl;

                break;

            case '4':
                // Вывод на экран таблицы 2.1 - REQUISITES, NUMERATION

                cout << endl;
                cout << " " << "Таблица 2.1 - REQUISITES, NUMERATION" << endl; // назввание таблицы
                cout << endl;
                cout << setw(2) << "Нумерация" << setw(10) << "Реквизиты" << endl; // заголовки столбцов
                cout << setw(2) << "-------" << setw(10) << "----------------------------" << endl;

                for (int b = 0; b < 2; b++) // выводим данные файла, считанные в массив, на экран
                {
                    cout << setw(2) << ' ' << array_REQUISITES[b].numeration
                        << setw(7) << ' ' << array_REQUISITES[b].requisites << endl;
                }
                cout << endl;

                break;

            case '5':
                // Вывод на экран таблицы 3 - REGISTRATION NUMBER, PROPERTY, CASH

                cout << endl;
                cout << " " << "Таблица 3 - REGISTRATION NUMBER, PROPERTY, CASH" << endl; // назввание таблицы
                cout << endl;
                cout << setw(10) << "УНП" << setw(30) << "Собственность" << endl; // заголовки столбцов
                cout << setw(10) << "--------------" << setw(30) << "-------------------------" << endl;

                for (int c = 0; c < 10; c++) // выводим данные файла, считанные в массив, на экран
                {
                    cout << setw(5) << array_PROPERTY[c].registration_number
                        << setw(25) << array_PROPERTY[c].property << endl;
                }
                cout << endl;

                break;

            case '6':
                // Вывод на экран таблицы 4 - INSPECTOR, REGISTRATION NUMBER, MEASURE

                cout << endl;
                cout << " " << "Таблица 4 - INSPECTOR, REGISTRATION NUMBER, MEASURE" << endl; // назввание таблицы
                cout << endl;
                cout << setw(5) << "УНП" << setw(21) << "Инспектор" << setw(30) << "Мероприятие" << endl; // заголовки столбцов
                cout << setw(5) << "------------" << setw(20) << "---------------" << setw(30) << "-------------------------" << endl;

                for (int a = 0; a < 10; a++) // выводим данные файла, считанные в массив, на экран
                {
                    cout << setw(5) << array_INSPECTOR_AND_MEASURE[a].registration_number
                        << setw(15) << array_INSPECTOR_AND_MEASURE[a].inspector
                        << setw(37) << array_INSPECTOR_AND_MEASURE[a].measure << endl;
                }
                cout << endl;

                break;

            case '7':
                // 7. Возврат в главное меню (выход из условной конструкции)
                break;

            default:
                // Cообщение, что номер пункта меню введен неверно, попробуйте еще раз и вернуть пользователя в меню выбора таблицы
                cout << " " << "Вы ввели некорректный символ, пожалуйста, попробуйте еще раз" << endl;
                cout << endl;
                break;
            }
            break;

        case '3': // 3. Анализ таблиц по меню для плательщика

            if (a == 0 || b == 0)// Вызов предупреждения о том, что таблицы пустые
            {
                warning(a, b);
                break;
            }

            // Меню 3 пункта (анализирование данных)
            do
            {
                // Меню выбора направления анализа таблиц для п. 3. главного меню (шаг 1)

                cout << " " << "-----------------------------------" << endl;
                cout << " " << "Пункт 3. Шаг 1. Выберите, что вы хотите сделать: " << endl;
                cout << " " << "1 - Узнать наименование плательщика по УНП и код налога " << endl;
                cout << " " << "2 - Узнать сумму задолженности " << endl;
                cout << " " << "3 - Произвести расчет пени " << endl;
                cout << " " << "4 - Узнать реквизиты для оплаты " << endl;
                cout << " " << "5 - Проверить, какая собственность числится за ЮЛ/ИП " << endl;
                cout << " " << "6 - Узнать о мероприятих, которые проводились инспектором в отношении ЮЛ/ИП " << endl;
                cout << " " << "7 - Вернуться в главное меню или завершить работу программы. " << endl;
                cout << endl;
                cout << " " << "Выберите нужный пункт меню: ";
                cin >> answer_2;

                switch (answer_2)
                {
                case '1': // Анализ по наименованию плательщика и коду налога
                    int unp;
                    cout << "Введите Ваш учетный номер, чтобы узнать наименование и код налога" << endl;
                    cin >> unp;
                    for (int i = 0; i < 10; i++)
                    {
                        if (unp == array_PAYERS_AND_TAXES[i].registration_number)
                            cout << array_PAYERS_AND_TAXES[i].payers << "   " << array_PAYERS_AND_TAXES[i].taxes_code << endl;
                    } break;

                case '2': // Анализ по сумме задолженности
                    int name;
                    cout << " " << "-----------------------------------" << endl;
                    cout << "Введите Ваш УНП , чтобы узнать сумму задолженности" << endl;
                    cin >> name;
                    for (int i = 0; i < 10; i++)
                    {
                        if (name == array_PAYERS_AND_TAXES[i].registration_number)
                            cout << array_PAYERS_DEBT[i].payers << ' ' << array_PAYERS_DEBT[i].debt << endl; // берем данные из двух таблиц

                    } break;

                case '3': // Расчет суммы пени

                {
                    int i = 0;
                    double pow;
                    double pr = 0.0215;
                    int payer_name;
                    int dni_prosrochki;
                    cout << "Введите Ваш УНП, чтобы узнать сумму задолженности и произвести расчет пени" << endl;
                    cin >> payer_name;
                    cout << "Введите количество дней просрочки, чтобы произвести расчет пени" << endl;
                    cin >> dni_prosrochki;

                    for (int i = 0; i < 10; i++)
                    {
                        if (payer_name == array_PAYERS_AND_TAXES[i].registration_number)
                            cout << array_PAYERS_DEBT[i].payers << ' ' << array_PAYERS_DEBT[i].debt << endl; // берем данные из двух таблиц
                    }

                    pow = array_PAYERS_DEBT[i].debt * dni_prosrochki * pr;
                    cout << array_PAYERS_DEBT[i].debt << "*" << dni_prosrochki << "*" << pr << "=" << pow << endl;
                }

                break;

                case '4': //  Узнаем реквизиты для оплаты
                    int num;
                    cout << " " << "-----------------------------------" << endl;
                    cout << "Если вам нужны реквизиты местного бюджета - нажмите 1, если республиканского - 2" << endl;
                    cin >> num;
                    for (int i = 0; i < 2; i++)
                    {
                        if (num == array_REQUISITES[i].numeration)
                            cout << array_REQUISITES[i].requisites << endl;
                    }break;

                case '5': //  Анализ собственности, которая числится за ЮЛ/ИП
                    int property;
                    cout << " " << "-----------------------------------" << endl;
                    cout << "Наличие собственности, которая числится из плательщиком. Введите ваш УНП." << endl;
                    cin >> property;
                    for (int i = 0; i < 10; i++)
                    {
                        if (property == array_PROPERTY[i].registration_number)
                            cout << array_PROPERTY[i].property << endl;

                    }break;

                case '6': // Узнать о мероприятих, которые проводились инспектором в отношении ЮЛ/ИП
                    int measure;
                    cout << " " << "-----------------------------------" << endl;
                    cout << "Чтобы узнать вашего инспектора и просмотреть выполненные им мероприятия, введите УНП." << endl;
                    cin >> measure;
                    for (int i = 0; i < 10; i++)
                    {
                        if (measure == array_INSPECTOR_AND_MEASURE[i].registration_number)
                            cout << array_INSPECTOR_AND_MEASURE[i].inspector << ' ' << array_INSPECTOR_AND_MEASURE[i].measure << endl;
                    }break;

                case '7': // Eсли выбран вариант  "Завершить работу программы"
                    shutdown();


                default:
                    // Cообщение, что номер пункта меню введен неверно, попробуйте еще раз и вернуть пользователя в меню
                    cout << " " << "Вы ввели некорректный символ, пожалуйста, попробуйте еще раз" << endl;
                    cout << endl;
                    break;
                }

                gl_menu = return_to_main_menu(); // функция с вопросом, следует ли вернуться в меню или завершить работу программы

            } while (gl_menu);

            cin.get();
            return 0;
        }

        // ******************* Блок с определениями функций ***********************************
        gl_menushka = return_to_main_menu();
        // Завершение работы программы
    } while (gl_menushka);
}
void warning(int a, int b)
{
    if ((a == 0) || (b == 0)) // проверка условия "если строки какого-либо из массивов с базами данных равны нулю" 
    {
        cout << endl;
        cout << " " << "ПРЕДУПРЕЖДЕНИЕ: таблицы пока что не содержат данных," << endl;
        cout << " " << "поэтому вы не сможете вывести их на экран или проанализировать." << endl;
        cout << " " << "В главном меню выберите п.1, чтобы прочитать данные из файлов." << endl;
        cout << endl;
        return;
    }
}
void shutdown()
{
    cout << " " << "Завершение работы программы. Спасибо, что пользуетесь нашим сервисом!" << endl;
    cout << endl;
    exit(0);
    return;
}

void description()
{
    // Описание проекта 
    cout << " Итоговый проект  Минтель Анна, группа Пв2-20ПО" << endl;
    cout << " Тема проекта - Электронный налоговый инспектор" << endl;
    cout << " Исходными данными для проекта являются 6 таблиц, в которых содержится следующая информация: " << endl;
    cout << " УНП плательцика, его наименование, уплачиваемын налог, сумма задолженности, сроки оплаты, " << endl;
    cout << " реквизиты для оплаты налогов, кто является инспектором, что находится на балансе организации " << endl;
    cout << " а также список проведенных инспектором мероприятий по погашению задолженности " << endl;
    cout << endl;
    cout << " В программе пользователь имеет возможность:" << endl;
    cout << " 1. ввести данные в программу путем считывания таблиц в файл;" << endl;
    cout << " 2. вывести на экран таблицы;" << endl;
    cout << " 3. узнать следующую информацию:" << endl;
    cout << " 3.1. наименование плательщика по УНП и код налога;" << endl;
    cout << " 3.2. сумму задолженности;" << endl;
    cout << " 3.3. произвести расчет пени;" << endl;
    cout << " 3.4. сроки оплаты и полное наименование налога;" << endl;
    cout << " 3.5. реквизиты для оплаты;" << endl;
    cout << " 3.6. проверить, какая собственность числится за ЮЛ/ИП;" << endl;
    cout << " 3.7. мероприятия, которые проводились инспектором в отношении ЮЛ/ИП;" << endl;
    cout << endl;
}
int return_to_main_menu()
{
    char answer_return;
    cout << " " << "Желаете вернуться в главное меню? Y - вернуться, N - завершить работу программы: ";
    cin >> answer_return;

    do // цикл, который выполняет проверку корректности введенных символов, если корректные, выход из программы или возврат в сеню, если некорректные, повторный запрос
    // так как сначала в конструкции идет do, а потом проверка условия, то цикл выполняется по меньшей мере один раз (в случае, если символ введен корректно)
    {
        if ((answer_return == 'Y') || (answer_return == 'y') || (answer_return == 'N') || (answer_return == 'n')) // проверка, введены ли корректные символы
        {
            if ((answer_return == 'N') || (answer_return == 'n'))
            {
                cout << endl;
                cout << " " << "Вы выбрали завершить работу программы" << endl;
                cout << endl;
                return 0;
            }
        }
        else
        {
            cout << " " << "Введен некорректный символ, попробуйте еще раз. Y - вернуться, N - завершить работу программы: ";
            cin >> answer_return;
        }

    } while ((answer_return != 'Y') && (answer_return != 'y') && (answer_return != 'N') && (answer_return != 'n')); // цикл повторется, пока введенный символ не равен Y, y, N, n
    system("cls");  // Очистка содержимого экран
    return 1;
}