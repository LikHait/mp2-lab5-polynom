#include <iostream>
#include "polinom.h"

using namespace std;

int TPolinom::p;

int main()
{
	setlocale(LC_ALL, "Russian");
	int p;
	cout << "������� ����������� � \n";
	cin >> p;
	TPolinom::setP(p);
    string std;
	cout << "������� ������� p1\n";
    cin >> std;
    TPolinom polinom(std);
	cout << "������� ������� p2\n";
	cin >> std;
	TPolinom polinom2(std);
	cout << polinom.ToString() << endl;
	cout << polinom2.ToString() << endl;
    //������ �������������� ��������
	TPolinom polinom3;
    cout << "p1 + p2 " << endl;
	polinom3 = polinom + polinom2;
	cout << polinom3.ToString() << endl;
    cout << "p1 - p2" << endl;
    polinom3 = polinom - polinom2;
    cout << polinom3.ToString() << endl;
    //������ �������� �������� � ���������� ����������
    double val[3];
    cout << "������� �������� x, y, z" << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> val[i];
    }
    cout << "��������� :";
    cout << polinom.Calculate(val[0], val[1], val[2]) << endl;
	return 0;
}
