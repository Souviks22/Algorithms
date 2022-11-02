#include <iostream>
using namespace std;

long fibonacci(int);

int main()
{
    int idx{};
    cout << "Enter fibnacci index - ";
    cin >> idx;
    cout << ">> Element no. " << idx << " is " << fibonacci(idx) << endl;
    return 0;
}

long fibonacci(int num)
{
    if (!num)
        return 0;
    else if (num == 1)
        return 1;
    return fibonacci(num - 1) + fibonacci(num - 2);
}