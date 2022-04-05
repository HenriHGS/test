#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
class Point{
public:
    Point(int x, int y): x(x),y(y){}
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    double Dist(Point b){
        double dist = (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
        return sqrt(dist);
    }
    //�����������Ǻ���Ϥ��������
    double Dist(const Point&b) const{
        double dist = (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
        return sqrt(dist);
    }
private:
    int x, y;
};
int main(){
    const Point myp1(1,1), myp2(4,5);
    int x1, y1, x2, y2; 
    cout<<"������p1"<<endl;
    cin>>x1>>y1;
    cout<<"������p2"<<endl;
    cin>>x2>>y2;
    Point p1(x1,y1), p2(x2,y2);
    cout<<"myp1 �� p1�ľ���"<<endl;
    cout<<myp1.Dist(p1)<<endl;
    
    cout<<"myp1 �� p2�ľ���"<<endl;
    cout<<myp1.Dist(p2)<<endl;
    
    cout<<"myp2 �� p1�ľ���"<<endl;
    cout<<myp2.Dist(p1)<<endl;
    
    cout<<"myp1 �� p1�ľ���"<<endl;
    cout<<myp2.Dist(p2)<<endl;
    
    return 0;
}