#include <iostream>
using namespace std;

void add_to_array(int *&, size_t &, size_t, int);
const int delete_from_array(int *&, size_t &, size_t);
void resize(int *&, size_t &, float, size_t);
void print_array(int *, size_t);

int main()
{
    int *arr = new int[1]{};
    size_t Cp{1};
    size_t N{};
    int what_to_do{};
    int input{};
    do
    {
        cout << ">> What you want to do? (push/pop/exit)=>(1/2/0) - ";
        cin >> what_to_do;

        switch (what_to_do)
        {
        case 1:
            cout << "Enter an element to add - ";
            cin >> input;
            add_to_array(arr, Cp, N++, input);
            break;

        case 2:
            if (!N)
                cout << "Array is Empty" << endl;
            else
                cout << delete_from_array(arr, Cp, N--) << " removed" << endl;
            break;

        case 0:
            cout << "Finished" << endl;
            break;

        default:
            cout << "Try Again!" << endl;
            print_array(arr, N);
            break;
        }

    } while (what_to_do);

    return 0;
}

void add_to_array(int *&arr, size_t &capacity, size_t size, int input)
{
    if (size >= capacity)
        resize(arr, capacity, 2, size);
    arr[size] = input;
    print_array(arr, size + 1);
}
const int delete_from_array(int *&arr, size_t &capacity, size_t size)
{
    if (size <= capacity / 4)
        resize(arr, capacity, 1 / 2.0, size);
    const int element = arr[size - 1];
    print_array(arr, size - 1);
    return element;
}
void resize(int *&arr, size_t &capacity, float factor, size_t size)
{
    capacity *= factor;
    int *new_arr = new int[capacity];
    for (size_t i{}; i < size; i++)
        new_arr[i] = arr[i];
    delete[] arr;
    arr = new_arr; // wtf
}
void print_array(int arr[], size_t size)
{
    cout << "[ ";
    for (size_t i{}; i < size; i++)
        cout << arr[i] << " ";
    cout << "]" << endl;
}