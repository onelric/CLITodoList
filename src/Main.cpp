#include <iostream>
#include <sstream>
#include <string>

#include "Renderer.hpp"
#include "Task.hpp"
#include "Util.hpp"

void Program()
{
    Renderer* renderer = new Renderer();

    std::cout << "Enter tasks:" << std::endl;
    while (true)
    {
        std::string line;
        getline(std::cin, line);

        std::string lowerCaseLine;
        for (char& c : line)
            lowerCaseLine.push_back(std::tolower(c));

        if (lowerCaseLine == "done")
            break;
        else 
            renderer->PushTask(Task(line));
    }

    renderer->RenderTasks();

    std::cout << "Enter Task to mark as finished! Number from 1 to " << renderer->GetTasks().size() << " separated with ,."<< std::endl;

    std::string indices;
    getline(std::cin, indices);

    std::vector<unsigned int> indicesToChange;
    std::vector<std::string> splits = split(indices, ",");
    for (int i = 0; i < splits.size(); i++) 
    {
        if (splits[i] == ",")
            splits.erase(std::next(splits.begin(), i));

        unsigned int index;
        std::stringstream stream;
        stream << splits[i];
        stream >> index;
        indicesToChange.push_back(index);
    }

    for (auto index : indicesToChange)
        renderer->GetTask(index-1).SetFinished();

    renderer->RenderTasks();

    delete renderer;
}


// This is the beginning of a horribly structured todo list
int main()
{
    Program();
    return 0;
}
