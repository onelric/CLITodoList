#include "Renderer.hpp"

Renderer::Renderer()
{
    system("clear");
}

void Renderer::RenderTasks()
{
    system("clear");
    std::cout << "   __--~Tasks~--__\n" << std::endl;

    for (auto& task : GetTasks())
    {
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
