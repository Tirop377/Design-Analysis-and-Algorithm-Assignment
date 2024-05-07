# Design-Analysis-and-Algorithm-Assignment

SCT221-0115/2020

ICS 2301: Design and Analysis of Algorithms Assignment one
Q1
#include <iostream>
#include <vector>
#include <sstream>

std::string extract_sentence(std::string sentence, int start, int end) {
    std::vector<std::string> words;
    std::istringstream iss(sentence);
    std::string word;

    while (iss >> word) {
        words.push_back(word);
    }
    if (start < 0) {
        start = 0;
    }
    if (end > words.size()) {
        end = words.size();
    }
    std::string result;
    for (int i = start; i < end; ++i) {
        result += words[i];
        if (i < end - 1) {
            result += " ";
        }
    }
    return result;
}

int main() {
    std::string sentence = "sample sentence to demonstrate the algorithm.";
    int start_index = 3;
    int end_index = 7;
    std::string result = extract_sentence(sentence, start_index, end_index);
    std::cout << result << std::endl;
    return 0;
}

Recurrence relation:
T(n) = T(n - k) + O(1)

Where:
n is the length of the substring (end - start + 1)
k is the length of the word being extracted
The time complexity can be analyzed using the tracing tree method. In each recursive call, the algorithm reduces the problem size by extracting one word and then calls itself recursively on the remaining substring. Therefore, the time complexity can be expressed as the sum of lengths of all words between the start and end indices. Let's analyze the time complexity using an example:

For the sentence "This is a sample sentence for testing" with start index 5 and end index 24:

"is" has length 2
"a" has length 1
"sample" has length 6
"sentence" has length 8
Total length = 2 + 1 + 6 + 8 = 17

 time complexity of the algorithm is  = O(n)

Q2
#include <iostream>
#include <vector>

using namespace std;

void reverseArray(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void circularShift(vector<int>& arr, int k) {
    int n = arr.size();
    // If k is greater than array size, adjust it to k % n
    k %= n;

    // Reverse the entire array
    reverseArray(arr, 0, n - 1);

    // Reverse the first k elements
    reverseArray(arr, 0, k - 1);

    // Reverse the remaining elements
    reverseArray(arr, k, n - 1);
}

int main() {
    vector<int> arr = {5, 15, 29, 35, 42};
    int k1 = 2;
    int k2 = 4;

    circularShift(arr, k1);
    cout << "After circular shift by " << k1 << " positions: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    circularShift(arr, k2);
    cout << "After circular shift by " << k2 << " positions: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

The recurrence relation for this algorithm can be described as follows:

T(n) = O(n) + O(k) + O(n - k)

Where:

n is the size of the array
k is the number of positions to shift
The time complexity of the algorithm is O(n), where n is the size of the array, since it iterates through the array only once for each operation (reversal).



