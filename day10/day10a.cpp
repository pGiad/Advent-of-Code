#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

char invert(char x)
{
    switch (x)
    {
    case '(':
        return ')';
    case '[':
        return ']';
    case '{':
        return '}';
    case '<':
        return '>';
    }
    return ' ';
}

int exception_code(char x)
{
    switch (x)
    {
    case ')':
        return 3;
    case ']':
        return 57;
    case '}':
        return 1197;
    case '>':
        return 25137;
    }
    return 0;
}

int main()
{
    stack<char> checker;

    ifstream file_name("input_day10.txt");
    string line_input;
    int syntax_error_sum = 0;

    while (!file_name.eof())
    {
        file_name >> line_input;
        for (int i = 0; i < line_input.size(); i++)
        {
            if (line_input[i] == '(' || line_input[i] == '[' || line_input[i] == '{' || line_input[i] == '<')
                checker.push(line_input[i]);
            else
            {
                if (line_input[i] == invert(checker.top()))
                {
                    checker.pop();
                }
                else
                {
                    syntax_error_sum += exception_code(line_input[i]);
                    while (!checker.empty())
                        checker.pop();
                    break;
                }
            }
        }
    }
    cout << syntax_error_sum << endl;
}