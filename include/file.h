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

#endif // FILE_H