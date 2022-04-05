/* 
    定义一个加法的模板
    int main()
    {
        cout<<add(9,8)<<endl;
        cout<<add(9.0,8.0)<<endl;
        cout<<add(9.0,8)<<endl;
        return 0；
    }

 */
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

template<typename T1,typename T2, typename T3>
T1 add(T2 a, T3 b){
    T1 sum = 0;
    sum = static_cast<T1>(a+b);
    return sum;
}

int main(){
    // cout<<add<1,1><<endl;
    // 无法自动推导返回值的类型
    cout<< add<int>(1,1) <<endl;
    cout<< add<float>(1.1,1.2) << endl;

    return 0;
}