#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;


int main() {
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

    for(auto i = position.begin(); i < position.end(); i++) cout << *i << " ";
    cout << endl;

    int target_position = position.at(position.size()/2);

    cout << target_position << endl;

    int fuel = 0;

    for(auto i = position.begin(); i < position.end(); i++)
    fuel = fuel + abs(*i - target_position);

    cout << fuel;
}