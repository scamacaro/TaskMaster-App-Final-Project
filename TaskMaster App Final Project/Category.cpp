// This line includes the header file "Category.h" that contains the declaration of the Category class.
#include "Category.h"

//This is the constructor for the Category class that takes three std::string arguments: title, dueDate, and category.
Category::Category(const std::string& title, const std::string& dueDate, const std::string& category)
    : Task(title, dueDate), category(category) {}

//This is a member function of the Category class that returns the value of the category member variable.
std::string Category::getCategory() const {
    return category;
}

//This is a member function of the Category class that sets the value of 
//the category member variable to the value of the category argument.
void Category::setCategory(const std::string& category) {
    this->category = category;
}

// This is a member function of the Category class that displays the 
//title and dueDate members of the Task base class using Task::display()
void Category::display() const {
    Task::display();
    std::cout << ", Category: " << category;
}
