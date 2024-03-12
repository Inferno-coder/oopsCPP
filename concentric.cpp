#include <iostream>
#include <cmath>

void printConcentricPattern(int n) {
    // Calculate the size of the pattern
    int size = 2 * n - 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Calculate the distance from the center
            int distance = std::max(abs(i - n + 1), abs(j - n + 1));
            // Print the appropriate element based on the distance
            std::cout << (n-distance) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the size of the concentric pattern: ";
    std::cin >> n;
    printConcentricPattern(n);
    return 0;
}
