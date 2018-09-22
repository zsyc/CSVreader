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

class csvFrame
{
private:
    string path;
    char sep;

public:
    csvFrame(string ex_path,char ex_sep=',');
    vector<string> loadCSVline();
    vector<string> lineSplit(const string);
    vector<vector<string> > DataFrame ();

};

#endif // CSVFRAME_H_INCLUDED
