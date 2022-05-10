#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int Hydro_Vents[1000][1000];

int main()
{
    int x1[500], x2[500], y1[500], y2[500];
    char garbage;
    int input;
    int line = 0;
    ifstream file_name("input_day5.txt");
    while (!file_name.eof())
    {
        file_name >> input;
        x1[line] = input;
        file_name >> garbage >> input;
        y1[line] = input;
        file_name >> garbage >> garbage >> input;
        x2[line] = input;
        file_name >> garbage >> input;
        y2[line] = input;
        line++;
    }

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            Hydro_Vents[i][j] = 0;
        }
    }

    for (int i = 0; i < 500; i++)
    {
        if (x1[i] == x2[i])
        {
            if (y1[i] < y2[i])
            {
                for (int loc = y1[i]; loc <= y2[i]; loc++)
                {
                    Hydro_Vents[x1[i]][loc]++;
                }
            }
            else
            {
                for (int loc = y2[i]; loc <= y1[i]; loc++)
                    Hydro_Vents[x1[i]][loc]++;
            }
        }
        else if (y1[i] == y2[i])
        {
            if (x1[i] < x2[i])
            {
                for (int loc = x1[i]; loc <= x2[i]; loc++)
                    Hydro_Vents[loc][y1[i]]++;
            }
            else
            {
                for (int loc = x2[i]; loc <= x1[i]; loc++)
                    Hydro_Vents[loc][y1[i]]++;
            }
        }
        else if (abs(x2[i] - x1[i]) == abs(y2[i] - y1[i]))
        {
            if (x2[i] > x1[i] && y2[i] > y1[i])
            {
                for (int loc = 0; loc <= x2[i] - x1[i]; loc++)
                    Hydro_Vents[x1[i] + loc][y1[i] + loc]++;
            }
            else if (x2[i] < x1[i] && y2[i] < y1[i])
            {
                for (int loc = 0; loc <= x1[i] - x2[i]; loc++)
                    Hydro_Vents[x1[i] - loc][y1[i] - loc]++;
            }
            else if (x2[i] > x1[i] && y2[i] < y1[i])
            {
                for (int loc = 0; loc <= x2[i] - x1[i]; loc++)
                    Hydro_Vents[x1[i] + loc][y1[i] - loc]++;
            }
            else
            {
                for (int loc = 0; loc <= x1[i] - x2[i]; loc++)
                    Hydro_Vents[x1[i] - loc][y1[i] + loc]++;
            }
        }
    }

    int TotalVents = 0;

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (Hydro_Vents[i][j] > 1)
                TotalVents++;
        }
    }
    cout << TotalVents;
}
