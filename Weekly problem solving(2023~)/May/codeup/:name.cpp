#include <iostream>
#include <string.h>

using namespace std;

int main()
{

    int *arr;
    string input;
    cin >> input;
    int size = input.length();

    arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        if (input[i] == 't')
        {
            arr[i] = i+1;
        }
        else
        {
            arr[i] = 0;
        }
    };

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            cout << arr[i] << ' ';
        }
    };
    cout << '\n';
}