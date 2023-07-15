#include <iostream>

using namespace std;

class CMatrix
{
private:
    int rowNumber;
    int columnNumber;
    int** matrix;
public:
    CMatrix()
    {

    }
    CMatrix(int rowNumber,int columnNumber)
    {
        this->rowNumber=rowNumber;
        this->columnNumber=columnNumber;
        matrix=new int*[rowNumber];
        for(int i=0;i<rowNumber;i++)
        {
            matrix[i]=new int[columnNumber];
            for(int j=0;j<columnNumber;j++)
            {
                matrix[i][j]=0;
            }
        }
    }
    virtual ~CMatrix()
    {

    }
    void init(int rowNumber,int columnNumber)
    {
        this->rowNumber=rowNumber;
        this->columnNumber=columnNumber;
        matrix=new int*[rowNumber];
        for(int i=0;i<rowNumber;i++)
        {
            matrix[i]=new int[columnNumber];
            for(int j=0;j<columnNumber;j++)
            {
                matrix[i][j]=0;
            }
        }
    }
    virtual void readData()
    {
        int pom;
        for(int i=0;i<rowNumber;i++)
        {
            for(int j=0;j<columnNumber;j++)
            {
                cin>>pom;
                matrix[i][j]=pom;
            }
        }
    }
    virtual void show()
    {
        for(int i=0;i<rowNumber;i++)
        {
            for(int j=0;j<columnNumber;j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int getrow()
    {
        return rowNumber;
    }
    int getcol()
    {
        return columnNumber;
    }
    void setmatind(int i,int j,int wartosc)
    {
        matrix[i][j]=wartosc;
    }
    int getmatind(int i,int j)
    {
        return matrix[i][j];
    }
    virtual double determinant()=0;

};
class CTriangularMatrix: public CMatrix
{
public:
    CTriangularMatrix()
    {

    }
    CTriangularMatrix(int m):CMatrix(m,m)
    {
       cout<<"konstruktor"<<endl;
    }
    virtual void readData()
    {
        int pom;
        int roz=getrow();
        for(int i=0;i<roz;i++)
        {
            for(int j=i;j<roz;j++)
            {
                cin>>pom;
                setmatind(i,j,pom);
            }
        }
    }
    virtual double determinant()
    {
        int wskaznik=1;
        int k=getrow();
        for (int i=0;i<k;i++)
        {
            wskaznik = wskaznik * getmatind(i,i);
        }
        return wskaznik;
    }
};

int main()
{
    CMatrix *m1=new CTriangularMatrix(3);
    m1->readData();
    m1->show();
    cout<<m1->determinant()<<endl;


    return 0;
}
