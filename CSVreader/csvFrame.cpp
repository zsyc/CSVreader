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
    path=ex_path;   // csv�ļ�·��
    sep=ex_sep;
}

vector<string> csvFrame::loadCSVline() // �����ԡ��С�Ϊ��λ�洢��vector�е�csv����
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

vector<string> csvFrame::lineSplit(const string line) //��һ���Էָ����ָ�,Ȼ���ÿһ��ѹ��vector
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
    /* ������ͨ�������Ӻ��������һ�����񣬼���һ���ı��ĵ�����ĳ�ָ���װ��һ����άvector�� */
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
