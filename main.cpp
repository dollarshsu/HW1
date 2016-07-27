#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <sstream>

using namespace std;

#define X step
#define Y 10



int main(int argc, char *argv[])
{
    cout << setw(6) << "B" << setw(6) << "x" << setw(6) << "y" << setw(6) << "z" << setw(6) << "p\n" << endl; //座標格


    ifstream fin;
    fin.open("text2.txt");




    stringstream ss;


    int i , j ;  //給矩陣for迴圈用的
    int row = 1 ;//這個是用來 讀到五個word 之後 換行
    int conter = 0 ; //把零濾掉 給for迴圈用的
    string line ;
    int step = 0 ;

    while(getline (fin,line)){
        step++;                         //換行的 計數器
    }
    cout << setw(22) << "this file have : " << step << " data"<< endl ;

    double A[X][Y];

    ifstream fin2;
    fin2.open("text2.txt");
    string word ;

    for(i=1;i<=step;i++){
        for(j=1;j<=5;j++){
            fin2 >> word ;
            ss << word;
            ss >> A[i][j];
            if (j == 1 && word == "0"){
                ss.str("");
                ss.clear();
                for (conter;conter<4;conter++){
                        fin2 >> word ;              //讀五個字 不做事情 把那排零濾掉
                }
                conter=0;
                j = 6;


            }
            else{

            cout << setw(6) << A[i][j] ;
            if(((row++)%5)==0) {        //一排五個字 後 換行
                cout << endl;
                row=1;
            }
            ss.str("");
            ss.clear();
        }
    }
}

    cout << endl;


    fin2.close();

    return 0;
}
