#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
    bool check_arr[1000];
    for (int i = 0; i < 1000; i++)
        check_arr[i] = true;

    int oxygen_loc, co2_loc;
    string oxygen, co2;

    vector<string> s;
    fstream file_name;
    file_name.open("input_day3.txt");
    string item_name;
    while (file_name >> item_name)
    {
        s.push_back(item_name);
        if (file_name.eof())
            break;
    }

    int counter = 1000;

    for (int j = 0; j < 12; j++)
    {
        int aces = 0, zeros = 0;
        for (int i = 0; i < 1000; i++)
        {
            if (check_arr[i] == true)
            {
                if (s[i][j] == '1')
                    aces++;
                else
                    zeros++;
            }
        }
        cout << aces << " " << zeros << endl;

        for (int i = 0; i < 1000; i++)
        {
            if (check_arr[i] == true)
            {
                if (counter == 1)
                {
                    oxygen_loc = i;
                    break;
                }
                if (aces >= zeros && s[i][j] == '0')
                {
                    check_arr[i] = false;
                    counter--;
                    if (j == 11 && counter == 1)
                        j--;
                }
                else if (zeros > aces && s[i][j] == '1')
                {
                    check_arr[i] = false;
                    counter--;
                    if (j == 11 && counter == 1)
                        j--;
                }
                else
                    oxygen_loc = i;
            }
            cout << check_arr[i] << " ";
        }
        cout << endl;
    }

    for (int j = 0; j < 12; j++)
        oxygen.push_back(s[oxygen_loc][j]);

    /////////////////////////////////////////////////////////////////////

    counter = 1000;

    for (int i = 0; i < 1000; i++)
        check_arr[i] = true;

    for (int j = 0; j < 12; j++)
    {
        int aces = 0, zeros = 0;
        for (int i = 0; i < 1000; i++)
        {
            if (check_arr[i] == true)
            {
                if (s[i][j] == '1')
                    aces++;
                else
                    zeros++;
            }
        }

        for (int i = 0; i < 1000; i++)
        {
            if (check_arr[i] == true)
            {
                if (counter == 1)
                {
                    co2_loc = i;
                    break;
                }
                if (aces < zeros && s[i][j] == '0')
                {
                    check_arr[i] = false;
                    counter--;
                    if (j == 11 && counter == 1)
                        j--;
                }
                else if (zeros <= aces && s[i][j] == '1')
                {
                    check_arr[i] = false;
                    counter--;
                    if (j == 11 && counter == 1)
                        j--;
                }
            }
        }
    }

    for (int j = 0; j < 12; j++)
        co2.push_back(s[co2_loc][j]);

    int oxygen_dec = 0, co2_dec = 0;
    oxygen_dec = stoi(oxygen, 0, 2);
    co2_dec = stoi(co2, 0, 2);

    cout << oxygen << " " << co2 << endl;
    cout << oxygen_dec * co2_dec;
}