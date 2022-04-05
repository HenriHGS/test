#include <string>
using namespace std;
#ifndef _SCORE_H_
#define _SCORE_H_
class Score{
public: 
    Score(){}
    Score(string id, string name, int s1, int s2){
        this->id = id;
        this->name = name;
        this->normalScore = s1;
        this->finalScore = s2;
        count();
    }

    void count(){
        totScore = (normalScore*4 + finalScore*6)/ 10;
    }
    void showScore(){
        cout<<id<<"  "<<name<<"  "<<normalScore<<"  "<<finalScore<<"  "<<totScore<<endl;
    }
private:
    string id, name;
    int normalScore, finalScore, totScore;
};
#endif