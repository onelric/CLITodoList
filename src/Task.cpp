#include "Task.hpp"

Task::Task(const std::string& name) : m_Name(name)
{

}

void Task::SetFinished() { m_State = State::Finished; }
