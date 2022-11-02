#include <iostream>
#include "List.h"
using namespace std;

void menu();
List merge(List &, List &);

int main()
{
    cout << ">> Let's create a head for your list - ";
    int head_val{};
    cin >> head_val;
    List my_list{head_val};

    char what_to_do{};
    int value{};
    size_t index{};
    menu();
    do
    {
        cout << "> Type 'm' for operations" << endl;
        cout << "> Type 'e' for (e)xit" << endl;
        cout << ">> Make your choice - ";
        cin >> what_to_do;

        switch (what_to_do)
        {
        case '1':
        case 'p':
            my_list.print();
            break;

        case '2':
        case 'h':
            cout << ">> Enter a value for inserting at head - ";
            cin >> value;
            my_list.push_front(value);
            break;

        case '3':
        case 'b':
            cout << ">> Enter a value for inserting at back - ";
            cin >> value;
            my_list.push_back(value);
            break;

        case '4':
        case 'i':
            cout << ">> At which index? - ";
            cin >> index;
            cout << ">> Enter a value for inserting - ";
            cin >> value;
            my_list.push(value, index);
            break;

        case '5':
        case 'f':
            cout << ">> Enter a value for searching - ";
            cin >> value;
            cout << "> " << value << " is at position => " << my_list.find(value) << endl;
            break;

        case '6':
        case 'r':
            my_list = my_list.reverse();
            my_list.print();
            break;

        case '7':
        case 'd':
            cout << ">> Enter the index for deletion - ";
            cin >> index;
            my_list.pop(index);
            break;

        case '8':
        case 's':
            my_list = my_list.sort();
            my_list.print();
            break;

        case '9':
        case 'c':
            my_list.clear();
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
    cout << "\t2. (h)ead insert" << endl;
    cout << "\t3. (b)ack insert" << endl;
    cout << "\t4. (i)nsert" << endl;
    cout << "\t5. (f)ind" << endl;
    cout << "\t6. (r)everse" << endl;
    cout << "\t7. (d)elete" << endl;
    cout << "\t8. (s)ort" << endl;
    cout << "\t9. (c)lear" << endl;
}
List merge(List &l1, List &l2)
{
    List merged_list{};
    Node *temp{merged_list.head}, *temp1{l1.head}, *temp2{l2.head};
    while (temp1)
    {
        temp = temp1;
        temp = temp->next;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        temp = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }

    return merged_list;
}
