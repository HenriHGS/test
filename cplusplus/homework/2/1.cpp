#include <iostream>
using namespace std;

class Test
{
private:
    int x;
public:
    Test(int x)
    {
        this->x = x;
        cout << x <<" parameter constructed" << endl;}

    Test()
    {
        x = 0;
        cout << x <<" default constructed" << endl;
    }
    void init(int x)
    {
        this->x = x;
        cout << x <<" init constructed" << endl;
    }
    ~Test()
    {
        cout << x <<" destroied" << endl;
    }
    int GetX()
    {
        return x;
    }
};
Test t1(1);
Test t2(2);
void fun(Test t){
    Test t1(1000);
}
int main()
{
    
     Test a(1);
    Test b;   
    b.init(2);
    Test arr[3] = {Test(3),Test(),Test()};
    Test brr[3];   
    cout<<brr[0].GetX()<<endl;
    brr[0].init(4);
    cout<<brr[0].GetX()<<endl; 
    
    cout<<endl;
    fun(brr[0]);
    cout<<endl;
    return 0;
}
