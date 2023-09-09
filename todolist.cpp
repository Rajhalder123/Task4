#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure
struct Task {
    string description;
    bool completed;
};

// Function to add a task to the list
void addTask(vector<Task>& taskList, const string& description) {
    taskList.push_back({description, false});
    cout << "Task added successfully!" << endl;
}

// Function to view tasks
void viewTasks(const vector<Task>& taskList) {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << i + 1 << ". ";
        if (taskList[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << taskList[i].description << endl;
    }
    cout << endl;
}

// Function to mark a task as completed
void markCompleted(vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(taskList.size())) {
        taskList[taskIndex - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(taskList.size())) {
        taskList.erase(taskList.begin() + taskIndex - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    vector<Task> tasks;
    char choice;

    cout << "Welcome to the To-Do List Manager!" << endl;

    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Mark a task as completed" << endl;
        cout << "4. Remove a task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': // Add a task
            {
                string taskDescription;
                cout << "Enter the task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
            case '2': // View tasks
                viewTasks(tasks);
                break;
            case '3': // Mark a task as completed
                int taskIndex;
                viewTasks(tasks);
                cout << "Enter the task number to mark as completed: ";
                cin >> taskIndex;
                markCompleted(tasks, taskIndex);
                break;
            case '4': // Remove a task
                viewTasks(tasks);
                cout << "Enter the task number to remove: ";
                cin >> taskIndex;
                removeTask(tasks, taskIndex);
                break;
            case '5': // Quit
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
