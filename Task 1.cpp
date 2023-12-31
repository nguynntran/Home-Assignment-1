/* Task 1
Given a length if a number sequence and the sequence itself in the next line, that might contain duplicates, return all possible unique permutations in any order.
*/

#include <iostream>

using namespace std;
// Swap two elements 
void change_pos(int &x , int &y) {
    int temp = x;
    x = y;
    y = temp;
}
//Check the duplicate of elements
int dup(int numbers[], int begin, int end) {
    for (int i = begin; i < end; i++) {
        if (numbers[i] == numbers[end]) {
            return 1;
        }
    }
    return 0;
}

void permutations(int numbers[], int length_of_sequence, int current) {
    if (current == length_of_sequence) {
        for (int i = 0; i < length_of_sequence; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = current; i < length_of_sequence; i++) {
        if (dup(numbers, current, i) == 0) {
            change_pos(numbers[i], numbers[current]);
            permutations(numbers, length_of_sequence, current + 1);
            change_pos(numbers[i], numbers[current]);
        }
    }
}

int main() {
    int length_of_sequence;
    cout << "Enter the length of numbers :";
    cin >> length_of_sequence;
    
    cout << "Enter the numbers :";
    int numbers[length_of_sequence];
    for (int i = 0; i < length_of_sequence; i++) {
        cin >> numbers[i];
    }
    cout << "All possible unique permutation: "<< endl;
    permutations(numbers, length_of_sequence, 0);
    
    return 0;
}
