#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;

/*  作为C++练习 尝试写一个csv处理工具，并部分提供pandas库中对Dataframe的处理方法
    打算提供方法：
    1. 索引，也就是某行某列
    2. 添加、删除行
    3. 添加、删除列
    4. 要考虑第一行不是数据，而是header的情况

    数据结构，因为CSV文件行列不清楚，必须是动态容器：
    1. 使用vector<string>来处理行，然后对string进行逗号、分号分割（刚刚发现标准库里没有现成方法……），但这样做的话，
    功能3就难以实现？并且对数据处理要进行类型转换
    2. 使用二维vector<vector<double> >，但好像定义起来比较麻烦，读取效率也低*/
template <typename T>
void DisplayContents(const T& container)
{
    for (auto &i:container) cout<<i<<endl;;
//    for (auto element=container.cbegin();element!=container.cend();++element) cout<<*element<<' ';
    cout<<endl;
}
//细想起来问题非常多，先实现CSV文件的读取吧，就使用数据结构1
vector<string> loadCSV(string fpath,char sep=',') // 参数为csv文件路径以及csv文件分隔符（一般为逗号或者分号）
{
    vector<string> index;
    string line;
    ifstream openCsvFile(fpath);
//    openCsvFile.open(fpath);
    if (!openCsvFile.is_open()){
        cout<<"File path is not valid"<<endl;
        exit(1);
    }
    else{
        while (openCsvFile.good()){
            getline (openCsvFile,line);
            index.push_back(line);
        }
    }
    openCsvFile.close();
    // TODO (Clemens#1#09/21/18): 实现逗号、分号分割
    return index;
}
string PATH="./data/cc.txt";
int main()
{
//    loadCSV(PATH);
    DisplayContents(loadCSV(PATH));
    return 0;
}
