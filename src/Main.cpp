#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "Renderer.hpp"
#include "Task.hpp"
#include "Util.hpp"

using std::cout, std::endl, std::cin, std::getline, std::string;

void RenderTasksTask(Renderer& renderer)
{
    // Clear terminal
    system("clear");
    // Print title
    cout << "    __--~Tasks~--__\n" << endl;

    // Render tasks
    for (auto& task : renderer.GetTasks())
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
        cout << " " << prefix << " " << task.GetName() << endl;
    }
}

void Program()
{
    // Create renderer
    Renderer renderer{};

    for (int i = 0; i < 3; i++)
    {
        std::string taskName;
        getline(cin, taskName);
        renderer.PushTask(Task(taskName));
    }

    RenderTasksTask(renderer);

    cout << " Enter Task to highligh as finished! Enter number from 1 to " << renderer.GetTasks().size() << " separated with ,."<< endl;

    std::vector<unsigned int> indicesToChange;
    std::string indices;
    getline(cin, indices);
    std::vector<std::string> splits = split(indices, ",");
    for (int i = 0; i < splits.size(); i++) 
    {
        if (splits[i] == ",")
            splits.erase(std::next(splits.begin(), i));
        indicesToChange.push_back(i + 1);
    }

    for (auto index : indicesToChange)
        renderer.GetTask(index).SetFinished();

    RenderTasksTask(renderer);
}


int main()
{
    Program();

    return 0;
}
