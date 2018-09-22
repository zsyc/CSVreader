#include "CsvFrame.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
int main()
{
//    string PATH="./data/cc.txt";  //sep=','
    string PATH="./data/exa.csv";   //sep=';'
    CsvFrame obj(PATH,';');
    vector<vector<string> > Data=obj.DataFrame();
    obj.Shape();
//    obj.Header();
//    obj.DisplayRows(1,3);
    obj.DisplayCols(1,2);


    return 0;
}
