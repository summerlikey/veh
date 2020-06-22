#ifndef OPTIONIMAGE_H
#define OPTIONIMAGE_H

#include<iostream>
#include<vector>
#include"opencv2/opencv.hpp"
class OptionImage
{
public:
    OptionImage();
    //读取图片
    void read_images(std::string images_path);
    //调用图片分割模型入口
    int RunImagesSegmentation(std::string images_src_path,std::string images_mask_path);
    //调用colmap入口
    int RunColmap(std::string colmap_work_path,std::string colmap_out_path);
    //调用mvs入口
    int RunMVS(std::string mvs_work_path,std::string mvs_out_path);
private:
    //path
    std::string pattern_jpg_;
    //all images path
    std::vector<cv::String> images_files_;
    //save src image in vector
    std::vector<cv::Mat> src_images_;
    //flit images
    std::vector<cv::Mat> flit_images_;//TODO
};

#endif // OPTIONIMAGE_H