/*
Counts the occurence of each number in the given array outputs it. 
Using an unordered_map to store the count of each number. 
Time complexity O(n) 
*/



#include <iostream>
#include <unordered_map>
#include <vector>

void countOccurrences(const std::vector<int>& arr){
    std::unordered_map<int, int> count;

    for(int n: arr){
        count[n]++;
    }

    for(const auto& pair : count){
        std::cout << "The number: " << pair.first<< " occurs " <<pair.second<< " times." << std::endl;
    }
}

int main() {
    
    std::vector<int> myArray = {12, 4, 12, 23, 1, 1, 12, 4, 5};
    countOccurrences(myArray);

    return 0;
}
