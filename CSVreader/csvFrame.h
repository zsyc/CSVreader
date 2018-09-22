#ifndef CSVFRAME_H_INCLUDED
#define CSVFRAME_H_INCLUDED
#include <string>
#include <vector>

using std::vector;
using std::string;

/*  作为C++练习 尝试写一个csv处理工具，并部分提供pandas库中对Dataframe的处理方法，最好做一个GUI
    打算提供方法：
    1. 索引，也就是某行某列
    2. 添加、删除行
    3. 添加、删除列
    4. 要考虑第一行不是数据，而是header的情况

    数据结构，因为CSV文件行列不清楚，必须是动态容器：
    1. 使用vector<string>来处理行，然后对string进行逗号、分号分割（刚刚发现标准库里没有现成方法……），但这样做的话，
    功能3就难以实现？并且对数据处理要进行类型转换
    2. 使用二维vector<vector<double> >，但好像定义起来比较麻烦，读取效率也低

    方案:
    1. 使用数据结构1读取行，这样可以避免一些行尾特殊字符带来的多余bug
    2. 分割行数据，压入二维vector*/

class csvFrame
{
private:
    string path;
    char sep;

public:
    csvFrame(string ex_path,char ex_sep=',');
    vector<string> loadCSVline();
    vector<string> lineSplit(const string);
    vector<vector<string> > DataFrame ();

};

#endif // CSVFRAME_H_INCLUDED
