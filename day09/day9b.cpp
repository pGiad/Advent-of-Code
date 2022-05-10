#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int input[102][102];
int visited[102][102];

int flood_fill(int i, int j, int vis[][102], int arr[][102], int &counter)
{
    if (arr[i][j] >= 9 || vis[i][j] == -1)
    {
        return counter;
    }

    vis[i][j] = -1;

    flood_fill(i + 1, j, vis, arr, counter);
    flood_fill(i - 1, j, vis, arr, counter);
    flood_fill(i, j + 1, vis, arr, counter);
    flood_fill(i, j - 1, vis, arr, counter);
    return counter++;
}

int main()
{
    char in;
    int height;
    ifstream file_name("input_day9.txt");
    int risk_level_sum = 0;
    int basin_size = 0;
    vector<int> AllBasin_sizes;

    for (int i = 0; i < 102; i++)
    {
        visited[0][i] = 0;
        visited[i][0] = 0;
        visited[101][i] = 0;
        visited[i][101] = 0;
        input[0][i] = 10;
        input[i][0] = 10;
        input[101][i] = 10;
        input[i][101] = 10;
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            file_name >> in;
            height = in - '0';
            input[i + 1][j + 1] = height;
            visited[i + 1][j + 1] = 0;
        }
    }

    for (int i = 1; i < 101; i++)
    {
        for (int j = 1; j < 101; j++)
        {
            basin_size = 0;
            if (input[i][j] < input[i - 1][j] && input[i][j] < input[i + 1][j] &&
                input[i][j] < input[i][j - 1] && input[i][j] < input[i][j + 1])
            {
                flood_fill(i, j, visited, input, basin_size);
                AllBasin_sizes.push_back(basin_size);
            }
        }
    }

    sort(AllBasin_sizes.begin(), AllBasin_sizes.end());
    int finalresult = 1;
    for (int i = 0; i < 3; i++)
    {
        finalresult *= AllBasin_sizes.back();
        AllBasin_sizes.pop_back();
    }
    cout << finalresult << endl;
}