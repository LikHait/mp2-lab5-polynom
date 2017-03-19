#include "polinom.h"

void TPolinom::AddMonom(TMonom monom)
{
    TLink* link = new TLink;
    link->monom = monom;
    if (pFirst == pFirst->pNext)
    {
        link->pNext = pFirst;
        pFirst->pNext = link;
        return;
    }
    TLink* tmp = pFirst ->pNext;
    while (tmp->pNext->monom.degree > monom.degree)
    {
        tmp = tmp->pNext;
    }
	link -> pNext = tmp -> pNext;
	tmp -> pNext = link;
}

void TPolinom::CreateHead()
{
	pFirst = new TLink;
	if (pFirst == nullptr)
        throw("Memory allocation error");
	pFirst ->monom.coef = 0;
	pFirst ->monom.degree = -1;
	pFirst ->pNext = pFirst;
}

void TPolinom::RemoveZeroComponents()
{
	TLink* tmp = pFirst;
	while (tmp -> pNext != pFirst)
	{
		if (tmp -> pNext -> monom.coef == 0)
		{
			TLink* tmpNext= tmp -> pNext -> pNext;
			delete tmp -> pNext;
			tmp -> pNext = tmpNext;
		}
		tmp = tmp -> pNext;
	}
}

void TPolinom::CreatePolinom(string str)
{
	if (str.length() == 0)
		return;
	int i = 0;
	TMonom monom;
	string st;
	for (int i = 0; i < str.length(); i++)
	{
        st.clear();
		monom.coef = 0;
		monom.degree = 0;
        while (str[i] != '+' && str[i] != '-' && i < str.length())
		{
			if (i == 0 || str[i-1] == '+' || str[i-1] == '-')
			{
                while (str[i] != 'x' && str[i] != 'y' && str[i] != 'z' && str[i] != '+' && str[i] != '-' && i < str.length())
				{
					st += str[i];
					i++;
				}
				monom.coef = stod(st);
                st.clear();
			}
			if (str[i] == 'x')
			{
				if (str[++i] == '^')
					i++;
                while (str[i] != 'y' && str[i] != 'z' && str[i] != '+' && str[i] != '-' && i < str.length())
				{
					st += str[i];
					i++;
				}
                if (st != "")
                {
                    monom.degree += p*p*stoi(st);
                    st.clear();
                }
                else monom.degree += p*p*1;
			}
			if (str[i] == 'y')
			{
				if (str[++i] == '^')
					i++;
                while (str[i] != 'z' && str[i] != '+' && str[i] != '-' && i < str.length())
				{
					st += str[i];
					i++;
				}
                if (st != "")
                {
                    monom.degree += p*stoi(st);
                    st.clear();
                }
                else monom.degree += p * 1;
			}
			if (str[i] == 'z')
			{
				if (str[++i] == '^')
					i++;
                while (str[i] != '+' && str[i] != '-' && i < str.length())
				{
					st += str[i];
					i++;
				}
                if (st != "")
                {
                    monom.degree += stoi(st);
                    st.clear();
                }
                else monom.degree += 1;
			}
		}
		AddMonom(monom);
	}
	RemoveZeroComponents();
}

string TPolinom::MonomToString(TMonom monom)
{
    if (monom.coef == 0)
        return "";
    string str;
    if (monom.coef < 0)
    {
        str += "-";
    }
    else
    {
        str += "+";
    }
    str += to_string(monom.coef);
    if (monom.degree / (p * p) != 0)
    {
        str += "x^";
        str += to_string(monom.degree / (p * p));
    }
    if ((monom.degree % (p * p)) / p != 0)
    {
        str += "y^";
        str += to_string((monom.degree % (p * p)) / p);
    }
    if ((monom.degree % (p * p)) % p != 0)
    {
        str += "z^";
        str += to_string((monom.degree % (p * p)) % p);
    }
    return str;
}

string TPolinom::ToString()
{
    if (pFirst == pFirst->pNext)
        return "0";
    TLink* tmp = pFirst->pNext;
    string str;
    while (tmp != pFirst)
    {
        str += MonomToString(tmp->monom);
        tmp = tmp->pNext;
    }
    str.erase(0, 1);
    return str;
}

string TPolinom::MonomToString(TMonom monom)
{
    if (monom.coef == 0)
        return "";
    string str;
    if (monom.coef < 0)
    {
        str += "-";
    }
    else
    {
        str += "+";
    }
    str += to_string(monom.coef);
    if (monom.degree / (p * p) != 0)
    {
        str += "x^";
        str += to_string(monom.degree / (p * p));
    }
    if ((monom.degree % (p * p)) / p != 0)
    {
        str += "y^";
        str += to_string((monom.degree % (p * p)) / p);
    }
    if ((monom.degree % (p * p)) % p != 0)
    {
        str += "z^";
        str += to_string((monom.degree % (p * p)) % p);
    }
    return str;
}

string TPolinom::ToString()
{
    if (pFirst == pFirst->pNext)
        return "0";
    TLink* tmp = pFirst->pNext;
    string str;
    while (tmp != pFirst)
    {
        str += MonomToString(tmp->monom);
        tmp = tmp->pNext;
    }
    str.erase(0, 1);
    return str;
}

TPolinom:: TPolinom(char* str)
{
	CreateHead();
	string st(str);
	CreatePolinom(st);
}
TPolinom:: TPolinom(string str)
{
	CreateHead();
	CreatePolinom(str);
}
TPolinom:: TPolinom()
{
	CreateHead();
}

TPolinom::~TPolinom()
{
    TLink* link = pFirst->pNext;
    TLink* linkN;
    while (link != pFirst)
    {
        linkN = link->pNext;
        delete link;
        link = linkN;    
    }
    delete link;
}
