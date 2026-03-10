#include <filesystem>
#include <iostream>

int main()
{
    std::filesystem::path p = "test.txt";
    std::cout << p << std::endl;
}