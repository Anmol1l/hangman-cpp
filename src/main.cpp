#include <iostream>
#include <string>
#include "Wordlist.h"
#include "Session.h"

int main() {
    std::cout << "Welcome to C++ man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n\n";

    std::cout << "The word is: " << WordList::getRandomWord() << '\n';

    Session s {WordList::getRandomWord()};
    s.displayBasicState();
}
