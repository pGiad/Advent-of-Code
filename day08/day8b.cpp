#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{

    string input, s;
    char garbage;
    string decoding[10];
    string output[4];
    string dec[10];
    int result = 0;

    ifstream file("input_day8.txt");
    while (!file.eof())
    {
        for (int i = 0; i < 10; i++)
        {
            file >> input;
            dec[i] = input;
        }
        for (int k = 0; k < 10; k++)
        {
            for (int i = 0; i < 10; i++)
            {
                s = dec[i];
                switch (s.length())
                {
                case 2:
                    decoding[1] = s;
                    break;
                case 3:
                    decoding[7] = s;
                    break;
                case 4:
                    decoding[4] = s;
                    break;
                case 7:
                    decoding[8] = s;
                    break;
                case 6:
                {
                    bool nine = true;
                    for (auto j = decoding[4].begin(); j != decoding[4].end(); j++)
                    {
                        if (s.find(*j) == -1)
                        {
                            nine = false;
                            break;
                        }
                    }
                    if (nine)
                    {
                        decoding[9] = s;
                        break;
                    }

                    bool zero = true;
                    for (auto j = decoding[1].begin(); j != decoding[1].end(); j++)
                    {
                        if (s.find(*j) == -1)
                        {
                            zero = false;
                            break;
                        }
                    }
                    if (zero)
                    {
                        decoding[0] = s;
                        break;
                    }
                    else
                    {
                        decoding[6] = s;
                        break;
                    }
                }
                case 5:
                {
                    bool three = true;
                    for (auto j = decoding[1].begin(); j != decoding[1].end(); j++)
                    {
                        //cout << *j << endl;
                        if (s.find(*j) == -1)
                        {
                            //cout << k << " " << i << endl;
                            three = false;
                            break;
                        }
                    }
                    if (three)
                    {
                        //cout << k << " " << i << endl;
                        decoding[3] = s;
                        break;
                    }

                    bool five = true;
                    int missing = 0;
                    for (auto j = decoding[6].begin(); j != decoding[6].end(); j++)
                    {
                        if (s.find(*j) == -1)
                        {
                            missing++;
                        }
                        if (missing == 2)
                        {
                            five = false;
                            break;
                        }
                    }
                    if (five)
                    {
                        decoding[5] = s;
                        break;
                    }
                    else
                    {
                        decoding[2] = s;
                        break;
                    }
                }
                }
            }
        }

        file >> garbage;
        for (int i = 0; i < 4; i++)
        {
            file >> s;
            output[i] = s;
        }

        string output_num, checker_num;
        bool matching = true;

        for (int i = 0; i < 4; i++)
        {
            output_num = output[i];
            //cout << output_num << endl;
            for (int j = 0; j < 10; j++)
            {
                matching = true;
                checker_num = decoding[j];
                //cout << checker_num << endl;
                if (output_num.length() == checker_num.length())
                {
                    for (int k = 0; k < output_num.length(); k++)
                    {
                        if (checker_num.find(output_num[k]) == -1)
                        {
                            //cout << i << " " << j << " " << k << endl;
                            matching = false;
                            break;
                        }
                    }
                    if (matching == true)
                    {
                        result += j * pow(10, 3 - i);
                        cout << j << endl;
                    }
                }
            }
        }
        cout << result << endl;
    }

    for (int i = 0; i < 10; i++)
        cout << decoding[i] << " ";
}