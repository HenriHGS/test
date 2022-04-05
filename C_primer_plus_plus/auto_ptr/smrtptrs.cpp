// smrtptrs.cpp -- using three kinds of smart pointers
// requires support of C++11 shared_ptr and unique_ptr
#include <iostream>
#include <string>
#include <memory>

class Report{
private:
    std::string str;
public:
    Report(const std::string s): str(s)
        { std::cout<< "Object created!\n";}
    ~Report(){ std::cout<<"Object deleted!\n"; }
    void comment() const { std::cout<<str<< "\n"; }
};
int main(){
    {
        std::auto_ptr<Report> ps(new Report("using auto_ptr"));
        ps->comment();
    }
    {
        std::shared_ptr<Report> ps(new Report("using shared_ptr"));
        ps->comment();
    }
    {
        std::unique_ptr<Report> ps(new Report("using unique_ptr"));
        ps->comment();
    }
    {
        std::shared_ptr<double> pd(new double(4));
        std::cout<<*pd<<std::endl;
        //double* pd2 = pd;
        // std::cout<<*pd2<<std::endl;
    }
    return 0;
}