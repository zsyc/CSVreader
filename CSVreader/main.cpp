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

/*  ��ΪC++��ϰ ����дһ��csv�����ߣ��������ṩpandas���ж�Dataframe�Ĵ�����
    �����ṩ������
    1. ������Ҳ����ĳ��ĳ��
    2. ��ӡ�ɾ����
    3. ��ӡ�ɾ����
    4. Ҫ���ǵ�һ�в������ݣ�����header�����

    ���ݽṹ����ΪCSV�ļ����в�����������Ƕ�̬������
    1. ʹ��vector<string>�������У�Ȼ���string���ж��š��ֺŷָ�ոշ��ֱ�׼����û���ֳɷ��������������������Ļ���
    ����3������ʵ�֣����Ҷ����ݴ���Ҫ��������ת��
    2. ʹ�ö�άvector<vector<double> >���������������Ƚ��鷳����ȡЧ��Ҳ��*/
template <typename T>
void DisplayContents(const T& container)
{
    for (auto &i:container) cout<<i<<endl;;
//    for (auto element=container.cbegin();element!=container.cend();++element) cout<<*element<<' ';
    cout<<endl;
}
//ϸ����������ǳ��࣬��ʵ��CSV�ļ��Ķ�ȡ�ɣ���ʹ�����ݽṹ1
vector<string> loadCSV(string fpath,char sep=',') // ����Ϊcsv�ļ�·���Լ�csv�ļ��ָ�����һ��Ϊ���Ż��߷ֺţ�
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
    // TODO (Clemens#1#09/21/18): ʵ�ֶ��š��ֺŷָ�
    return index;
}
string PATH="./data/cc.txt";
int main()
{
//    loadCSV(PATH);
    DisplayContents(loadCSV(PATH));
    return 0;
}
