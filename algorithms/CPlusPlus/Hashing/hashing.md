# Hashing in C++

## Introduction

Hashing is the process of converting any data into a fixed-size string of characters. It is used to index and retrieve items in a database because it is faster than searching through all the items in the database. 

## Steps

1. Include the unordered_map header file.
2. Create an instance of the unordered_map.
3. Insert key-value pairs into the unordered_map.
4. Retrieve values from the unordered_map.

## Examples

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> myMap;
    myMap["John"] = 25;
    myMap["Jane"] = 30;
    std::cout << "John is " << myMap["John"] << " years old." << std::endl;
    return 0;
}

