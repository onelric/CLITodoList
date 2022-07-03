#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>
#include "Task.hpp"

class Renderer
{
public:
    void RenderTasks();

    std::vector<Task> GetTasks() const { return m_Tasks; }
    Task& GetTask(unsigned int);

    void PushTask(Task);
private:
    std::vector<Task> m_Tasks;
};

#endif
