#include <iostream>
#include <string>
#include "Wordlist.h"

int main() {
    std::cout << "Welcome to C++ man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n\n";

    std::cout << "The word is: " << WordList::getRandomWord();
}
