#include <iostream>
#include <string>


int findThirdCommaIndex(const std::string& str, int currentIndex, int commaCount) {
    if (currentIndex >= str.length()) {
        return -1;
    }

    if (str[currentIndex] == ',') {
        commaCount++;
        if (commaCount == 3) {
            return currentIndex; 
        }
    }

    return findThirdCommaIndex(str, currentIndex + 1, commaCount);
}


void replaceCommasWithStars(std::string& str, int currentIndex) {
    if (currentIndex >= str.length()) {
        return; 
    }

    if (str[currentIndex] == ',') {
        str.replace(currentIndex, 1, "**");

        replaceCommasWithStars(str, currentIndex + 1);
    }
    else {

        replaceCommasWithStars(str, currentIndex + 1);
    }
}

int main() {
    std::cout << "Input: ";
    std::string str;
    std::getline(std::cin, str);

    int commaIndex = findThirdCommaIndex(str, 0, 0);
    if (commaIndex != -1) {
        std::cout << "Index: " << commaIndex << std::endl;

        replaceCommasWithStars(str, 0);
        std::cout << "Width '**': " << str << std::endl;
    }
    else {
        std::cout << "Nothing" << std::endl;
    }

    return 0;
}
