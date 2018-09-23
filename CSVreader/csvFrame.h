#ifndef CSVFRAME_H_INCLUDED
#define CSVFRAME_H_INCLUDED

/*  ��ΪC++��ϰ ����ģ��pandasдһ��csv�����ߣ��������ṩpandas���ж�Dataframe�Ĵ������������һ��GUI
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
    std::string path;
    char sep;

public:
    std::vector<std::vector<std::string> > dataframe;  // ����DataFrame���������ڴ洢�ö���

    CsvFrame(const std::string &ex_path, const char ex_sep=',');
    std::vector<std::string> LoadCSVline();   //�����ԡ��С�Ϊ��λ�洢��vector�е�csv����
    std::vector<std::string> LineSplit(const std::string&);    //��һ���Էָ����ָ�,Ȼ���ÿһ��ѹ��vector��������һ�е�һάvector
    std::vector<std::vector<std::string> > DataFrame ();   // ������ͨ�������Ӻ��������һ�����񣬼���һ���ı��ĵ�����ĳ�ָ���װ��һ����άvector��
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
