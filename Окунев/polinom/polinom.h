#include <string>

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
	static const int p = 10;
	void AddMonom(TMonom monom); //добавление монома к списку
	void CreatePolinom(string str); //разбор строки на мономы
	void CreateHead(); //создание "head"
    string MonomToString(TMonom monom);
	void RemoveZeroComponents();
public:
	TPolinom(char* str);
	TPolinom(string str);
	TPolinom();
	~TPolinom();
//методы
	TPolinom operator+(const TPolinom &p);
	TPolinom operator-(const TPolinom &p);
	TPolinom operator*(float c);
	string ToString();
};

