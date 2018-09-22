#ifndef CSVFRAME_H_INCLUDED
#define CSVFRAME_H_INCLUDED
#include <string>
#include <vector>

using std::vector;
using std::string;

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

class CsvFrame
{
private:
    string path;
    char sep;

public:
    vector<vector<string> > dataframe;  // ����DataFrame���������ڴ洢�ö���

    CsvFrame(const string &ex_path, const char ex_sep=',');
    vector<string> LoadCSVline();   //�����ԡ��С�Ϊ��λ�洢��vector�е�csv����
    vector<string> LineSplit(const string&);    //��һ���Էָ����ָ�,Ȼ���ÿһ��ѹ��vector��������һ�е�һάvector
    vector<vector<string> > DataFrame ();   // ������ͨ�������Ӻ��������һ�����񣬼���һ���ı��ĵ�����ĳ�ָ���װ��һ����άvector��
    void DisplayData(); //��ӡ��������
    void DisplayData(const int,const int); //��ӡ��Ԫ��
    void DisplayRows(const int); //��ӡĳ��
    void DisplayRows(const int,const int);  //��ӡ��������
    void DisplayCols(const int); //��ӡĳ��
    void DisplayCols(const int,const int);  //��ӡ��������

    void Shape();   // ���csv������
    void Header();  //�����һ��

};
/* python��Ƭ�����Ƿ���������ء�:��ʵ�֣�
    pandas���������ʹ��pd.Seriesʵ�ֵģ��Ƿ��ǣ�*/

#endif // CSVFRAME_H_INCLUDED
