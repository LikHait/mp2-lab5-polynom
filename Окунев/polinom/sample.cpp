#include <iostream>
#include "polinom.h"

using namespace std;

int main()
{
    string std;
    cin >> std;
    TPolinom polinom(std);
    cout << polinom.ToString();
    getchar();
    getchar();
	return 0;
}
