
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Task {
    string name;
    bool completed;
    int priority;
    string time;
};

vector<Task> tasks;

void addTask() {
    Task task;
    
    cout << "Enter task name: ";
    getline(cin >> ws, task.name);

    cout << "Priority (1-3 Lowest to Highest): ";
    cin >> task.priority;

    if (task.priority < 1 || task.priority > 3) {
        cout << "Invalid priority!\n";
        return;
    }

    cout << "Enter time (example: 6:00 PM): ";
    cin.ignore();
    getline(cin, task.time);

    task.completed = false;
    tasks.push_back(task);
    cout << "Task added!\n";
}

void showTasks() {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }

    for (int i = 0; i < tasks.size(); i++) {
        cout << "\nTask " << i + 1 << ": " << tasks[i].name;

        if (tasks[i].completed) {
            cout << " [Completed]";
        } 
        else {
            cout << " [Not completed]";
        }

        cout << "\nPriority: ";

        if (tasks[i].priority == 1) {
            cout << "Low";
        } 
        else if (tasks[i].priority == 2) {
            cout << "Medium";
        } 
        else {
            cout << "High";
        }

        cout << "\nTime: " << tasks[i].time << "\n";
    }
}

void completeTask() {
    int number;

    showTasks();

    if (tasks.empty()) {
        return;
    }

    cout << "Enter task number to complete: ";
    cin >> number;

    if (number >= 1 && number <= tasks.size()) {
        tasks[number - 1].completed = true;
        cout << "Task completed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

void deleteTask() {
    int number;

    showTasks();

    if (tasks.empty()) {
        return;
    }

    cout << "Enter task number to delete: ";
    cin >> number;

    if (number >= 1 && number <= tasks.size()) {
        tasks.erase(tasks.begin() + number - 1);
        cout << "Task deleted!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

void saveTasks() {
    ofstream file("tasks.txt");

    for (int i = 0; i < tasks.size(); i++) {
        file << tasks[i].completed << "\n";
        file << tasks[i].priority << "\n";
        file << tasks[i].time << "\n";
        file << tasks[i].name << "\n";
    }

    file.close();
}

void loadTasks() {
    ifstream file("tasks.txt");
    Task task;

    while (file >> task.completed) {
        file >> task.priority;
        file.ignore();
        getline(file, task.time);
        getline(file, task.name);

        tasks.push_back(task);
    }

    file.close();
}

int main() {
    loadTasks();
    int choice;

    do {
        cout << "\n--- TO-DO LIST ---\n";
        cout << "1. Add task\n";
        cout << "2. Show tasks\n";
        cout << "3. Complete task\n";
        cout << "4. Delete task\n";
        cout << "5. Save tasks\n";
        cout << "0. Exit";
        cout << "\n------------------\n";
        cout << "Choose an option: ";

        cin >> choice;

        if (choice == 1) {
            addTask();
        } 
        else if (choice == 2) {
            showTasks();
        } 
        else if (choice == 3) {
            completeTask();
        } 
        else if (choice == 4) {
            deleteTask();
        } 
        else if (choice == 5) {
            saveTasks();
            cout << "Tasks saved!\n";
        } 
        else if (choice == 0) {
            saveTasks();
            cout << "Goodbye!\n";
        } 
        else {
            cout << "Invalid option!\n";
        }
    } 
    while (choice != 0);
    return 0;
}
