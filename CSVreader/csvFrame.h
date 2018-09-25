#ifndef CSVFRAME_H_INCLUDED
#define CSVFRAME_H_INCLUDED
using std::string;
using std::vector;

/*  ��ΪC++��ϰ ����ģ��pandasдһ��csv�����ߣ��������ṩpandas���ж�Dataframe�Ĵ������������QTʵ��һ��GUI
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
    2. �ָ������ݣ�ѹ���άvector */

class CsvFrame
{
private:
    string path;
    char sep;

    /**���ڴ洢����******************************/
    vector<vector<string> > dataframe;   //����DataFrame���������ڴ洢�ö���
    std::map<string,int> headerlabelmap;           //����header ��ǩ
    /*******************************************/

    /**������Ԥ����**********************************/
    vector<string> LoadCSVline();                    //�����ԡ��С�Ϊ��λ�洢��vector�е�csv����
    vector<string> LineSplit(const string&);        //��һ���Էָ����ָ�,Ȼ���ÿһ��ѹ��vector��������һ�е�һάvector

    vector<double> GetColumnData(const int);           //��ĳһ�е���ֵת��Ϊ������vector���ڼ���,headerת��Ϊ0.0
    vector<double> GetColumnData(const string);
    /************************************************/

public:
    /**Object init��read and save the data****************/
    CsvFrame(const string &ex_path, const char ex_sep=',') : path(ex_path), sep(ex_sep){};
    vector<vector<string> > DataFrame ();       //��һ���ı��ĵ�����ĳ�ָ���װ��һ����άvector��
    void SetHeaderLabels();                     //��header��ǩ��������Ӧ�������洢��headerlabelmap�У�ǰ�����Ѿ�����dataframe����

    /*****************************************************/

    /**Display data************************************/
    void DisplayData();                     //��ӡ��������
    void DisplayData(const int row,const int col);  //��ӡ��Ԫ��
    void DisplayRows(const int row);            //��ӡĳ��
    void DisplayRows(const int firstrow,const int lastrow);  //��ӡ��������
    void DisplayCols(const int col);            //��ӡĳ��
    void DisplayCols(const int firstcol,const int lastcol);  //��ӡ��������
    void DisplayColWithLabel(const string &);
    void Shape();                           // ���csv������
    void Header();                          //�����һ��
    /*************************************************/

    /**statistic*************************************/
    double Mean(const int col, bool header);    //If header doesn't exist, header=0
    /*************************************************/

};
/* python��Ƭ�����Ƿ���������ء�:��ʵ�֣�
    pandas���������ʹ��pd.Seriesʵ�ֵģ��Ƿ��ǣ�*/

#endif // CSVFRAME_H_INCLUDED
