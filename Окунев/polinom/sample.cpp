#include <iostream>
#include "polinom.h"

using namespace std;

int TPolinom::p;

int main()
{
	setlocale(LC_ALL, "Russian");
	int p;
    cout << "Введите максимальную степень полинома\n";
	cin >> p;
	TPolinom::setP(p);
    string std;
	cout << "Введите полином p1\n";
    cin >> std;
    TPolinom polinom(std);
	cout << "Введите полином p2\n";
	cin >> std;
	TPolinom polinom2(std);
    cout << "--------------------------" << endl;
    cout << "Введённые полиномы :" << endl;
	cout << polinom.ToString() << endl;
	cout << polinom2.ToString() << endl;
    //пример арифметических операций
	TPolinom polinom3;
    cout << "--------------------------" << endl;
    cout << "Арифметические операции :" << endl;
    cout << "p1 + p2 " << endl;
	polinom3 = polinom + polinom2;
	cout << polinom3.ToString() << endl;
    cout << "p1 - p2" << endl;
    polinom3 = polinom - polinom2;
    cout << polinom3.ToString() << endl;
    //пример подсчета полинома с указанными значениями
    cout << "--------------------------" << endl;
    cout << "Введите значения x, y, z" << endl;
    double val[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> val[i];
    }
    cout << "Результат :";
    cout << polinom.Calculate(val[0], val[1], val[2]) << endl;
	return 0;
}
