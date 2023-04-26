//This is a preprocessor directive that ensures that 
//this header file is only included once during compilation, even if it is referenced multiple times.
#pragma once

//This line includes the header file "Task.h" in this file, so that the compiler can access its declarations.
#include "Task.h"

//This line declares a new class called "Category" that publicly inherits from the "Task" class.
class Category : public Task {
    // This line declares a private member variable called "category" of type "std::string" in the "Category" class.
private:
    std::string category;

public:
    Category(const std::string& title, const std::string& dueDate, const std::string& category);
    ~Category() override = default;

    std::string getCategory() const;
    void setCategory(const std::string& category);

    void display() const override;
};

