#include<iostream>
#include <cmath>
using namespace std;

const float PI = acos(-1.0);
const float FENCE_PRICE = 35;
const float CONCRTE_PRICE = 20;

class Circle{
public:
    Circle(float r);
    float circumference();
    float area();
private:
    float radius;

};
Circle::Circle(float r){
    radius = r;
}
float Circle::circumference(){
    return 2*PI*radius;
}
float Circle::area(){
    return PI*radius*radius;
}
int main(){
    return 0;
}