#include <iostream>
#include "Stack.h"
using namespace std;

void menu();

int main()
{
    cout << ">> Let's create a head for your Stack - ";
    int head_val{};
    cin >> head_val;
    Stack my_stack{head_val};

    char what_to_do{};
    int value{};
    menu();
    do
    {
        cout << "\n> Type 'm' for operations" << endl;
        cout << "> Type 'e' for (e)xit" << endl;
        cout << ">> Make your choice - ";
        cin >> what_to_do;

        switch (what_to_do)
        {
        case '1':
        case 'p':
            my_stack.print();
            break;

        case '2':
        case 'i':
            cout << ">> Enter a value for inserting - ";
            cin >> value;
            my_stack.push(value);
            break;

        case '3':
        case 'd':
            my_stack.pop();
            break;

        case '4':
        case 't':
            cout << ">> " << my_stack.top() << " is at top right now" << endl;
            break;

        case 'm':
            menu();
            break;
        case 'e':
            cout << ">> Finished" << endl;
            break;

        default:
            cout << ">> Try Again!" << endl;
        }

    } while (what_to_do != 'e');
    return 0;
}

void menu()
{
    cout << ">> What you want to do?" << endl;
    cout << "\t1. (p)rint" << endl;
    cout << "\t2. (i)nsert" << endl;
    cout << "\t3. (d)elete" << endl;
    cout << "\t4. (t)op" << endl;
}