#include <iostream>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>
#include <boost/system/result.hpp>

boost::system::result<int> do_operation_1()
{
    return 10;
}

boost::system::result<int> do_operation_2()
{
    return boost::system::errc::make_error_code(boost::system::errc::operation_canceled);
}

boost::system::result<int> combined_operations()
{
    boost::system::result<int> res1 = do_operation_1();
    if (res1.has_error())
    {
        return res1;
    }

    boost::system::result<int> res2 = do_operation_2();
    if (res2.has_error())
    {
        return res2;
    }

    return res1.value() + res2.value();
}

int main()
{
    boost::system::result<int> res = combined_operations();
    if (res)
    {
        std::cout << "success: " << res.value() << std::endl;
    }
    else
    {
        std::cout << "failed: " << res.error().message() << std::endl;
    }

    return 0;
}