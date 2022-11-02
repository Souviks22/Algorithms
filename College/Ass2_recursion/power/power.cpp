#include <iostream>
using namespace std;

long power(int, int);

int main()
{
    int base{}, exponent{};
    cout << "Enter base - ";
    cin >> base;
    cout << "Enter exponent - ";
    cin >> exponent;
    cout << ">> " << base << "^" << exponent << " = " << power(base, exponent) << endl;
    return 0;
}

long power(int base, int exponent)
{
    if (!exponent)
        return 1;
    return base * power(base, exponent - 1);
}
