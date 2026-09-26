#include "Session.h"
#include <iostream>
#include <limits>

bool hasUnextractedInput() {
    return !std::cin.eof() && std::cin.peek() != '\n';
}

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::vector<char> printAndStoreWord(const Session &s) {

    for (const auto letter: s.m_word)
        std::cout << letter;
    std::cout << '\n';

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

void printLives(Session& s) {
    static int lives {6};
    if (s.m_guessed.size() > 0) {
        char letter {s.m_guessed.back()};

        if (s.trackWrongGuesses(letter)) {
            --lives;
        }
    }
    std::cout << "Wrong Guesses: ";
    for (int i {0} ; i < lives; ++i) {
        std::cout << "+ ";
    }
    std::cout << '\n';
}

bool Session::trackWrongGuesses(char letter) {
    for (const auto character:m_word ) {
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
    getInput();
    printAndStoreWord(s);
    printLives(s);
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
    std::cout << trackWrongGuesses(letter) << '\n';
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
