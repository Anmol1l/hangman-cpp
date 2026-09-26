#ifndef CPP_TEMPLATE_SESSION_H
#define CPP_TEMPLATE_SESSION_H
#include "Wordlist.h"
#include <vector>

class Session {
private:
    const std::string m_word {};
    std::vector <char> m_guessed {};
    std::vector<char> m_wrong {};

public:
    Session(std::string_view word)
        : m_word {word}
    { };
    void displayBasicState(Session& s);
    void startGame(Session& s);
    void getInput();
    void updateGuessArray(char letter);
    bool trackWrongAndStoreGuesses(char letter);
    friend std::vector<char> printAndStoreWord(const Session& s);
    friend void printLives(Session& s);
};
#endif //CPP_TEMPLATE_SESSION_H
