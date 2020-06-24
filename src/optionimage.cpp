#include "optionimage.h"

OptionImage::OptionImage()
{

}

int OptionImage::RunPythonMVSModule(const char * c_str){
    //封装python函数
    int res = 0;
	PyObject *pName,*pModule,*pFunc;
	PyObject *pArgs,*pValue;
	/*  import  */
	//模块名
	const char *pModuleName = "mvstest";
	//函数名
    const char *pFunction = "test_string";
    pName = PyUnicode_DecodeFSDefault(pModuleName);
	pModule = PyImport_Import(pName);
	//释放指针
    Py_DECREF(pName);
    if (pModule != NULL){
        std::cout<<"find module: "<<std::endl;
        /*  指向函数  */
        pFunc = PyObject_GetAttrString(pModule,pFunction);
        if (pFunc && PyCallable_Check(pFunc)) {
            std::cout<<"find function"<<std::endl;
            /*　build args  */
            //传入参数，有几个参数写几个
            pArgs = PyTuple_New(1);
            //传入参数，将其传入pArgs中
            PyTuple_SetItem(pArgs,0,Py_BuildValue("s",c_str));
            /*  call回调  */
            pValue = PyObject_CallObject(pFunc,pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                printf("Result of call: %s\n", PyUnicode_AsUTF8(pValue));
                //return PyLong_AsLong(pValue);
                return 0;
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return 1;
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \n");
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else{
        printf("can not open module:\n");
        PyErr_Print();
        return 1;
    }
	return res;
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
    Py_Initialize();
    std::string path = "'/home/ganggang/Documents/colmap-test/veh/src'";
    std::string python_file_path = "sys.path.append(";
    python_file_path = python_file_path + path + ")" ;
    const char* c_python_file_path = python_file_path.c_str();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString(c_python_file_path);
    char const * c_str = "hello mvs";
    RunPythonMVSModule(c_str);
    //销毁解释器
    Py_Finalize();
    return 0;
}

