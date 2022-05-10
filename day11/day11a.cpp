#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void flash(int i, int j, int arr[][12], bool flashed[][12], int &total_flashes)
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
        flash(i - 1, j - 1, arr, flashed, total_flashes);
        flash(i - 1, j, arr, flashed, total_flashes);
        flash(i - 1, j + 1, arr, flashed, total_flashes);
        flash(i, j - 1, arr, flashed, total_flashes);
        flash(i, j + 1, arr, flashed, total_flashes);
        flash(i + 1, j - 1, arr, flashed, total_flashes);
        flash(i + 1, j, arr, flashed, total_flashes);
        flash(i + 1, j + 1, arr, flashed, total_flashes);

        arr[i][j] = 0;
        total_flashes++;
        return;
    }
    if (flashed[i][j])
        arr[i][j] = 0;
    return;
}

void step(int input[][12], bool flashed[][12], int &total_flashes)
{
    for (int i = 1; i < 11; i++)
        for (int j = 1; j < 11; j++)
            input[i][j]++;

    for (int i = 1; i < 11; i++)
        for (int j = 1; j < 11; j++)
            flash(i, j, input, flashed, total_flashes);

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
    int energy_level;
    ifstream file_name("input_day11.txt");
    int total_flashes = 0;

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

    for (int i = 0; i < 100; i++)
        step(input, flashed, total_flashes);

    cout << total_flashes << endl;

    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}