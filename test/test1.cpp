#include <stdio.h>
#include<iostream>
#include"file.h"
#include"optionimage.h"
using namespace std;

int main()
{
    int a = 100, b = 99;
    string path = "data";
    string str_id = "1";
    int int_id = 2;
    CreateDirById(path,str_id);
    CreateDirById(path,int_id);
    
    std::cout<<"hello test"<<a<<":"<<b<<std::endl;
    return 0;
}
