#include"optionpointcloud.h"
OptionPointCloud::OptionPointCloud()
{

}

int OptionPointCloud::RunPointCloudFilter(){
    //点云滤波
    std::cout<<"点云滤波"<<std::endl;
    return 0;
}

int OptionPointCloud::RunPointCloudSplicing(){
    //点云拼接
    std::cout<<"点云拼接"<<std::endl;
    return 0;
}

int OptionPointCloud::RunMeasureTruck(){
    //测量车身尺寸
    std::cout<<"测量车身尺寸"<<std::endl;
    return 0;
}

int OptionPointCloud::RunLocateWheel(){
    //定位分割车身部件
    std::cout<<"定位车身部件，轮胎，栏板"<<std::endl;
    return 0;
}

int OptionPointCloud::RunMeasureWheelbase(){
    //测量轴距，栏板高度
    std::cout<<"车辆轴距，栏板高度"<<std::endl;
    return 0;
}


void OptionPointCloud::set_truck_length(double length){
    truck_length_ = length;
}
void OptionPointCloud::set_truck_width(double width){
    truck_width_ = width;
}
void OptionPointCloud::set_truck_height(double height){
    truck_height_ = height;
}
void OptionPointCloud::set_wheelbase(double wheelbase){
    wheelbase_ = wheelbase;
}
void OptionPointCloud::set_backboard(double backboard){
    backboard_ = backboard;
}
double OptionPointCloud::get_truck_length(){
    return truck_length_;
}
double OptionPointCloud::get_truck_width(){
    return truck_width_;
}
double OptionPointCloud::get_truck_height(){
    return truck_height_;
}
double OptionPointCloud::get_wheelbase(){
    return wheelbase_;
}
double OptionPointCloud::get_backboard(){
    return backboard_;
}