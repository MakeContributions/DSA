#include <iostream>
#include <unordered_map>
#include <vector>

void countFrequency(const std::vector<int>& array) {
    std::unordered_map<int, int> frequencyMap;

    for (int element : array) {
        frequencyMap[element]++;
    }

    for (const auto& pair : frequencyMap) {
        std::cout << "Element " << pair.first << ": " << pair.second << " times\n";
    }
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    std::vector<int> array(size);
    std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> array[i];
    }

    countFrequency(array);

    return 0;
}