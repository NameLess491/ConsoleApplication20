#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

// Завдання 1
void task1(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (inFile && outFile) {
        std::string line;
        while (std::getline(inFile, line)) {
            outFile << line << std::endl;
        }
    }
}

// Завдання 2
void task2(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (inFile && outFile) {
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(inFile, line)) {
            lines.push_back(line);
        }
        for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
            outFile << *it << std::endl;
        }
    }
}

// Завдання 3
void task3(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (inFile && outFile) {
        std::string line;
        std::vector<std::string> lines;
        bool foundNoSpace = false;

        while (std::getline(inFile, line)) {
            lines.push_back(line);
            if (line.find(' ') == std::string::npos) {
                foundNoSpace = true;
            }
        }

        for (const auto& l : lines) {
            outFile << l << std::endl;
        }

        if (foundNoSpace) {
            outFile << "------------" << std::endl;
        }
        else {
            outFile << "------------" << std::endl;
        }
    }
}

// Завдання 4
void task4(const std::string& file1, const std::string& file2) {
    std::ifstream inFile1(file1);
    std::ifstream inFile2(file2);

    if (inFile1 && inFile2) {
        std::string line1, line2;
        while (std::getline(inFile1, line1) && std::getline(inFile2, line2)) {
            if (line1 != line2) {
                std::cout << "Mismatch:\nFile1: " << line1 << "\nFile2: " << line2 << std::endl;
            }
        }
    }
}

// Завдання 5
void task5(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (inFile && outFile) {
        int charCount = 0, lineCount = 0, vowelCount = 0, consonantCount = 0, digitCount = 0;
        std::string vowels = "AEIOUaeiouАЕЁИОУЫЭЮЯаеёиоуыэюя";

        std::string line;
        while (std::getline(inFile, line)) {
            lineCount++;
            for (char ch : line) {
                charCount++;
                if (std::isdigit(ch)) {
                    digitCount++;
                }
                else if (std::isalpha(ch)) {
                    if (vowels.find(ch) != std::string::npos) {
                        vowelCount++;
                    }
                    else {
                        consonantCount++;
                    }
                }
            }
        }

        outFile << "Characters: " << charCount << std::endl;
        outFile << "Lines: " << lineCount << std::endl;
        outFile << "Vowels: " << vowelCount << std::endl;
        outFile << "Consonants: " << consonantCount << std::endl;
        outFile << "Digits: " << digitCount << std::endl;
    }
}

// Завдання 6: Шифр Цезаря
void task6(const std::string& inputFile, const std::string& outputFile, int key) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (inFile && outFile) {
        std::string line;
        while (std::getline(inFile, line)) {
            for (char& ch : line) {
                if (std::isalpha(ch)) {
                    char offset = std::islower(ch) ? 'а' : 'А';
                    ch = offset + (ch - offset + key) % 32;
                }
            }
            outFile << line << std::endl;
        }
    }
}

int main() {
    task1("input.txt", "output1.txt");
    task2("input.txt", "output2.txt");
    task3("input.txt", "output3.txt");
    task4("file1.txt", "file2.txt");
    task5("input.txt", "stats.txt");
    task6("input.txt", "encrypted.txt", 3);
    return 0;
}
