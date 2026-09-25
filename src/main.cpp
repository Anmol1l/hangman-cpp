#include <iostream>
#include <string>
#include "Random.h"

namespace WordList {
    enum Words {
        mystery,
        broccoli,
        account,
        almost,
        spaghetti,
        opinion,
        beautiful,
        distance,
        luggage,
        word_count,
    };
}

std::string_view getWordString(WordList::Words word) {
    switch (word) {
        case WordList::mystery:
            return "mystery";
        case WordList::broccoli:
            return "broccoli";
        case WordList::account:
            return "account";
        case WordList::almost:
            return "almost";
        case WordList::spaghetti:
            return "spaghetti";
        case WordList::opinion:
            return "opinion";
        case WordList::beautiful:
            return "beautiful";
        case WordList::distance:
            return "distance";
        case WordList::luggage:
            return "luggage";
        default:
            return "???";
    }
}

int main() {
    std::cout << "Welcome to C++ man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n\n";
    int randomNum =  Random::get(0,static_cast<int>(WordList::word_count - 1));
    std::cout << "The word is: " << getWordString(static_cast<WordList::Words>(randomNum));
}
