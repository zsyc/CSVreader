#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include "CsvFrame.h"
//#include <cstdlib>  //exit(1)

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::out_of_range;

CsvFrame::CsvFrame(const string &ex_path,const char ex_sep)
{
    path=ex_path;   // csv文件路径
    sep=ex_sep;
}

vector<string> CsvFrame::LoadCSVline() // 返回以“行”为单位存储在vector中的csv数据
{
    vector<string> index;
    string line;
    ifstream openCsvFile(path);
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
    return index;
}

vector<string> CsvFrame::LineSplit(const string &line) //把一行以分隔符分割,然后把每一项压入vector，最后输出一行的一维vector
{
    string::size_type pos=0,j;
    vector<string> linecell;
    while(pos<line.size()){
        j=line.find(sep,pos);
        if (j!=string::npos){
            linecell.push_back(line.substr(pos,j-pos));
            pos=j+1;
        }
        else{
            linecell.push_back(line.substr(pos,line.size()-pos));
            pos=line.size();
        }
    }
    return linecell;
}

vector<vector<string> > CsvFrame::DataFrame ()
{
    /* 本函数通过调用子函数完成了一项任务，即把一个文本文档按照某分隔符装入一个二维vector中 */
    vector<string> lineVector=LoadCSVline();
    vector<string>::size_type num_lines=lineVector.size();
    for (vector<string>::size_type i=0;i<num_lines;++i)
    {
        dataframe.push_back(LineSplit(lineVector.at(i)));
    }
    return dataframe;
}

void CsvFrame::DisplayData()    //打印所有内容
{
    if (dataframe.empty()) cout<<"No data was imported."<<endl;
    else{
        for (vector<vector<string> >::size_type row=0;row<dataframe.size();++row){
            for (vector<string>::size_type col=0;col<dataframe.at(row).size();++col)
                cout<<dataframe.at(row).at(col);
            cout<<endl;
        }
    }
}
void CsvFrame::DisplayData(const int row,const int col)
{
    cout<<dataframe.at(row).at(col)<<endl;
}

void CsvFrame::DisplayRows(const int row)
{
    for (const string &cell:dataframe.at(row)) cout<<cell<<' ';
    cout<<endl;
}
void CsvFrame::DisplayRows(const int firstrow,const int lastrow)
{
    for (auto row=firstrow;row<=lastrow;++row){
        for (const string &cell:dataframe.at(row)) cout<<cell<<' ';
        cout<<endl;
    }
}
void CsvFrame::DisplayCols(const int col)
{
    try{    //一些csv会最后一行留空，因此捕捉出界异常
        for (vector<vector<string> >::size_type row=0;row<dataframe.size();++row) cout<<dataframe.at(row).at(col)<<' ';
    }
    catch(out_of_range){
    cout<<endl<<"out of range"<<endl;
    }

    cout<<endl;
}
void CsvFrame::DisplayCols(const int firstcol,const int lastcol)
{
    for (auto col=firstcol;col<=lastcol;++col){
        try{    //一些csv会最后一行留空，因此捕捉出界异常
            for (vector<vector<string> >::size_type row=0;row<dataframe.size();++row) cout<<dataframe.at(row).at(col)<<' ';
        }
        catch(out_of_range){
            cout<<endl<<"out of range"<<endl;
        }
        cout<<endl;
    }
}

void CsvFrame::Shape()  // 输出csv行列数
{
    cout<<dataframe.size()<<" rows X "<<dataframe.at(0).size()<<" columns"<<endl;
}
void CsvFrame::Header() //output header/ first row
{
    for (string &cell:dataframe.at(0)) cout<<cell<<' ';
}

#define TEST_CSVFRAME   //This part is test code.
#ifdef TEST_CSVFRAME
int main()
{
    string PATH="./data/cc.txt";  //sep=','
//    string PATH="./data/exa.csv";   //sep=';'
    CsvFrame obj(PATH,',');
    vector<vector<string> > Data=obj.DataFrame();
    obj.Shape();
    obj.Header();
    obj.DisplayRows(1,3);
    obj.DisplayCols(1,2);

    return 0;
}
#endif // TEST_CSVFRAME
