#include "Renderer.hpp"

void Renderer::PushTask(Task task)
{
    m_Tasks.push_back(task);
}

Task& Renderer::GetTask(unsigned int index)
{
    return m_Tasks[index];
}
