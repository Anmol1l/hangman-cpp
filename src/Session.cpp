#include "Session.h"
#include <iostream>
#include <limits>

void printDash(std::size_t n) {
    for (int i{0}; i < n; i++) {
        std::cout << "_ ";
    }
    std::cout << '\n';
}

void Session::displayBasicState() const {
    std::cout << "The word: ";
    printDash(m_word.length());
    getInput();
}

bool hasUnextractedInput() {
    return !std::cin.eof() && std::cin.peek() != '\n';
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Session::getInput() const {
    char letter{};
    while (true) {
        std::cout << "Enter your letter: ";
        std::cin >> letter;
        if (hasUnextractedInput()) {
            ignoreLine();
            continue;
        }
        if (letter >= 'a' && letter <= 'z')
            break;
    }
    std::cout << "You entered: " << letter;
}
