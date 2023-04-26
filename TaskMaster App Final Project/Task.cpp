// This line includes the header file Task.h, which likely contains the declaration of the Task class.
#include "Task.h"

//This is the implementation of the Task constructor, which takes two arguments: a title string and a dueDate string. 
Task::Task(const std::string& title, const std::string& dueDate) : title(title), dueDate(dueDate) {}

//This is the implementation of the getTitle method, which returns the title member variable. 
std::string Task::getTitle() const {
    return title;
}

//This is the implementation of the setTitle method, 
//which sets the title member variable to the value passed in as an argument.
void Task::setTitle(const std::string& title) {
    this->title = title;
}

//This is the implementation of the getDueDate method, 
//which returns the dueDate member variable. 
std::string Task::getDueDate() const {
    return dueDate;
}

//This is the implementation of the setDueDate method, 
//which sets the dueDate member variable to the value passed in as an argument.
void Task::setDueDate(const std::string& dueDate) {
    this->dueDate = dueDate;
}

//This is the implementation of the display method, 
//which prints out the title and dueDate member variables to the console in a formatted string. 
void Task::display() const {
    std::cout << "Title: " << title << ", Due Date: " << dueDate;
}
