#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int main()
{
    int a[2000];
    ifstream file("input_day1.txt");
    int count = 0;
    int x;
    while (count < 2000 && file >> x)
        a[count++] = x;

    int counter = 0;
    for (int i = 0; i < 1997; i++)
        if (a[i] < a[i + 3])
            counter++;

    cout << counter;
    return 0;
}