#include "filesystem.hpp"
#include <iostream>

Filesystem::Filesystem()
    : current_path(std::filesystem::current_path()),
    objects({}),
    forbiden_ext({".obj", ".exe", ".dll"})
{

}

std::vector<std::string> Filesystem::get_objects()
{
    return this->objects;
}

size_t Filesystem::get_objects_size()
{
    return this->objects.size();
}

void Filesystem::set_objects(std::filesystem::path path)
{   
    clear_objects();
    this->objects.push_back(".."); 

    try {
        for (const auto& it : std::filesystem::directory_iterator(path))
        {
            this->objects.push_back(it.path().filename().string());
        }
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error reading directory: " << e.what() << '\n';
    }
}

void Filesystem::clear_objects()
{
    this->objects.clear();
}

std::filesystem::path Filesystem::get_current_path()
{
    return this->current_path;
}


void Filesystem::set_current_path(const std::string& new_path)
{
    std::filesystem::path path_obj(new_path);  
    std::filesystem::current_path(path_obj);  
    this->current_path = std::filesystem::current_path(); 
}

bool Filesystem::is_filename_forbidden(const std::string& filename)
{
    for (const auto& ext : forbiden_ext)
    {
        if (filename.find(ext) != std::string::npos)
            return true;
    }
    return false;
}