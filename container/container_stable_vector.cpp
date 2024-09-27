#include <iostream>
#include <string>
#include <boost/container/stable_vector.hpp>

class Task
{
public:
    Task(std::string name) : name(name) {}
    std::string getName() const { return name; }

private:
    std::string name;
};

class TaskManager
{
public:
    void addTask(const std::string& taskName)
    {
        tasks.emplace_back(taskName);
    }

    void removeTask(size_t index)
    {
        if (index < tasks.size())
        {
            tasks.erase(tasks.begin() + index);
        }
        else
        {
            std::cout << "Invalid index.\n";
        }
    }

    void displayTasks() const
    {
        if (tasks.empty())
        {
            std::cout << "No tasks available.\n";
            return;
        }
        std::cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            std::cout << i + 1 << ". " << tasks[i].getName() << "\n";
        }
    }

private:
    boost::container::stable_vector<Task> tasks;
};

int main()
{
    TaskManager manager;

    // Adding tasks
    manager.addTask("Write report");
    manager.addTask("Attend meeting");
    manager.addTask("Send emails");

    // Display tasks
    manager.displayTasks();

    // Remove a task
    manager.removeTask(1); // Remove "Attend meeting"

    // Display tasks again
    manager.displayTasks();

    return 0;
}
