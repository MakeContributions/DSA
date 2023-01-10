#include <algorithm>
#include <iostream>
#include <locale>
#include <string>

int main() {
  // User explanation and examples
  std::cout << "Please type a string, e.g.: pop, civic, 123454321, rotor, "
               "obobo, nancyiycnan etc.\n";

  // Define a buffer variable
  std::string input;
  // Taking input from user
  std::getline(std::cin, input);

  // Remove all non-alphanumeric characters.  Filtering is done according to the
  // users locale using `std::locale("")`.  This uses the erase-remove idiom:
  // https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
  std::locale user_locale("");
  input.erase(std::remove_if(
                  input.begin(), input.end(),
                  [&](const auto &c) { return !std::isalnum(c, user_locale); }),
              input.cend());
  // Convert to lowercase
  std::transform(input.cbegin(), input.cend(), input.begin(),
                 [&](const auto &c) { return std::tolower(c, user_locale); });

  // Print filtered string
  std::cout << "Checking the string: " << input << '\n';

  // This will hold the reverse of the input.  We make sure it is as long as
  // the input string and fill it with zero-bytes for now
  std::string rev(input.length(), '\0');
  // Copying the reverse of the string
  std::reverse_copy(input.begin(), input.end(), rev.begin());

  // Compare and output
  std::cout << (input == rev ? "Palindrome\n" : "Non-palindrome\n");

  // Exit with success
  return 0;
}

// Complexity, with n being the length of the input:
//   std::remove_if are O(n)
//   std::vector<T>::erase is worst-case O(n)
//   Constructing rev is O(n)
//   std::reverse_copy is O(n)
//   Total: O(n)
