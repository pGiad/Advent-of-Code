#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void flash(int i, int j, int arr[][12], bool flashed[][12])
{

    if (arr[i][j] > 9 && flashed[i][j] == false)
    {

        flashed[i][j] = true;
        if (arr[i - 1][j - 1] <= 9)
            arr[i - 1][j - 1]++;
        if (arr[i - 1][j] <= 9)
            arr[i - 1][j]++;
        if (arr[i - 1][j + 1] <= 9)
            arr[i - 1][j + 1]++;
        if (arr[i][j - 1] <= 9)
            arr[i][j - 1]++;
        if (arr[i][j + 1] <= 9)
            arr[i][j + 1]++;
        if (arr[i + 1][j - 1] <= 9)
            arr[i + 1][j - 1]++;
        if (arr[i + 1][j] <= 9)
            arr[i + 1][j]++;
        if (arr[i + 1][j + 1] <= 9)
            arr[i + 1][j + 1]++;
        flash(i - 1, j - 1, arr, flashed);
        flash(i - 1, j, arr, flashed);
        flash(i - 1, j + 1, arr, flashed);
        flash(i, j - 1, arr, flashed);
        flash(i, j + 1, arr, flashed);
        flash(i + 1, j - 1, arr, flashed);
        flash(i + 1, j, arr, flashed);
        flash(i + 1, j + 1, arr, flashed);

        arr[i][j] = 0;
        return;
    }
    if (flashed[i][j])
        arr[i][j] = 0;
    return;
}

void step(int input[][12], bool flashed[][12])
{
    for (int i = 1; i < 11; i++)
        for (int j = 1; j < 11; j++)
            input[i][j]++;

    for (int i = 1; i < 11; i++)
        for (int j = 1; j < 11; j++)
            flash(i, j, input, flashed);

    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            flashed[i][j] = false;
        }
    }
    return;
}

int main()
{

    int input[12][12];
    bool flashed[12][12];

    char in;
    int energy_level = 0;
    ifstream file_name("input_day11.txt");
    int synchronized_step = 0;

    for (int i = 0; i < 12; i++)
    {
        input[0][i] = 10;
        input[i][0] = 10;
        input[11][i] = 10;
        input[i][11] = 10;
        flashed[0][i] = true;
        flashed[i][0] = true;
        flashed[11][i] = true;
        flashed[i][11] = true;
    }

    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            file_name >> in;
            energy_level = in - '0';
            input[i][j] = energy_level;
            flashed[i][j] = false;
        }
    }

    while (true)
    {
        step(input, flashed);
        bool x = true;
        for (int j = 0; j < 11; j++)
        {
            for (int k = 0; k < 11; k++)
            {
                if (input[j][k] != 0)
                    x = false;
            }
        }
        synchronized_step++;
        if (x)
        {
            cout << synchronized_step << endl;
            break;
        }
    }
}