#include <iostream>
#include <boost/system/error_code.hpp>

enum demo_errors
{
    success = 0,
    demo_initialize_failed,
    demo_invalid_argument,
    demo_invalid_operation
};

class demo_error_category : public boost::system::error_category
{
public:
    virtual const char* name() const noexcept override
    {
        return "demo_error_category";
    }

    virtual std::string message(int ec) const override
    {
        switch (ec)
        {
            case demo_errors::success: return "demo success";
            case demo_errors::demo_initialize_failed: return "demo initialization failed";
            case demo_errors::demo_invalid_argument: return "demo invalid argument";
            case demo_errors::demo_invalid_operation: return "invalid operation";
        }

        return "";
    }

    virtual boost::system::error_condition default_error_condition(int ev) const noexcept override
    {
        if (ev >= 2)
        {
            return boost::system::errc::make_error_condition(boost::system::errc::operation_not_permitted);
        }
        return boost::system::error_condition(ev, *this);
    }
};

const boost::system::error_category& demo_category()
{
    static demo_error_category instance;
    return instance;
}

void do_something(boost::system::error_code& ec)
{
    ec = boost::system::error_code(demo_errors::demo_invalid_operation, demo_category());
}

int main()
{
    boost::system::error_code ec;

    do_something(ec);

    if (ec.failed())
    {
        std::cerr << "Error: " << ec.message() << std::endl;
        std::cerr << "Error value: " << ec.value() << std::endl;
        std::cerr << "Error category: " << ec.category().name() << std::endl;
        std::cerr << "Error condition: " << ec.default_error_condition().message() << std::endl;
    }
    else
    {
        std::cout << "Operation succeeded." << std::endl;
    }

    return 0;
}