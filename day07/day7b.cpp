#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int best = 1000000000;

int distance(int d) {
    return d*(d+1)/2;
}

int main()
{
    vector<int> position;
    int input;
    char comma;
    ifstream file_name("input_day7.txt");
    while (!file_name.eof())
    {
        file_name >> input;
        position.push_back(input);
        file_name >> comma;
    }

    sort(position.begin(), position.end());

    for(int i = 0; i < *max_element(position.begin(), position.end()); i++) {
        int total_fuel = 0;
        for(auto j = position.begin(); j < position.end(); j++) {
            int d = abs(*j - i);
            total_fuel += distance(d);
        }
        if(total_fuel < best) best = total_fuel;
    }
    cout << best;
}