#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added successfully!\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the to-do list.\n";
        } else {
            cout << "To-Do List:\n";
            cout << setw(4) << "ID" << setw(20) << "Description" << setw(15) << "Status" << "\n";
            cout << setfill('-') << setw(40) << "" << setfill(' ') << "\n";

            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << setw(4) << i + 1 << setw(20) << tasks[i].description << setw(15) << (tasks[i].completed ? "Completed" : "Pending") << "\n";
            }
        }
    }

    void markAsCompleted(size_t taskId) {
        if (taskId > 0 && taskId <= tasks.size()) {
            tasks[taskId - 1].completed = true;
            cout << "Task marked as completed!\n";
        } else {
            cout << "Invalid task ID.\n";
        }
    }

    void removeTask(size_t taskId) {
        if (taskId > 0 && taskId <= tasks.size()) {
            tasks.erase(tasks.begin() + taskId - 1);
            cout << "Task removed successfully!\n";
        } else {
            cout << "Invalid task ID.\n";
        }
    }
};

int main() {
    ToDoList toDoList;

    int choice;
    do {cout << "\n------ To-Do List Manager ------\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear the input buffer
                string taskDescription;
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                size_t taskId;
                cout << "Enter the task ID to mark as completed: ";
                cin >> taskId;
                toDoList.markAsCompleted(taskId);
                break;
            }
            case 4: {
                size_t taskId;
                cout << "Enter the task ID to remove: ";
                cin >> taskId;
                toDoList.removeTask(taskId);
                break;
            }
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
