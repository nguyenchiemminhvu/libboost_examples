#include <iostream>
#include <thread>
#include <chrono>
#include <boost/program_options.hpp>

void worker_thread(int sec)
{
    std::cout << "Worker is working" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(sec));
    std::cout << "Worker done its job" << std::endl;
}

void consume_thread()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "Consume product" << std::endl;
    }
}

void spawn_worker_thread(int sec)
{
    std::cout << "spawn_worker_thread for " << sec << " seconds" << std::endl;

    std::thread t_worker(worker_thread, sec);
    t_worker.join();
}

void spawn_consume_thread()
{
    std::cout << "spawn_consume_thread" << std::endl;

    std::thread t_consume(consume_thread);
    t_consume.detach();
}

int main(int argc, char** argv)
{
    boost::program_options::options_description desc("Options");
    desc.add_options()
        ("help,h", "Print usage")
        ("time,t", boost::program_options::value<int>()->required()->notifier(spawn_worker_thread), "Duration of the worker thread")
        ("consume,c", "Spawn consume thread");
    
    boost::program_options::variables_map vm;

    try
    {
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        if (vm.find("help") != vm.end())
        {
            std::cout << desc << std::endl;
            return 0;
        }

        if (vm.find("consume") != vm.end())
        {
            spawn_consume_thread();
        }

        boost::program_options::notify(vm);
    }
    catch(const boost::program_options::error& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}