#include "csvFrame.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//#include <cstdlib>  //exit(1)

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;

csvFrame::csvFrame(string ex_path,char ex_sep)
{
    path=ex_path;   // csv文件路径
    sep=ex_sep;
}

vector<string> csvFrame::loadCSVline() // 返回以“行”为单位存储在vector中的csv数据
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

vector<string> csvFrame::lineSplit(const string line) //把一行以分隔符分割,然后把每一项压入vector
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

vector<vector<string> > csvFrame::DataFrame ()
{
    /* 本函数通过调用子函数完成了一项任务，即把一个文本文档按照某分隔符装入一个二维vector中 */
    vector<string> lineVector=loadCSVline();
    vector<string>::size_type num_lines=lineVector.size();
    vector<vector<string> > dataframe;
    cout<<num_lines<<endl;
    for (vector<string>::size_type i=0;i<num_lines;++i)
    {
        dataframe.push_back(lineSplit(lineVector.at(i)));
    }
    return dataframe;
}
