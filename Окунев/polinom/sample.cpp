#include <iostream>
#include "polinom.h"

using namespace std;

int TPolinom::p;

int main()
{
	setlocale(LC_ALL, "Russian");
	int p;
	cout << "Введите коэффициент р \n";
	cin >> p;
	TPolinom::setP(p);
    string std;
	cout << "Введите полином \n";
    cin >> std;
    TPolinom polinom(std);
	cout << "Введите полином 2\n";
	cin >> std;
	TPolinom polinom2(std);
	cout << polinom.ToString() << endl;
	cout << polinom2.ToString() << endl;
	TPolinom polinom3;
	polinom3 = polinom + polinom2;
	cout << polinom3.ToString() << endl;
    getchar();
    getchar();
	return 0;
}
