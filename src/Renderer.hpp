#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>
#include "Task.hpp"

class Renderer
{
public:
    Renderer(); 

    void RenderTasks();

    std::vector<Task> GetTasks() const { return m_Tasks; }
    Task& GetTask(unsigned int index) { return m_Tasks[index]; }

    void PushTask(Task task) { m_Tasks.push_back(task); }
private:
    std::vector<Task> m_Tasks;
};

#endif
