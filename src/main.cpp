#include "iostream"
#include "optionimage.h"
#include "optionpointcloud.h"
#include "file.h"
using namespace std;
int main()
{
    cout<<"veh 3.0"<<endl;

    //get image
    //veh images number
    string veh_images_number = "images_src_01";
    //source path
    string source_path = "data/" + veh_images_number;
    //work path
    CreateDirIfNotExists("work");
    string work_path = "work/" + veh_images_number;
    CreateDirIfNotExists(work_path);
    //left image dir
    string left_image_path =  source_path + "/left_src_images";
    string right_image_path = source_path + "/right_src_images";

/*图片转点云*/
    //左边图像生成点云
    OptionImage leftOptionImages;
    //左边读图片
    string left_image_name = left_image_path +"/*.JPG";
    leftOptionImages.read_images(left_image_path);
    //左边图片分割后存储文件夹子
    //左边分割存储图片文件夹
    string left_mask_images_path = work_path + "/left_mask_images";
    CreateDirIfNotExists(left_mask_images_path);
    //图像分割输入左边图片文件夹，和输出分割后图片文件夹
    leftOptionImages.RunImagesSegmentation(left_image_path,left_mask_images_path);
    //Colmap
    string left_colmap_out_path = work_path + "/left_colmap";
    CreateDirIfNotExists(left_colmap_out_path);
    leftOptionImages.RunColmap(left_mask_images_path,left_colmap_out_path);
    //mvs
    string left_mvs_out_path = work_path + "/left_mvs";
    CreateDirIfNotExists(left_mvs_out_path);
    leftOptionImages.RunMVS(left_colmap_out_path,left_mvs_out_path);

    //右边图像生成点云
    OptionImage rightOptionImages;
    //左边读图片
    string right_image_name = right_image_path +"/*.JPG";
    rightOptionImages.read_images(right_image_path);
    //左边图片分割后存储文件夹子
    //左边分割存储图片文件夹
    string right_mask_images_path = work_path + "/right_mask_images";
    CreateDirIfNotExists(right_mask_images_path);
    //图像分割输入左边图片文件夹，和输出分割后图片文件夹
    rightOptionImages.RunImagesSegmentation(right_image_path,right_mask_images_path);
    //Colmap
    string right_colmap_out_path = work_path + "/right_colmap";
    CreateDirIfNotExists(right_colmap_out_path);
    rightOptionImages.RunColmap(right_mask_images_path,right_colmap_out_path);
    //mvs
    string right_mvs_out_path = work_path + "/right_mvs";
    CreateDirIfNotExists(right_mvs_out_path);
    rightOptionImages.RunMVS(right_colmap_out_path,right_mvs_out_path);

/*图片转点云*/

/*点云处理并测量*/
    OptionPointCloud optionPointCloud;
    //点云滤波
    optionPointCloud.RunPointCloudFilter();
    //点云拼接
    optionPointCloud.RunPointCloudSplicing();
    //测量车身尺寸
    optionPointCloud.RunMeasureTruck();
    //定位分割车身部件，轮胎，栏板
    optionPointCloud.RunLocateWheel();
    //测量轴距，栏板高度
    optionPointCloud.RunMeasureWheelbase();


/*点云处理并测量*/

    return 0;
}
