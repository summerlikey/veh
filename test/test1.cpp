#include <stdio.h>
#include<iostream>
#include"file.h"
#include"optionimage.h"
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
using namespace std;

int main()
{
    
    int a = 100, b = 99;
    cout<<a<<"::"<<b<<endl;
    string path = "data";
    string str_id = "1";
    int int_id = 2;
    CreateDirById(path,str_id);
    CreateDirById(path,int_id);
    
    return 0;
}
