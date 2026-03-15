#ifndef _FILE_STSTEM_HPP_
#define _FILE_STSTEM_HPP_

#include <filesystem>
#include <vector>
#include <string>

class Filesystem {

public:

    Filesystem();
    std::vector<std::string>    get_objects();
    void                        set_objects(std::filesystem::path path);
    void                        clear_objects();
    std::filesystem::path       get_current_path();
    bool                        set_current_path(const std::string& new_path);


private:

    std::vector<std::string>    objects;
    std::filesystem::path       current_path;
};

#endif
