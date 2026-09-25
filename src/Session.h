#ifndef CPP_TEMPLATE_SESSION_H
#define CPP_TEMPLATE_SESSION_H
#include "Wordlist.h"
class Session {
private:
    std::string m_word {};
public:
    Session(std::string_view word)
        : m_word {word}
    { };
};
#endif //CPP_TEMPLATE_SESSION_H
