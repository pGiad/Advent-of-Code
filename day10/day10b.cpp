#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <bits/stdc++.h>

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
    case '(':
        return 1;
    case '[':
        return 2;
    case '{':
        return 3;
    case '<':
        return 4;
    }
    return 0;
}

bool corrupted_line(string input)
{
    stack<char> checker;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{' || input[i] == '<')
            checker.push(input[i]);
        else
        {
            if (input[i] == invert(checker.top()))
            {
                checker.pop();
            }
            else
            {
                while (!checker.empty())
                    checker.pop();
                return true;
            }
        }
    }
    return false;
}

int main()
{
    stack<char> incomplete_checker;
    vector<uint64_t> syntax_error_sum_pLine;
    ifstream file_name("Input_Day10.txt");
    string line_input;
    uint64_t syntax_error_sum = 0;

    while (!file_name.eof())
    {
        file_name >> line_input;
        syntax_error_sum = 0;
        if (!corrupted_line(line_input))
        {
            for (int i = 0; i < line_input.size(); i++)
            {
                if (line_input[i] == '(' || line_input[i] == '[' || line_input[i] == '{' || line_input[i] == '<')
                    incomplete_checker.push(line_input[i]);
                else
                {
                    if (line_input[i] == invert(incomplete_checker.top()))
                    {
                        incomplete_checker.pop();
                    }
                }
            }
            while (!incomplete_checker.empty())
            {
                syntax_error_sum = 5 * syntax_error_sum + exception_code(incomplete_checker.top());
                incomplete_checker.pop();
            }
            syntax_error_sum_pLine.push_back(syntax_error_sum);
        }
    }
    sort(syntax_error_sum_pLine.begin(), syntax_error_sum_pLine.end());
    cout << syntax_error_sum_pLine[syntax_error_sum_pLine.size() / 2] << endl;
}