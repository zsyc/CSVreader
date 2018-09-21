#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>  //exit(1)

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;

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

template <typename T>
void DisplayContents(const T& container)
{
    for (auto &i:container) cout<<i<<endl;;
//    for (auto element=container.cbegin();element!=container.cend();++element) cout<<*element<<' ';
    cout<<endl;
}
//细想起来问题非常多，先实现CSV文件的读取吧，就使用数据结构1
vector<string> loadCSVline(string fpath) // 参数为csv文件路径，返回以“行”为单位存储在vector中的csv数据
{
    vector<string> index;
    string line;
    ifstream openCsvFile(fpath);
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

vector<string> lineSplit(string line, char sep=',') //把一行以分隔符分割,然后把每一项压入vector
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

vector<vector<string> > csvDataFrame (string path,char sep=',')
{
    /* 本函数通过调用子函数完成了一项任务，即把一个文本文档按照某分隔符装入一个二维vector中 */
    vector<string> lineVector=loadCSVline(path);
    vector<string>::size_type num_lines=lineVector.size();
    vector<vector<string> > dataframe;
    cout<<num_lines<<endl;
    for (vector<string>::size_type i=0;i<num_lines;++i)
    {
        dataframe.push_back(lineSplit(lineVector.at(i),sep));
    }
    return dataframe;
}

//TODO 下一步a. 整合到类中，b. 再提供一些方法
int main()
{
    string PATH="./data/cc.txt";
//    string PATH="./data/exa.csv";
    vector<vector<string> > Data=csvDataFrame(PATH);
    cout<<Data.at(2).at(1);

    return 0;
}
