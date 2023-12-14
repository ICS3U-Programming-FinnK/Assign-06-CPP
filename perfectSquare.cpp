// Created by: Finn Kitor
// Created on: December 13th, 2023
// this program asks for the user to input numbers
// and it will display if the number is a perfect square.
#include <iostream>
#include <cmath>
#include <vector>
// Checking if the input is a array
std::vector<int> find_perfect_squares(std::vector<int> numbers) {
    std::vector<int> perfect_squares;
    // Iterating through each number in the array
    for (int num : numbers) {
        // Checking if the number is a perfect square
        if (num >= 0) {
            // Trying to convert the number to an integer
            try {
                if (std::pow(std::sqrt(num), 2) == num) {
                    perfect_squares.push_back(num);
                }  // Catching the error if the number is not a valid integer
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << '\n';
            }
        }
    }
    return perfect_squares;
}
int main() {
    // Asking the user for a list of whole numbers
    std::vector<int> numbers;
    std::string input;
    std::cout << "Please enter a list of whole numbers, separated by commas: ";
    // Convert input string to a list of integers
    std::getline(std::cin, input);
    size_t pos = 0;
    std::string token;
    // Catching the error if the input is not a valid list
    while ((pos = input.find(",")) != std::string::npos) {
        token = input.substr(0, pos);
        try {
            numbers.push_back(std::stoi(token));
        } catch (const std::invalid_argument& ia) {
            std::cerr << "Invalid argument: " << ia.what() << '\n';
        } catch (const std::out_of_range& oor) {
            std::cerr << "Out of Range error: " << oor.what() << '\n';
        }
        input.erase(0, pos + 1);
    }
    // Catching the error if the input is not a valid list
    try {
        numbers.push_back(std::stoi(input));
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
    // Printing the list of perfect squares to the user
        std::vector<int>
            perfect_squares = find_perfect_squares(numbers);
    std::cout << "These numbers are perfect squares:";
    for (int num : perfect_squares) {
        std::cout << " " << num;
    }
    std::cout << std::endl;
    // Calling the main function to start the program
    return 0;
}