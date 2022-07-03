#include "Renderer.hpp"

void Renderer::PushTask(Task task)
{
    m_Tasks.push_back(task);
}

Task& Renderer::GetTask(unsigned int index)
{
    return m_Tasks[index];
}

void Renderer::RenderTasks()
{
    system("clear");
    std::cout << "      __--~Tasks~--__\n" << std::endl;

    for (auto& task : GetTasks())
    {
        if (task.GetName() == "FinishedTask")
            task.SetFinished();

        char prefix = '*';
        switch (task.GetState())
        {
            case State::Finished:
                prefix = 'J';
                break;
            case State::Todo:
                prefix = '*';
                break;
        }

        std::cout << " " << prefix << " " << task.GetName() << std::endl;
    }
}
