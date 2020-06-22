#ifndef FILE_H
#define FILE_H
#include<iostream>
#include<string>
#include <fstream>
#include<boost/filesystem.hpp>

//dir is exist
bool ExistsDir(const std::string& path);
//if not creat dir
void CreateDirIfNotExists(const std::string& path);
//create the dir by car id
int CreateDirById(const std::string& path,const std::string& id);
//int
int CreateDirById(const std::string& path,const int& id);

#endif // FILE_H