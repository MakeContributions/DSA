#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, int> FrequencyElement(const std::vector<int>& nums) {
    std::unordered_map<int, int> un_map;

    for (int i : nums) {
        un_map[i]++;
    }

    return un_map;
}


int main() {
    std::vector<int> inputArray = {1, 2, 3, 1, 2, 1, 4, 5, 4, 3};

    std::unordered_map<int, int> result = FrequencyElement(inputArray);

    for (const auto& pair : result) {
        std::cout << "Element: " << pair.first << ", Frequency: " << pair.second << std::endl;
    }

    return 0;
}
