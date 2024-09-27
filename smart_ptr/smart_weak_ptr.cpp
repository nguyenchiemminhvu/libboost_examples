#include <iostream>
#include <boost/weak_ptr.hpp>
#include <boost/make_shared.hpp>

class Resource;
class Owner
{
public:
    Owner()
    {

    }

    ~Owner()
    {

    }

    void set_resource(const boost::shared_ptr<Resource>& res)
    {
        res_ptr = res;
    }

    void use_resource()
    {
        boost::shared_ptr<Resource> res = res_ptr.lock();
        if (static_cast<bool>(res))
        {
            std::cout << "Owner is using the resource" << std::endl;
        }
    }

private:
    boost::weak_ptr<Resource> res_ptr;
};

class Resource
{
public:
    Resource()
    {

    }

    ~Resource()
    {

    }

    void use_resource()
    {
        std::cout << "Use resource by itself" << std::endl;
    }
};

int main()
{
    boost::shared_ptr<Resource> res = boost::make_shared<Resource>();
    boost::shared_ptr<Owner> owner = boost::make_shared<Owner>();
    owner->set_resource(res);

    owner->use_resource();
    res->use_resource();

    return 0;
}