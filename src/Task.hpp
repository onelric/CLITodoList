#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
#include <string>

enum State 
{
    Finished,
    Todo,
};

class Task
{
public:
    Task(const std::string&);

    bool IsComplete() const { return m_Completed; }

    const std::string& GetName() const { return m_Name; }
    const std::string& GetDesc() const { return m_Description; }

    State GetState() const { return m_State; }

    void SetFinished();

private:
    const std::string m_Name;
    const std::string m_Description;
    bool m_Completed;
    State m_State;
};

#endif
