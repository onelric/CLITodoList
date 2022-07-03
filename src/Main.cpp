#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "Renderer.hpp"
#include "Task.hpp"
#include "Util.hpp"

void Program()
{
    // Create renderer
    Renderer* renderer = new Renderer();

    for (int i = 0; i < 3; i++)
    {
        std::string taskName;
        getline(std::cin, taskName);
        renderer->PushTask(Task(taskName));
    }

    renderer->RenderTasks();

    std::cout << " Enter Task to highligh as finished! Enter number from 1 to " << renderer->GetTasks().size() << " separated with ,."<< std::endl;

    std::vector<unsigned int> indicesToChange;
    std::string indices;
    getline(std::cin, indices);
    std::vector<std::string> splits = split(indices, ",");
    for (int i = 0; i < splits.size(); i++) 
    {
        if (splits[i] == ",")
            splits.erase(std::next(splits.begin(), i));
        indicesToChange.push_back(i + 1);
    }

    for (auto index : indicesToChange)
        renderer->GetTask(index).SetFinished();

    renderer->RenderTasks();

    delete renderer;
}


int main()
{
    Program();
    return 0;
}
