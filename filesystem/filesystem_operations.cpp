#include <iostream>
#include <boost/filesystem.hpp>

int main()
{
    boost::filesystem::path from(boost::filesystem::current_path());
    boost::filesystem::path to(boost::filesystem::current_path() / "backup");

    if (!boost::filesystem::exists(to))
    {
        boost::filesystem::create_directories(to);
    }

    for (boost::filesystem::recursive_directory_iterator iter(from); iter != boost::filesystem::recursive_directory_iterator(); iter++)
    {
        if (iter->path().string().find("backup") != std::string::npos)
        {
            continue;
        }

        try
        {
            const boost::filesystem::path relative_path(boost::filesystem::relative(iter->path()));
            const boost::filesystem::path target_path(to / relative_path);

            if (boost::filesystem::is_directory(iter->status()))
            {
                if (!boost::filesystem::exists(target_path))
                {
                    boost::filesystem::create_directories(target_path);
                }
            }
            else if (boost::filesystem::is_regular_file(iter->status()))
            {
                boost::filesystem::copy_file(iter->path(), target_path, boost::filesystem::copy_options::overwrite_existing);
            }
        }
        catch (const std::exception& ex)
        {
            std::cerr << ex.what() << std::endl;
        }
    }

    return 0;
}