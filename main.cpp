// written by Sofia Gratny
// september 27, 2022


#include "Task.h"
#include "Console.h"
#include <vector>


Task* getTask(Task*, int);
void displayTasks(Task*);
void removeTask(Task*, int);
void deleteLinks(Task*);


int main() {
    
    Task *head = new Task;
    Task *current = head;
    Task *task;
    bool quit = false;
    std::string desc;
    char option;
    int lp = 0;
    int n;

    while (!quit) {

        Console::displayOptions();
        option = Console::getCharInput("Please enter a valid option: ");

        switch(option) {

            case 'A':
                // add case

                lp += 1;
                task = new Task;
                desc = Console::getStringInput("Enter the task description: ");
                task -> setDesc(desc);
                current -> setLink(task);
                current = task;
                break;

            case 'C':
                // complete case

                if ( lp == 0 ) {
                    std::cout << "There aren't any tasks to mark completed!\n";
                    break;
                }

                do {
                    n = Console::getIntInput("Please enter the task number to mark completed: ");
                    if (n > lp) {
                        Console::displayInvalidInput();
                    }
                } while (n > lp);

                task = getTask(head, n);
                task -> setCompleted(true);
                break;

            case 'D':
                // display case
                
                if (lp == 0) {
                    std::cout << "There aren't any tasks to display!\n";
                    break;
                }

                displayTasks(head);
                break;

            case 'Q':
                // quit case

                quit = true;
                break;

            case 'R':
                // reset case

                if (lp == 0) {
                    break;
                }

                task = head -> getLink();
                current = head;
                lp = 0;
                deleteLinks(task);
                break;

            case 'W':
                // withdraw case

                if (lp == 0) {
                    std::cout << "There aren't any tasks to withdraw!\n";
                    break;
                }

                do {
                    n = Console::getIntInput("Please enter the task number to withdraw: ");
                    if (n > lp) {
                        Console::displayInvalidInput();
                    }
                } while (n > lp);
                
                lp -= 1;
                removeTask(head, n);
                break;

            default:
                Console::displayInvalidInput();
                break;
        }
    }

    return 0;
}


Task* getTask(Task *head, int n) {

    if ( n == 0 ) {
        return head;
    }

    int i = 0;
    Task *current = head;

    while ( i < n && current -> hasLink() ) {

        current = current -> getLink();
        i += 1;
    }

    return current;
}


void displayTasks(Task *head) {

    Task *current = head;
    int i = 1;

    std::cout << "\nMY TODO LIST:\n";
    std::cout << "-------------\n";

    while ( current -> hasLink() ) {
        
        current = current -> getLink();
        std::cout << i << ". " << current -> getDesc() << " [" << (current -> isCompleted() ? "Complete" : "Incomplete") << "]\n";
        i += 1;
    }
}


void removeTask(Task *head, int n) {

    Task *current = head;
    Task *previous, *next;
    int i = 0;

    while ( i < n && current -> hasLink() ) {

        previous = current;
        current = current -> getLink();
        i += 1;
    }

    next = current -> getLink();
    previous -> setLink(next);
    delete current;
}


void deleteLinks(Task *task) {

    // this vector holds all the tasks to be removed
    std::vector<Task*> tasks = {task};
    Task *current = task;

    while ( current -> hasLink() ) {

        current = current -> getLink();
        tasks.push_back(current);
    }

    for (auto t : tasks) {
        
        delete t;
    }
}