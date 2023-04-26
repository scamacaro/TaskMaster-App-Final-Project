//This is a preprocessor directive that ensures that 
//this header file is only included once during compilation, even if it is referenced multiple times.
#pragma once

// Includes the standard C++ library header file for the 
// std::vector container, 
// which is a dynamic array that can resize itself automatically as elements are added or removed.
#include <vector> 
// includes the header file for the Task class. 
#include "Task.h"

// Begins the definition of the TaskManager class.
class TaskManager {
    //  Indicates that the following members of the class are private and can
    // only be accessed within the class itself.
private:
    std::vector<Task*> tasks;

    // Indicates that the following members of the class are 
    // public and can be accessed from outside the class.
public:
    ~TaskManager();

    void addTask(Task* task);
    void removeTask(size_t index);
    void displayTasks() const;
    void clearTasks();
};

