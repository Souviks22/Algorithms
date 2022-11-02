#include <iostream>
using namespace std;

int gcd(int, int);

int main()
{
    int num1{}, num2{};
    cout << "Enter first number - ";
    cin >> num1;
    cout << "Enter second number - ";
    cin >> num2;
    cout << ">> GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;
    return 0;
}

int gcd(int num1, int num2)
{
    if (!num2)
        return num1;
    return gcd(num2, num1 % num2);
}