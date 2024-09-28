#include <iostream>
#include <boost/heap/priority_queue.hpp>

struct Task
{
    int priority;
    std::string description;

    Task(int p, const std::string& desc) : priority(p), description(desc) {}
};

struct TaskComparator
{
    bool operator()(const Task& lhs, const Task& rhs) const
    {
        return lhs.priority < rhs.priority; // Max-heap by priority
    }
};

int main()
{
    boost::heap::priority_queue<Task, boost::heap::compare<TaskComparator>> taskQueue;

    taskQueue.push(Task(1, "Low priority task"));
    taskQueue.push(Task(3, "High priority task"));
    taskQueue.push(Task(2, "Medium priority task"));

    while (!taskQueue.empty())
    {
        Task topTask = taskQueue.top();
        std::cout << "Processing task: " << topTask.description
                  << " with priority: " << topTask.priority << std::endl;
        taskQueue.pop();
    }

    return 0;
}
