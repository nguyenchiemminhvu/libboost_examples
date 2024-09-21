#include <iostream>
#include <boost/filesystem.hpp>

int main()
{
    boost::filesystem::path curFile(boost::filesystem::current_path() / "filesystem_file_status");
    boost::filesystem::file_status fStat = boost::filesystem::status(curFile);
    if (boost::filesystem::exists(curFile))
    {
        std::cout << "File type: " << fStat.type() << std::endl;
        std::cout << "File permission: " << fStat.permissions() << std::endl;

        if (boost::filesystem::is_regular_file(curFile))
        {
            std::cout << "Just a regular file " << boost::filesystem::file_size(curFile) << " bytes" << std::endl;
        }
        else if (boost::filesystem::is_directory(curFile))
        {
            std::cout << "A directory" << std::endl;
        }
    }
    return 0;
}