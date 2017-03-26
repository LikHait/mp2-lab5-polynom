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
	void static setP(int P) { p = P; }
	TPolinom operator+(const TPolinom &p);
	TPolinom operator-(const TPolinom &p);
	TPolinom operator*(double c);
    TPolinom operator=(const TPolinom &p);
	string ToString();
};
