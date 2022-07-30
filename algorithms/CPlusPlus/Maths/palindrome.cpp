#include <algorithm>
#include <iostream>
#include <string>

int main() {
    // User explanation and examples
    std::cout << "Please type a string, e.g.: 101, pop, asdfgfdsa, 123454321, obobo, nancyiycnan etc.\n";

    // Define a buffer variable
    std::string user_input;
    // Taking input from user
    std::cin >> user_input;

    // This will hold the reverse of the input
    // We make sure it is as long as the input string and fill it with zero-bytes for now
    std::string rev(user_input.length(), '\0');
    // Copying the reverse of the string
    std::reverse_copy(user_input.begin(), user_input.end(), rev.begin());

    // Compare and output
    std::cout << (user_input == rev ? "Palindrome\n" : "Non-palindrome\n");

    // Exit with success
    return 0;

    // Complexity, with n = the length of the input:
    //   Constructing rev is O(n)
    //   std::reverse_copy is O(n)
    //   Total: O(n)
}
