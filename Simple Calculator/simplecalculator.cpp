#include <iostream>

void displayMenu() {
    std::cout << "Simple Calculator\n";
    std::cout << "Choose an operation:\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void performOperation(int choice, double num1, double num2) {
    switch (choice) {
        case 1:
            std::cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << "\n";
            break;
        case 2:
            std::cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << "\n";
            break;
        case 3:
            std::cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << "\n";
            break;
        case 4:
            if (num2 != 0) {
                std::cout << "Result: " << num1 << " / " << num2 << " = " << (num1 / num2) << "\n";
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            std::cout << "Invalid operation. Please try again.\n";
    }
}

int main() {
    int choice;
    double num1, num2;

    do {
        displayMenu();
        std::cin >> choice;

        if (choice >= 1 && choice <= 4) {
            std::cout << "Enter the first number: ";
            std::cin >> num1;
            std::cout << "Enter the second number: ";
            std::cin >> num2;

            performOperation(choice, num1, num2);
        } else if (choice != 5) {
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    std::cout << "Exiting the calculator. Goodbye!\n";
    return 0;
}
