#include "filesystem.hpp"

Filesystem::Filesystem()
    : current_path(std::filesystem::current_path())
{
}

std::vector<std::string> Filesystem::get_current_objects()
{
    std::vector<std::string> objects;

    objects.push_back("..");

    for (auto& it : std::filesystem::directory_iterator(current_path))
    {
        objects.push_back(it.path().filename().string());
    }

    return objects;
}

bool Filesystem::execute_enter(std::string new_path)
{
    return true;
}
