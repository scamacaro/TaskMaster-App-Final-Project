# TaskMaster-App-Final-Project
/** Sanyerlis Camacaro- CSC275 - Sancamac@uat.edu Assignment: TaskMaster App Final Project
This code demonstrates:

An opening screen with a description of the application and instructions.
A menu for the user to choose options, such as creating a task, viewing tasks, and exiting the application.
Encapsulation: All class attributes will be private, with public getter and setter functions.
Polymorphism: The Task class will have a virtual "display" function, which will be overridden
in the derived Category and PriorityTask classes. The application will also use operator
overloading to compare task due dates.
Multi-threading: The application will use multiple threads to handle user input
and manage the task list simultaneously.
Exception handling: The application will have proper error handling for invalid
inputs and other possible exceptions.

The TaskMaster application  consist of the following classes:

Task
Category (derived from Task)
PriorityTask (derived from Task)
TaskManager
Here's a brief overview of each class:

Task: Represents a basic task with a title and due date.
Category: Inherits from the Task class and adds a category attribute.
PriorityTask: Inherits from the Task class and adds a priority attribute.
TaskManager: Handles the overall management of tasks, including adding, editing, and deleting tasks.
The application will feature the following functionalities:



*/
#include <iostream> // includes input and out as the standard library.
#include <stdexcept> // This line includes the standard exception class library, which is used for error handling.
// These lines include custom header files for the program.
#include "TaskManager.h"
#include "Task.h"
#include "Category.h"
#include "PriorityTask.h"

using namespace std; // means using standard namespace and that I dont have to type std:: in front of each line.

void displayOpeningScreen(); // This line declares a function called.
void displayMenu(); // This line declares a function called displayMenu that takes no arguments 
// and returns nothing.
int getMenuChoice();// This line declares a function called getMenuChoice that takes 
//no arguments and returns an integer.
void performMenuAction(TaskManager& taskManager, int choice); // This line declares a function 
//called performMenuAction that takes a TaskManager object and an integer choice as arguments and returns nothing.

//This line marks the beginning of the main function, which is the entry point of the program.
int main() {
    TaskManager taskManager; // This line creates a TaskManager object called taskManager.
    displayOpeningScreen(); //  This line calls the displayOpeningScreen function to display 
    //the opening screen of the program.

    while (true) { // This line starts an infinite loop.
        displayMenu(); // This line calls the displayMenu function to display the main menu options.
        int choice = getMenuChoice(); // This line calls the getMenuChoice function to get the user's 
        //choice and assigns it to the choice variable.
        performMenuAction(taskManager, choice); //This line calls the performMenuAction function 
        //to perform the selected action based on the user's choice.
    }

    return 0; // This line marks the end of the main function and returns 0 
    // to indicate successful program execution.
}

void displayOpeningScreen() { //  This line starts the implementation of the displayOpeningScreen function.
    cout << "\nWelcome to TaskMaster!\n" << endl;
    cout << "\nTaskMaster helps you manage and organize your tasks.\n" << endl;
    cout << "\nFollow the menu options to create, view, or remove tasks.\n" << endl;
}

void displayMenu() { // This line starts the implementation of the displayMenu function.
    cout << "\nMenu Options:\n" << endl;
    cout << "1. Create Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Remove Task" << endl;
    cout << "4. Exit" << endl;
}

int getMenuChoice() { // This line starts the implementation of the getMenuChoice function.
    int choice;
    cout << "\nEnter your choice (1-4): \n";
    cin >> choice;

    while (choice < 1 || choice > 4) {
        cout << "Invalid input. Please enter a number between 1 and 4: ";
        cin >> choice;
    }

    return choice;
}
// This line starts the implementation of the performMenuAction 
//function, which takes a TaskManager object and an integer choice as arguments.
void performMenuAction(TaskManager& taskManager, int choice) { 
    // This line declares three string variables
    string title, dueDate, category;
    //This line declares two integer variables 
    int priority, taskIndex;

    //This line starts a switch statement based on the user's choice.
    switch (choice) {
    case 1:
        cout << "Enter task title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter task due date (YYYY-MM-DD): ";
        cin >> dueDate;

        cout << "Enter task type (1 - Basic, 2 - Category, 3 - Priority): ";
        cin >> taskIndex;

        if (taskIndex == 2) {
            cout << "Enter task category: ";
            cin.ignore();
            getline(cin, category);
            taskManager.addTask(new Category(title, dueDate, category));
        }
        else if (taskIndex == 3) {
            cout << "Enter task priority (1-5): ";
            cin >> priority;
            taskManager.addTask(new PriorityTask(title, dueDate, priority));
        }
        else {
            taskManager.addTask(new Task(title, dueDate));
        }

        cout << "Task created successfully!" << endl;
        break;

    case 2:
        cout << "\nTasks:" << endl;
        taskManager.displayTasks();
        break;

    case 3:
        cout << "Enter the index of the task to remove: ";
        cin >> taskIndex;
        taskManager.removeTask(taskIndex);
        cout << "Task removed successfully!" << endl;
        break;

    case 4:
        cout << "Exiting TaskMaster. Goodbye!" << endl;
        taskManager.clearTasks();
        exit(0);
        break;

    default:
        cerr << "An unexpected error occurred." << endl;
        break;
    }
}

