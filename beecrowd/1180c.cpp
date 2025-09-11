#include <iostream>

int main() {
    int* n = new int;
    std::cin >> *n;

    int* nums = new int[*n];
    int* curr = nullptr;
    int* minor = nullptr;

    for (int i = 0; i < *n; i++) {
        std::cin >> nums[i];
        curr = &nums[i];

        if (i == 0 || *curr < *minor) {
            minor = curr;
        }
    }

    std::cout << "Menor: " << *minor << std::endl;
    std::cout << "Posicao: " << minor - nums << std::endl;

    delete n;
    delete[] nums;

    return 0;
}