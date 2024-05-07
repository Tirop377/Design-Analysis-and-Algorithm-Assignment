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

 
