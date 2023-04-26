//This is a preprocessor directive that ensures that the header 
//file containing this code is included only once during compilation. 
//It prevents the multiple inclusions of the same header file and reduces compilation time.
#pragma once

//These are include directives that allow the usage of the string class and 
//input/output stream functions in the code.
#include <string>
#include <iostream>

//This line starts the declaration of a new class named "Task".
class Task {
    // These are the private member variables of the Task class that store the task's title and due date.
protected:
    std::string title;
    std::string dueDate;

public:
    //These are the public member functions of the Task class
    Task(const std::string& title, const std::string& dueDate);
    virtual ~Task() = default;

    std::string getTitle() const;
    void setTitle(const std::string& title);

    std::string getDueDate() const;
    void setDueDate(const std::string& dueDate);

    virtual void display() const;
};

