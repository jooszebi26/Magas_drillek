#include <iostream>
#include <string>
#include "std_lib_facilities.h"

struct B1{
    virtual void vf (){ cout << "B1::vf())" << endl;}
    void f(){cout << "B1::v())" << endl;}
    virtual void pvf() = 0;

};

struct D1:B1{
    void vf() override {cout << "D1::vf())" << endl;}
    void f(){cout << "D1::v())" << endl;}
};

struct D2:D1{
    void pvf() override{cout << "D2::pvf())" << endl;}
};

struct B2{
    virtual void pvf() = 0;
};

struct D21 : B2{
    string string = "AoE";
    void pvf() override{cout << string << endl;}
};

struct D22 : B2{
    int numb = 20;
    void pvf() override {cout << numb << endl;}
};

void res (B2& numb){
    numb.pvf();
}

int main(){
    /*
    B1 first;
    first.vf();
    first.f();

    D1 second;
    second.vf();
    second.f();
    
    B1& reference1 {second};
    reference1.vf();
    reference1.f();
    */
    D2 fourth;
    fourth.vf();
    fourth.f();
    fourth.pvf();
    
    
    D21 aoe;
    aoe.pvf();
    
    D22 numb;
    res(numb);
    
    return 0;
}