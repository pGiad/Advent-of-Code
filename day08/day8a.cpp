#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string input;
    vector<string> digits;
    int counter = 0; 
    ifstream file_name("input_day8.txt");
    while (!file_name.eof())
    {
        for(int i = 0; i < 11; i++)  file_name >> input;
        for(int i = 0; i < 4; i++) {
            file_name >> input;
            digits.push_back(input);
        }
    }

    for(int i = 0; i < digits.size(); i++) {
        if(digits[i].size() == 2 || digits[i].size() == 4 || digits[i].size() == 3 || digits[i].size() == 7) counter++;
    }
    cout << counter;
}
