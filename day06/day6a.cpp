#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
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

    for(int day = 0; day < 80; day++) {
        int newborn = 0;
        for(int i = 0; i < timer.size(); i++) {
            if(timer[i] != 0)
                timer[i]--;
            else {
                timer[i] = 6;
                newborn++;
            }
        }
        for(int i = 0; i <newborn; i++) timer.push_back(8);
    }
    cout << timer.size();
}