#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    char input_char;
    int input, position[102][102];
    int result = 0;

    for (int i = 0; i < 102; i++)
    {
        for (int j = 0; j < 102; j++)
            position[i][j] = 10;
    }

    ifstream file_name("input_day9.txt");
    for (int i = 1; i < 101; i++)
    {
        for (int j = 1; j < 101; j++)
        {
            file_name >> input_char;
            input = input_char - '0';
            position[i][j] = input;
        }
    }

    for (int i = 1; i < 101; i++)
    {
        for (int j = 1; j < 101; j++)
        {
            cout << position[i][j];
            if (position[i][j] < position[i - 1][j] && position[i][j] < position[i + 1][j] && position[i][j] < position[i][j - 1] && position[i][j] < position[i][j + 1])
                result = result + 1 + position[i][j];
        }
        cout << endl;
    }
    cout << result;
}