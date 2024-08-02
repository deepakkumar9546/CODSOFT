#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool isCompleted;

    Task(const std::string& desc) : description(desc), isCompleted(false) {}
};

void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter the task description: ";
    std::getline(std::cin, description);
    tasks.emplace_back(description);
    std::cout << "Task added.\n";
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }
    std::cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description;
        std::cout << (tasks[i].isCompleted ? " [Completed]\n" : " [Pending]\n");
    }
}

void markTaskCompleted(std::vector<Task>& tasks) {
    int taskNumber;
    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> taskNumber;
    std::cin.ignore(); // Clear the newline character from the input buffer

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        std::cout << "Invalid task number.\n";
    } else {
        tasks[taskNumber - 1].isCompleted = true;
        std::cout << "Task marked as completed.\n";
    }
}

void removeTask(std::vector<Task>& tasks) {
    int taskNumber;
    std::cout << "Enter the task number to remove: ";
    std::cin >> taskNumber;
    std::cin.ignore(); // Clear the newline character from the input buffer

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        std::cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed.\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
