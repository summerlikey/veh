#include"file.h"


bool ExistsDir(const std::string& path) {
    return boost::filesystem::is_directory(path);
}

void CreateDirIfNotExists(const std::string& path) {
    if (!ExistsDir(path)) {
        boost::filesystem::create_directory(path);
    }
}