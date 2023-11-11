#include <iostream>
#include <algorithm>

void backtrack(int* nums, int size, int start, int** result, int* resultSize, int* temp, bool* used) {
    if (start == size) {
        result[*resultSize] = new int[size];
        std::copy(temp, temp + size, result[*resultSize]);
        (*resultSize)++;
        return;
    }

    for (int i = 0; i < size; i++) {
        if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]))
            continue;

        temp[start] = nums[i];
        used[i] = true;
        backtrack(nums, size, start + 1, result, resultSize, temp, used);
        used[i] = false;
    }
}

int** permuteUnique(int* nums, int size, int* returnSize, int** returnColumnSizes) {
    std::sort(nums, nums + size);  // Sort the numbers to handle duplicates

    int totalPermutations = 1;
    for (int i = 2; i <= size; i++)
        totalPermutations *= i;

    int** result = new int*[totalPermutations];
    int* temp = new int[size];
    bool* used = new bool[size];
    for (int i = 0; i < size; i++)
        used[i] = false;

    *returnSize = 0;
    backtrack(nums, size, 0, result, returnSize, temp, used);

    *returnColumnSizes = new int[*returnSize];
    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = size;

    delete[] temp;
    delete[] used;

    return result;
}

void printPermutations(int** permutations, int numPermutations, int* permutationSize) {
    for (int i = 0; i < numPermutations; i++) {
        for (int j = 0; j < permutationSize[i]; j++) {
            std::cout << permutations[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void freePermutations(int** permutations, int numPermutations, int* permutationSize) {
    for (int i = 0; i < numPermutations; i++) {
        delete[] permutations[i];
    }
    delete[] permutations;
    delete[] permutationSize;
}

int main() {
    int n;
    std:: cin >> n;
    int* nums = new int [n];
    for (int i = 0; i < n; i++){
        std:: cin >> nums[i];
    }
    int size = n;

    int** permutations;
    int numPermutations;
    int* permutationSize;

    permutations = permuteUnique(nums, size, &numPermutations, &permutationSize);

    printPermutations(permutations, numPermutations, permutationSize);
    freePermutations(permutations, numPermutations, permutationSize);

    return 0;
}