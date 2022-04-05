#include <cstdio>
#include <string>
#include <iostream>
#include "Score.h"
using namespace std;

int main(){
    cout<<"不带初始化:" <<endl;
    Score stu1[3];
    for(int i = 0; i < 3; i ++ ){
        string name1,name2, id;
        int s1, s2;
        cin>>id>>name1>>name2>>s1>>s2;
        string name = name1 + " " + name2;
        //stu1[i] = (new Score(id,name,s1,s2));
        stu1[i] = *(new Score(id,name,s1,s2));
        stu1[i].showScore();
    }
    cout<<"带初始化:" <<endl;
    static Score stu2[3] = {stu1[0], stu1[1], stu1[2]};
    for(int i = 0; i < 3; i ++ ) stu2[i].showScore();
    return 0;
}
/*
201925230107 He Guangsheng 90 90 
201925230108 Huan Haojin 100 90
201925230110 Lai Hongxiang 100 80 
*/