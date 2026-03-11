#ifndef _FILE_STSTEM_HPP_
#define _FILE_STSTEM_HPP_

#include <filesystem>
#include <vector>
#include <string>

class Filesystem {

public:

    Filesystem();
    std::vector<std::string> get_current_objects();


private:
    std::filesystem::path current_path;
};

#endif
