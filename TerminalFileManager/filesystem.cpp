#include "filesystem.hpp"
#include <iostream>

Filesystem::Filesystem()
    : current_path(std::filesystem::current_path()),
    objects({})
{
}

std::vector<std::string> Filesystem::get_objects()
{
    return this->objects;
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


bool Filesystem::set_current_path(const std::string& new_path)
{
    try {
        std::filesystem::path path_obj(new_path);  
        std::filesystem::current_path(path_obj);  
        this->current_path = std::filesystem::current_path(); 
        return true;
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error changing path: " << e.what() << '\n';
        return false;
    }
    return true;
}