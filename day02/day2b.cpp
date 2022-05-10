#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int distance = 0;
    int depth = 0;
    int aim = 0;
    string item_name;
    int moves = 0;
    ifstream file_name("input_day2.txt");
    while (file_name >> item_name >> moves)
    {
        if (item_name == "forward")
        {
            depth = depth + aim * moves;
            distance += moves;
        }
        else if (item_name == "down")
            aim += moves;
        else if (item_name == "up")
            aim -= moves;
    }
    cout << distance * depth;
}
