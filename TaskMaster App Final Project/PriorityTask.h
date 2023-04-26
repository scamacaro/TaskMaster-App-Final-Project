//This is a preprocessor directive that ensures that 
//this header file is only included once during compilation, even if it is referenced multiple times.
#pragma once

//This line includes the header file for the Task class, which this PriorityTask class inherits from.
#include "Task.h"

//This line declares a new class called PriorityTask that inherits publicly from the Task class.
class PriorityTask : public Task {
private:
    int priority;

public:
    PriorityTask(const std::string& title, const std::string& dueDate, int priority);
    ~PriorityTask() override = default;

    int getPriority() const;
    void setPriority(int priority);

    void display() const override;
};

