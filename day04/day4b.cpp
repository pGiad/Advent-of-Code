#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream file_name("input_day4_numbers.txt");
    ifstream file_name2("input_day4_bingo.txt");

    vector<int> bingo_input;
    char comma;
    int bingo_num;

    while (!file_name.eof())
    {
        file_name >> bingo_num;
        bingo_input.push_back(bingo_num);
        file_name >> comma;
    }

    int bingo[100][5][5];
    int bingo_tab;
    int bingo_checker[100][6][6];
    int winner[5][5];
    int win_sum = 0, result = 0;
    int winner_boards = 0;
    bool winner_boards_bool[100];
    bool win = false;

    for (int i = 0; i < 100; i++)
    {
        winner_boards_bool[i] = false;
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                bingo_checker[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                file_name2 >> bingo_tab;
                bingo[i][j][k] = bingo_tab;
            }
        }
    }

    for (auto in = bingo_input.begin(); in < bingo_input.end(); in++)
    {
        for (int i = 0; i < 100; i++)
        {
            if (winner_boards_bool[i] == false)
            {
                for (int j = 0; j < 5; j++)
                {
                    for (int k = 0; k < 5; k++)
                    {
                        if (bingo[i][j][k] == *in)
                        {
                            bingo_checker[i][j][k] = 1;
                            bingo_checker[i][j][5]++;
                            bingo_checker[i][5][k]++;
                        }
                        if (bingo_checker[i][j][5] == 5 || bingo_checker[i][5][k] == 5)
                        {
                            if (winner_boards_bool[i] == false)
                            {
                                winner_boards_bool[i] = true;
                                winner_boards++;
                                if (winner_boards == 100)
                                {
                                    for (int ia = 0; ia < 5; ia++)
                                    {
                                        for (int ja = 0; ja < 5; ja++)
                                        {
                                            //winner[ia][ja] = bingo[i][ia][ja];
                                            //cout << winner[ia][ja] << " ";
                                            if (bingo_checker[i][ia][ja] == 0)
                                                win_sum += bingo[i][ia][ja];
                                        }
                                    }
                                    cout << win_sum * (*in) << endl;
                                    win = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            if (win == true)
                break;
        }
        if (win == true)
            break;
    }
}