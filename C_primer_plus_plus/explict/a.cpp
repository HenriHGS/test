#include <iostream>
#include <cstring>
using namespace std;

class A
{
public:
    int var;
    /* explicit A(int tmp)
    {
        var = tmp;
        cout << var << endl;
    } */
    A(int tmp)
    {
        var = tmp;
        cout << var << endl;
    }
};
int main()
{
    A ex(100);
    A ex1 = 10; // error: conversion from 'int' to non-scalar type 'A' requested
    return 0;
}
