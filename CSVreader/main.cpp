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

/*  ��ΪC++��ϰ ����дһ��csv�����ߣ��������ṩpandas���ж�Dataframe�Ĵ������������һ��GUI
    �����ṩ������
    1. ������Ҳ����ĳ��ĳ��
    2. ��ӡ�ɾ����
    3. ��ӡ�ɾ����
    4. Ҫ���ǵ�һ�в������ݣ�����header�����

    ���ݽṹ����ΪCSV�ļ����в�����������Ƕ�̬������
    1. ʹ��vector<string>�������У�Ȼ���string���ж��š��ֺŷָ�ոշ��ֱ�׼����û���ֳɷ��������������������Ļ���
    ����3������ʵ�֣����Ҷ����ݴ���Ҫ��������ת��
    2. ʹ�ö�άvector<vector<double> >���������������Ƚ��鷳����ȡЧ��Ҳ��

    ����:
    1. ʹ�����ݽṹ1��ȡ�У��������Ա���һЩ��β�����ַ������Ķ���bug
    2. �ָ������ݣ�ѹ���άvector*/

template <typename T>
void DisplayContents(const T& container)
{
    for (auto &i:container) cout<<i<<endl;;
//    for (auto element=container.cbegin();element!=container.cend();++element) cout<<*element<<' ';
    cout<<endl;
}
//ϸ����������ǳ��࣬��ʵ��CSV�ļ��Ķ�ȡ�ɣ���ʹ�����ݽṹ1
vector<string> loadCSVline(string fpath) // ����Ϊcsv�ļ�·���������ԡ��С�Ϊ��λ�洢��vector�е�csv����
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

vector<string> lineSplit(string line, char sep=',') //��һ���Էָ����ָ�,Ȼ���ÿһ��ѹ��vector
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
    /* ������ͨ�������Ӻ��������һ�����񣬼���һ���ı��ĵ�����ĳ�ָ���װ��һ����άvector�� */
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

//TODO ��һ��a. ���ϵ����У�b. ���ṩһЩ����
int main()
{
    string PATH="./data/cc.txt";
//    string PATH="./data/exa.csv";
    vector<vector<string> > Data=csvDataFrame(PATH);
    cout<<Data.at(2).at(1);

    return 0;
}
