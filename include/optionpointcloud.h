#ifndef OPTIONPOINTCLOUD_H
#define OPTIONPOINTCLOUD_H
#include <iostream>
class OptionPointCloud{
public:
    OptionPointCloud();
    
    //调用点云滤波函数入口
    int RunPointCloudFilter();
    //调用点云拼接函数入口
    int RunPointCloudSplicing();
    //测量车辆尺寸
    int RunMeasureTruck();
    //定位分割车身部件(栏板，轮胎)
    int RunLocateWheel();
    //测量轴距，栏板高度
    int RunMeasureWheelbase();

    //设置值
    void set_truck_length(double length);
    void set_truck_width(double width);
    void set_truck_height(double height);
    void set_wheelbase(double wheelbase);
    void set_backboard(double backboard);
    //获得值
    double get_truck_length();
    double get_truck_width();
    double get_truck_height();
    double get_wheelbase();
    double get_backboard();

private:
    //长宽高
    double truck_length_;
    double truck_width_;
    double truck_height_;

    //轴距
    double wheelbase_;
    //栏板高度
    double backboard_;
};
#endif // OPTIONPOINTCLOUD_H