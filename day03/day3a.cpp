#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int Gamma_arr[12], Epsilon_arr[12];
    for (int i = 0; i < 12; i++)
    {
        Gamma_arr[i] = 0;
        Epsilon_arr[i] = 0;
    }
    string gamma, epsilon;
    ifstream file_name("input_day3.txt");
    char item_name;

    while (!file_name.eof())
    {
        for (int i = 0; i < 12; i++)
        {
            file_name >> item_name;
            if (item_name == '1')
                Gamma_arr[i]++;
        }
    }

    for (int i = 0; i < 12; i++)
    {
        if (Gamma_arr[i] > 500)
        {
            Gamma_arr[i] = 1;
            Epsilon_arr[i] = 0;
        }
        else
        {
            Gamma_arr[i] = 0;
            Epsilon_arr[i] = 1;
        }
    }

    for (int i : Gamma_arr)
        gamma += to_string(i);

    for (int i : Epsilon_arr)
        epsilon += to_string(i);

    int gamma_dec = 0, epsilon_dec = 0;
    gamma_dec = stoi(gamma, 0, 2);
    epsilon_dec = stoi(epsilon, 0, 2);

    cout << gamma_dec * epsilon_dec;
}