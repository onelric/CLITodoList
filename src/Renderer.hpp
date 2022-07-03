#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>
#include "Task.hpp"

class Renderer
{
public:
    std::vector<Task> GetTasks() const { return m_Tasks; }

    void PushTask(Task);
    Task& GetTask(unsigned int);
private:
    std::vector<Task> m_Tasks;
};

#endif
