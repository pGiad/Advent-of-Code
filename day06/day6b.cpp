#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int input;
    char comma;
    vector<int> timer;
    ifstream file_name("input_day6.txt");
    while (!file_name.eof())
    {
        file_name >> input;
        timer.push_back(input);
        file_name >> comma;
    }

    uint64_t state[9];
    for (int i = 0; i < 9; i++)
    {
        state[i] = 0;
    }

    for (int i = 0; i < timer.size(); i++)
    {
        int x = timer[i];
        state[x]++;
    }

    uint64_t newborn = 0;
    uint64_t sum = 0;

    for (int i = 0; i < 256; i++)
    {
        newborn = state[0];
        for (int j = 0; j < 8; j++)
        {
            state[j] = state[j + 1];
        }
        state[8] = newborn;
        state[6] += newborn;
    }

    for (int i = 0; i < 9; i++)
        sum += state[i];
    cout << sum << endl;
}