#include "Task.hpp"

Task::Task(const std::string& name) : m_Name(name), m_Completed(false), m_State(State::Todo)
{

}

void Task::SetFinished() { m_State = State::Finished; }
