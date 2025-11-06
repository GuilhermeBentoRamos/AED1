#include <iostream>
using namespace std;

void swap(int a, int b) {
    int *temp = &a;
    a = b;
    b = *temp;
    delete temp;
}
int heapfyUp (int *nums, int n, int x) {
    nums = new int[n + 1]; //aumentar vetor, não sei se está correto.
    nums[n] = x;
    int i = n;
    while (i > 0 && nums[(i - 1) / 2] > nums[i]) {
        swap(nums[(i - 1) / 2], nums[i]);
        i = (i - 1) / 2;
    }
    return n + 1; //new size
}

int heapfyDown(int *nums, int n) {
    int temp = nums[0];
    nums[0] = nums[n - 1];
    delete nums[n - 1];
    int i = 0;
    while (i < n - 1) {
        int min; // endereço do menor filho
        if (min < n - 1 && nums[i] > nums[min]) {
            swap(nums[i], nums[min]);
            i = min;
        } else {
            break;
        }
    }
}

int main() {
    int n;
    int *heapMin = new int[n];
}