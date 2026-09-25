#include "Session.h"
#include <iostream>
#include <limits>

bool hasUnextractedInput() {
    return !std::cin.eof() && std::cin.peek() != '\n';
}

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printWord(const Session &s) {
    std::cout << "The word: ";
    bool printed{false};
    for (const auto letter: s.m_word) {
        for (const auto guessed: s.m_guessed) {
            if (letter == guessed) {
                std::cout << letter << ' ';
                printed = true;
            }
        }
        if (!printed)
            std::cout << "_ ";
        printed = false;
    }
    std::cout << '\n';
}

void Session::displayBasicState(const Session &s) const {
    printWord(s);
}

void Session::startGame(const Session &s) {
    getInput();
    printWord(s);
}

void Session::getInput() {
    char letter{};
    while (true) {
        bool alreadyGuessed{false};

        std::cout << "Enter your letter: ";
        std::cin >> letter;

        if (hasUnextractedInput()) {
            std::cout << "Enter a single letter\n";
            ignoreLine();
            continue;
        }
        for (const auto guess: m_guessed) {
            if (letter == guess) {
                std::cout << "Already guessed\n";
                alreadyGuessed = true;
            }
        }

        if (alreadyGuessed)
            continue;

        if (letter >= 'a' && letter <= 'z') {
            std::cout << "You entered: " << letter << '\n';
            break;
        }
    }
    updateGuessArray(letter);
}

void Session::updateGuessArray(char letter) {
    for (const auto character: m_guessed) {
        if (character == letter) {
            return;
        }
    }
    m_guessed.push_back(letter);
}
