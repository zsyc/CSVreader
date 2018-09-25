#ifndef CSVFRAME_H_INCLUDED
#define CSVFRAME_H_INCLUDED
using std::string;
using std::vector;

/*  作为C++练习 尝试模仿pandas写一个csv处理工具，并部分提供pandas库中对Dataframe的处理方法，最后用QT实现一个GUI
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
    2. 分割行数据，压入二维vector */

class CsvFrame
{
private:
    string path;
    char sep;

    /**用于存储数据******************************/
    vector<vector<string> > dataframe;   //运行DataFrame函数后，用于存储该对象
    std::map<string,int> headerlabelmap;           //保存header 标签
    /*******************************************/

    /**对数据预处理**********************************/
    vector<string> LoadCSVline();                    //返回以“行”为单位存储在vector中的csv数据
    vector<string> LineSplit(const string&);        //把一行以分隔符分割,然后把每一项压入vector，最后输出一行的一维vector

    vector<double> GetColumnData(const int);           //把某一列的数值转换为浮点型vector便于计算,header转换为0.0
    vector<double> GetColumnData(const string);
    /************************************************/

public:
    /**Object init，read and save the data****************/
    CsvFrame(const string &ex_path, const char ex_sep=',') : path(ex_path), sep(ex_sep){};
    vector<vector<string> > DataFrame ();       //把一个文本文档按照某分隔符装入一个二维vector中
    void SetHeaderLabels();                     //把header标签与列数对应起来，存储到headerlabelmap中，前提是已经有了dataframe数据

    /*****************************************************/

    /**Display data************************************/
    void DisplayData();                     //打印所有内容
    void DisplayData(const int row,const int col);  //打印单元格
    void DisplayRows(const int row);            //打印某行
    void DisplayRows(const int firstrow,const int lastrow);  //打印连续几行
    void DisplayCols(const int col);            //打印某列
    void DisplayCols(const int firstcol,const int lastcol);  //打印连续几列
    void DisplayColWithLabel(const string &);
    void Shape();                           // 输出csv行列数
    void Header();                          //输出第一行
    /*************************************************/

    /**statistic*************************************/
    double Mean(const int col, bool header);    //If header doesn't exist, header=0
    /*************************************************/

};
/* python切片功能是否可以用重载‘:’实现？
    pandas的添加行列使用pd.Series实现的，是否考虑？*/

#endif // CSVFRAME_H_INCLUDED
