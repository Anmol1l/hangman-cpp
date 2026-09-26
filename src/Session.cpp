#include "Session.h"
#include <iostream>
#include <limits>
#include <algorithm>

bool hasUnextractedInput() {
    return !std::cin.eof() && std::cin.peek() != '\n';
}

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::vector<char> printAndStoreWord(const Session &s) {
    std::vector<char> word{};

    std::cout << "The word: ";
    bool printed{false};
    for (const auto letter: s.m_word) {
        for (const auto guessed: s.m_guessed) {
            if (letter == guessed) {
                std::cout << letter << ' ';
                printed = true;
                word.push_back(letter);
            }
        }
        if (!printed) {
            std::cout << "_ ";
            word.push_back('_');
        }
        printed = false;
    }
    std::cout << '\t';
    return word;
}

void printLives(Session &s) {
    static int lives{6};
    if (!s.m_guessed.empty()) {
        char letter{s.m_guessed.back()};
        if (s.trackWrongAndStoreGuesses(letter)) {
            --lives;
        }
    }
    std::cout << "Wrong Guesses: ";
    for (int i{0}; i < lives; ++i) {
        std::cout << "+ ";
    }

    if (!s.m_wrong.empty()) {
        for (const auto letter: s.m_wrong) {
            std::cout << letter << ' ';
        }
    }
    std::cout << '\n';
}

bool Session::trackWrongAndStoreGuesses(char letter) {
    for (const auto character: m_word) {
        if (letter == character)
            return false;
    }
    m_wrong.push_back(letter);
    return true;
}

void Session::displayBasicState(Session &s) {
    printAndStoreWord(s);
    printLives(s);
}

void Session::startGame(Session &s) {
    while (true) {
        getInput();
        std::vector<char> answer = printAndStoreWord(s);
        printLives(s);
        if (checkResults(answer))
            return;
    }
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

bool Session::checkResults(std::vector<char>& answer) const {
    if (answer.size() != m_word.size())
        return false;
    if (std::equal(m_word.begin(), m_word.end(), answer.begin())) {
        std::cout << "You Won\n";
        return true;
    }
    else if (m_wrong.size() >= 6) {
        std::cout << "You Lost\n";
        return true;
    }
    return false;
}
