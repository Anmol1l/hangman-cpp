#include <iostream>
#include <string>
#include "Wordlist.h"
#include "Session.h"

int main() {
    std::cout << "Welcome to C++ man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n\n";

    Session s{WordList::getRandomWord()};
    s.displayBasicState(s);

    s.startGame(s);
}
