#include "csvFrame.h"
#include <iostream>
using std::cout;
int main()
{
//    string PATH="./data/cc.txt";
    string PATH="./data/exa.csv";
    csvFrame obj(PATH,';');
    vector<vector<string> > Data=obj.DataFrame();
    cout<<Data.at(2).at(1);

    return 0;
}
