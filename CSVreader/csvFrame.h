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

class CsvFrame
{
private:
    string path;
    char sep;

public:
    vector<vector<string> > dataframe;  // 运行DataFrame函数后，用于存储该对象

    CsvFrame(const string &ex_path, const char ex_sep=',');
    vector<string> LoadCSVline();   //返回以“行”为单位存储在vector中的csv数据
    vector<string> LineSplit(const string&);    //把一行以分隔符分割,然后把每一项压入vector，最后输出一行的一维vector
    vector<vector<string> > DataFrame ();   // 本函数通过调用子函数完成了一项任务，即把一个文本文档按照某分隔符装入一个二维vector中
    void DisplayData(); //打印所有内容
    void DisplayData(const int,const int); //打印单元格
    void DisplayRows(const int); //打印某行
    void DisplayRows(const int,const int);  //打印连续几行
    void DisplayCols(const int); //打印某列
    void DisplayCols(const int,const int);  //打印连续几列

    void Shape();   // 输出csv行列数
    void Header();  //输出第一行

};
/* python切片功能是否可以用重载‘:’实现？
    pandas的添加行列使用pd.Series实现的，是否考虑？*/

#endif // CSVFRAME_H_INCLUDED
