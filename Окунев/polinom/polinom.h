#include <string>
#include <iostream>

using namespace std;

struct TMonom
{
	double coef;
	int degree;
};

struct TLink
{
	TMonom monom;
	TLink* pNext;
};

class  TPolinom
{
private:
	TLink* pFirst;
	static int p;
	void AddMonom(TMonom monom); //добавление монома к списку
	void CreatePolinom(string str); //разбор строки на мономы
	void CreateHead(); //создание "head"
    string MonomToString(TMonom monom);
	void RemoveZeroComponents();
public:
	TPolinom(char* str);
	TPolinom(string str);
	TPolinom(const TPolinom &p);
	TPolinom();
	~TPolinom();
//методы
    void static setP(int P) {
        int i = 0;
        while ( P != 0)
        {
            P /= 10;
            i++;
        }
        p = (int)pow(10, i);
        cout << p;
    }
    double Calculate(double x, double y, double z);
    double CalculateMonom(TMonom monom, double x, double y, double z);
	TPolinom operator+(const TPolinom &p);
	TPolinom operator-(const TPolinom &p);
	TPolinom operator*(double c);
    TPolinom operator=(const TPolinom &p);
	string ToString();
};
