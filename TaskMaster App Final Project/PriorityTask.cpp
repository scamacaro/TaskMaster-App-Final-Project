// This line includes the header file "PriorityTask.h", 
//which contains the declaration of the PriorityTask class.
#include "PriorityTask.h"

//This is the constructor for the PriorityTask class. It takes three parameters - title, dueDate, and priority.
PriorityTask::PriorityTask(const std::string& title, const std::string& dueDate, int priority)
    : Task(title, dueDate), priority(priority) {}

//This is a member function of the PriorityTask class that returns the value of the priority member variable.
int PriorityTask::getPriority() const {
    return priority;
}

//This is a member function of the PriorityTask class that sets the value of 
//the priority member variable to the value of the priority parameter.
void PriorityTask::setPriority(int priority) {
    this->priority = priority;
}

//This is a member function of the PriorityTask class that displays the title, 
//due date, and priority of the task.
void PriorityTask::display() const {
    Task::display();
    std::cout << ", Priority: " << priority;
}
