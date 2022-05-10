#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int hydro_vents[1000][1000];

int main() {
    int x1[500], y1[500], x2[500], y2[500];
    int i = 0;
    int input;
    char comma;

    ifstream file_name("input_day5.txt");

    while (!file_name.eof())
    {
        file_name >> input;
        x1[i] = input;
        file_name >> comma >> input;
        y1[i] = input;
        file_name >> comma >> comma >> input;
        x2[i] = input;
        file_name >> comma >> input;
        y2[i] = input;
        i++;
    }

    for(int i = 0; i<1000; i++) {
        for(int j = 0; j<1000; j++) {
            hydro_vents[i][j] = 0;
        }
    }

    for(int i = 0; i<500; i++) {
        if(x1[i] == x2[i]) {
            if(y1[i] < y2[i]) {
                for(int loc = y1[i]; loc<=y2[i]; loc++)
                hydro_vents[x1[i]][loc]++;
            }
            else {
                for(int loc = y2[i]; loc<=y1[i]; loc++)
                hydro_vents[x1[i]][loc]++;
            }
        }
        else if(y1[i] == y2[i]) {
            if(x1[i] < x2[i]) {
                for(int loc = x1[i]; loc<=x2[i]; loc++)
                hydro_vents[loc][y1[i]]++;
            }
            else {
                for(int loc = x2[i]; loc<=x1[i]; loc++)
                hydro_vents[loc][y2[i]]++;
            }
        }
    }

    int total_vents = 0;

    for(int i = 0; i<1000; i++) {
        for(int j = 0; j<1000; j++) {
            if(hydro_vents[i][j] > 1) total_vents++;
        }
    }

    cout << total_vents;
}