#ifndef CPP_TEMPLATE_SESSION_H
#define CPP_TEMPLATE_SESSION_H
#include "Wordlist.h"
#include <vector>

class Session {
private:
    const std::string m_word {};
    std::vector <char> m_guessed {};

public:
    Session(std::string_view word)
        : m_word {word}
    { };
    void displayBasicState(const Session& s) const;
    void startGame(const Session& s);
    void getInput();
    void updateGuessArray(char letter);
    friend void printWord(const Session& s);
};
#endif //CPP_TEMPLATE_SESSION_H
