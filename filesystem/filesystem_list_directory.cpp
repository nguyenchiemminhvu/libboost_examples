#include <iostream>
#include <string>
#include <boost/filesystem.hpp>

void list_directories_non_recursive(const boost::filesystem::path& dir_path)
{
    for (boost::filesystem::directory_iterator iter(dir_path); iter != boost::filesystem::directory_iterator(); iter++)
    {
        if (boost::filesystem::is_directory(iter->status()))
        {
            std::cout << iter->path() << std::endl;
        }
    }
}

void list_directories_recursive(const boost::filesystem::path& dir_path)
{
    for (boost::filesystem::recursive_directory_iterator iter(dir_path); iter != boost::filesystem::recursive_directory_iterator(); iter++)
    {
        if (boost::filesystem::is_directory(iter->status()))
        {
            std::cout << iter->path() << std::endl;
        }
    }
}

void list_files_with_extension(const boost::filesystem::path& dir_path, const std::string& ext)
{
    for (boost::filesystem::recursive_directory_iterator iter(dir_path); iter != boost::filesystem::recursive_directory_iterator(); iter++)
    {
        if (boost::filesystem::is_regular_file(iter->status()) && iter->path().extension() == ext)
        {
            std::cout << iter->path() << std::endl;
        }
    }
}

int main()
{
    boost::filesystem::path cur_path(boost::filesystem::current_path());

    std::cout << "List all directories in current folder" << std::endl;
    list_directories_non_recursive(cur_path);

    std::cout << "List all directories recursively" << std::endl;
    list_directories_recursive(cur_path);

    std::cout << "List all .txt files recursively" << std::endl;
    list_files_with_extension(cur_path, ".txt");

    return 0;
}