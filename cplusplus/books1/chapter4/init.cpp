#include <cstdio>
using namespace std;
class Clock{
public:
    Clock(){}
    Clock(int newH, int newM, int newS);
    Clock(Clock& tempC);
    void setTime(int newH, int newM, int newS);
    void showtime();
    ~Clock(){
        printf("调用了析构函数\n");
    }
    void outTime(){
        printf("%02d:%02d:%02d\n", hour, minute, second);
    }
private:
    int hour, minute, second;
};
Clock::Clock(int newH, int newM, int newS){
    hour = newH;
    minute = newM;
    second = newS;
}
Clock::Clock(Clock& tempC){
    hour = tempC.hour;
    minute = tempC.minute;
    second = tempC.second;
    printf("调用了复制构造函数\n");
}
Clock f(){
    Clock a(1,2,3);
    return a;
}
int main(){
    /* 这里的c1表示无参数构造方法 */
    //Clock c1;

    /* 这里的c1表示有参构造方法 */
    /* Clock c1(1,2,3);
    c1.outTime();

    Clock c2 = c1;
    c2.outTime();
 */
    Clock a;
    a = f();
    return 0;
}
