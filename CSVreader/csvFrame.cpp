#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <map>
#include "CsvFrame.h"
//#include <cstdlib>  //exit(1)

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::out_of_range;
using std::invalid_argument;
using std::map; //�洢header��ǩ

CsvFrame::CsvFrame(const string &ex_path,const char ex_sep)
{
    path=ex_path;   // csv�ļ�·��
    sep=ex_sep;
}

vector<string> CsvFrame::LoadCSVline() // �����ԡ��С�Ϊ��λ�洢��vector�е�csv����
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

vector<string> CsvFrame::LineSplit(const string &line) //��һ���Էָ����ָ�,Ȼ���ÿһ��ѹ��vector��������һ�е�һάvector
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

vector<double> CsvFrame::GetColumnData(const int col)
{
    vector<double> column;
    for (unsigned int row=0;row<dataframe.size();++row){
        try{
            column.push_back(stod(dataframe.at(row).at(col)));
        }
        catch (out_of_range) {
        cout<<"out of range"<<endl;
        }
        catch (invalid_argument){
        column.push_back(0.0);
        }
    }

    return column;
}
vector<double> CsvFrame::GetColumnData(const string col)
{
    vector<double> column;
    for (unsigned int row=0;row<dataframe.size();++row){
        try{
            column.push_back(stod(dataframe.at(row).at(headerlabelmap[col])));
        }
        catch (out_of_range) {
        cout<<"out of range"<<endl;
        }
        catch (invalid_argument){
        column.push_back(0.0);
        }
    }

    return column;
}

vector<vector<string> > CsvFrame::DataFrame ()
{
    /* ������ͨ�������Ӻ��������һ�����񣬼���һ���ı��ĵ�����ĳ�ָ���װ���άvector��(dataframe) */
    vector<string> lineVector=LoadCSVline();
    vector<string>::size_type num_lines=lineVector.size();
    for (vector<string>::size_type i=0;i<num_lines;++i)
    {
        dataframe.push_back(LineSplit(lineVector.at(i)));
    }
    return dataframe;
}

void CsvFrame::DisplayData()    //��ӡ��������
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
    try{    //һЩcsv�����һ�����գ���˲�׽�����쳣 out of range
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
        try{    //һЩcsv�����һ�����գ���˲�׽�����쳣
            for (vector<vector<string> >::size_type row=0;row<dataframe.size();++row) cout<<dataframe.at(row).at(col)<<' ';
        }
        catch(out_of_range){
            cout<<endl<<"out of range"<<endl;
        }
        cout<<endl;
    }
}
void CsvFrame::DisplayColWithLabel(const string &label)
{
    SetHeaderLabels();
    try{    //һЩcsv�����һ�����գ���˲�׽�����쳣
        for (vector<vector<string> >::size_type row=0;row<dataframe.size();++row) cout<<dataframe.at(row).at(headerlabelmap[label])<<' ';
    }
    catch(out_of_range){
    cout<<endl<<"out of range"<<endl;
    }

    cout<<endl;
}

void CsvFrame::Shape()  // ���csv������
{
    cout<<dataframe.size()<<" rows X "<<dataframe.at(0).size()<<" columns"<<endl;
}
void CsvFrame::Header() //output header/ first row
{
    for (string &cell:dataframe.at(0)) cout<<cell<<' ';
}
void CsvFrame::SetHeaderLabels()    //�����б�ǩ������һһ��Ӧ����ʵ���ñ�ǩ�����еĹ���
{
    for (vector<string>::size_type i=0;i<dataframe.at(0).size();++i)
        headerlabelmap.insert (make_pair (dataframe.at(0).at(i),i));
}


#define TEST_CSVFRAME   //This part is test code.
#ifdef TEST_CSVFRAME
int main()
{
//    string PATH="./data/cc.txt";  //sep=','
    string PATH="./data/exa2.csv";   //sep=';'
    CsvFrame obj(PATH,';');
    vector<vector<string> > Data=obj.DataFrame();
    obj.SetHeaderLabels();
//    obj.Shape();
//    obj.Header();
//    obj.DisplayRows(1,3); //��ӡ��1����3��
//    obj.DisplayCols(1,2);
//    for (auto &xin:obj.headerlabelmap) cout<<xin.first<<' '<<xin.second<<endl;;
//    obj.DisplayColWithLabel("TP[0].Class[1]");
    vector<double> a,a2;
    a=obj.GetColumnData(1);
    a2=obj.GetColumnData("RT-Range Processor.Hunter.AccelVehicle.AccelerationX");
    for (auto &x:a) cout<<x<<endl;
    for (auto &x:a2) cout<<x<<endl;

    return 0;
}
#endif // TEST_CSVFRAME
