// benchmarkData.cpp

// unique1          rand            0-max tuples -1
// unique2          sequence        0-max tuples - 1, sequential
// two              unique1 mod 2       0-1
// four             unique1 mod 4       0-3
// ten              unique1 mod 10      0-9
// twenty           unique1 mod 20      0-19
// onePercent       unique1 mod 100 0-99
// tenPercent       unique1 mod 10  0-9
// twentyPercent    unique mod 5    0-4
// fiftyPercent     unique1 mod 2   0-1
// unique3          ...same as unique1
// evenOnePercent   rand            onePercent * 2
// oddOnePercent    rand            onePercent * 2 + 1
// stringu1         7 random chars (A-Z) then 45 x
// stringu2         7 random chars (A-Z) then 45 x
// string4          4 of same char, then x  (AAAAxxxx..., HHHHxxxx..., OOOOxxxx..., VVVVxxxx..., AAAAxxxx..., etc)

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

void makeString(char uniqueSeven[], const int unique1);
void makeSeriesString(char string4[], char);

int main()
{
    ofstream fout;
    fout.open("benchmarkJ.txt");
    int unique1, unique2, onePercent;
    int counter = 0;
    int uniqueAra[50];
    char uniqueSeven[8];
    char exes[] = {"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"};
    char stringu1[53];
    char stringu2[53];
    char string4[53];

    char strch;
    bool hasDup = false;

    for(int i=0;i<50;i++){
        uniqueAra[i] = rand() ;
        //printf("array[%d] = %d\n\n", i, array[i]);
        hasDup = false;

        for(int j=0; j<=(i-1); j++){
                if (uniqueAra[i] == uniqueAra[j]){
                    hasDup = true;
                    i--;
                }
        }
    }

    for (int i = 0; i < 50; i++)
    {
        unique1 = uniqueAra[i];
        makeString(uniqueSeven, unique1);
        stringu1[52] = '\0';
        strcpy(stringu1, uniqueSeven);
        strcat(stringu1, exes);
        stringu2[52] = '\0';
        strcpy(stringu2, uniqueSeven);
        strcat(stringu2, exes);
        if (i % 4 == 0)
            strch = 'A';
        else if (i % 4 == 1)
            strch = 'H';
        else if (i % 4 == 2)
            strch = 'O';
        else
            strch = 'V';
        makeSeriesString(string4, strch);

        unique2 = counter;
        counter++;
        fout << unique1 << ','
             << unique2 << ',' ;
        fout << unique1 % 2 << ','
             << unique1 % 4 << ','
             << unique1 % 10 << ','
             << unique1 % 20 << ',';
        onePercent = unique1 % 100;
        fout << onePercent << ',' ;
        fout << onePercent * 10 << ','
             << onePercent * 20 << ','
             << onePercent * 50 << ','
             << unique1 << ','
             << onePercent * 2 << ','
             << onePercent * 2 + 1 << ','
             << stringu1 << ','
             << stringu2 << ','
             << string4;
        if (i < 49)
            fout << endl;
    }
    fout.close();

    return 0;
}


void makeString(char uniqueSeven[], const int unique1)
{
    string uniqueAsString;
    uniqueAsString = to_string(unique1);
    int i;

    for (i = 0; i < 7 && (static_cast<char>(uniqueAsString[i]) > 47 && static_cast<char>(uniqueAsString[i]) < 58); i++)
        uniqueSeven[i] = static_cast<char>((uniqueAsString[i])+28);

    for (i; i < 7; i++)
        uniqueSeven[i] = 'A';

    return;
}

void makeSeriesString(char string4[], char strch)
{
    for (int i = 0; i < 4; i++)
        string4[i] = strch;
    for (int j = 4; j < 52; j++)
        string4[j] = 'x';
    string4[52] = '\0';
    return;
}
