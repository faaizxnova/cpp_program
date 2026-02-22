#include <iostream>
#include <stdexcept>

void FunctionB() {
    std::cout << "Entering Function B\n";
    throw std::runtime_error("Critical Error in B!");
    std::cout << "This line in B will NEVER run.\n";
}

void FunctionA() {
    std::cout << "Entering Function A\n";
    FunctionB();
    std::cout << "This line in A will NEVER run.\n";
}

int main() {
    try {
        std::cout << "Starting in main\n";
        FunctionA();
    } 
    catch (const std::runtime_error& e) {
        std::cout << "Caught in main: " << e.what() << "\n";
    }
    std::cout << "Back to normal execution in main.\n";
    return 0;
}