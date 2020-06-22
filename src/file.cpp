#include"file.h"


bool ExistsDir(const std::string& path) {
    return boost::filesystem::is_directory(path);
}

void CreateDirIfNotExists(const std::string& path) {
    if (!ExistsDir(path)) {
        boost::filesystem::create_directory(path);
    }
}

int CreateDirById(const std::string& path,const std::string& id){
    if(!ExistsDir(path)){
        //如果上级目录不存在
        std::cout<<"the path "<<path<<" not exist"<<std::endl;
        return -1;
    }
    std::string path_ = path + "/" + id;
    CreateDirIfNotExists(path + "/" + id);
    return 0;
}

int CreateDirById(const std::string& path,const int& id){
    std::string id_ = std::to_string(id);
    if(!ExistsDir(path)){
        //如果上级目录不存在
        std::cout<<"the path "<<path<<" not exist"<<std::endl;
        return -1;
    }
    CreateDirIfNotExists(path + "/" + id_);
    return 0;
}