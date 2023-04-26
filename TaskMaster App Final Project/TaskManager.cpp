// Include the header file "TaskManager.h" to access the TaskManager class and its members.
#include "TaskManager.h"

TaskManager::~TaskManager() { // TaskManager class destructor definition.
    clearTasks(); // // Call the clearTasks() member function to clear and delete all tasks in the tasks vector.
}

void TaskManager::addTask(Task* task) { // Member function addTask() definition that takes a pointer to a Task object as an argument.
    tasks.push_back(task); // Add the Task object pointer to the tasks vector.
}

void TaskManager::removeTask(size_t index) { // Member function removeTask() definition that takes an index of type size_t as an argument.
    if (index < tasks.size()) { // Check if the index is within the range of the tasks vector.
        delete tasks[index]; // Delete the Task object pointed to by the element at the given index in the tasks vector.
        tasks.erase(tasks.begin() + index);// Remove the element at the given index from the tasks vector.
    }
}

void TaskManager::displayTasks() const { // Member function displayTasks() definition, declared as const to indicate that it does not modify the TaskManager object.
    for (const auto& task : tasks) { // Range-based for loop iterating through each task in the tasks vector.
        task->display(); // Call the display() member function of the Task object pointed to by the current task pointer.
        std::cout << std::endl; // Print a newline character to separate the displayed tasks.
    }
}

void TaskManager::clearTasks() { // Member function clearTasks() definition.
    for (auto& task : tasks) { // Range-based for loop iterating through each task in the tasks vector.
        delete task; // Delete the Task object pointed to by the current task pointer.
    }
    tasks.clear(); // Clear all elements from the tasks vector.
}
