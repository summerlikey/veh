#include "optionimage.h"

OptionImage::OptionImage()
{

}

void OptionImage::read_images(std::string images_path)
{
    pattern_jpg_ = images_path;
    //maybe error if no images
    cv::glob(pattern_jpg_, images_files_);

    for(unsigned long i=0;i<images_files_.size();i++)
    {

        cv::Mat image=cv::imread(images_files_[i]);
        if(image.empty()){
            std::cout<<"no images"<<std::endl;
            break;
        }
        cv::imshow("image",image);
        cvWaitKey(0);
        src_images_.push_back(image);
    }
}

int OptionImage::RunImagesSegmentation(std::string images_src_path,std::string images_mask_path){
    //图像分割
    //输入参数:源图像路径,分割后储存路径
    std::cout<<"图像分割"<<std::endl;
    std::cout<<"源图像路径"<<images_src_path<<std::endl;
    std::cout<<"分割图像路径"<<images_mask_path<<std::endl;

    return 0;
}

int OptionImage::RunColmap(std::string colmap_work_path,std::string colmap_out_path){
    //colmap
    //输入参数:工作路径，输出文件夹路径(包括稀疏点云，相机内参，位姿，矫正后图像)
    std::cout<<"colmap"<<std::endl;
    std::cout<<"colmap路径"<<colmap_work_path<<std::endl;
    std::cout<<"colmap输出路径"<<colmap_out_path<<std::endl;
    return 0;
}

int OptionImage::RunMVS(std::string mvs_work_path,std::string mvs_out_path){
    //mvs
    //输入参数:colmap的输出文件夹，输出点云数据
    std::cout<<"mvs"<<std::endl;
    std::cout<<"mvs工作路径"<<mvs_work_path<<std::endl;
    std::cout<<"mvs输出路径"<<mvs_out_path<<std::endl;
    return 0;
}

