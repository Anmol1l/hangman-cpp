#ifndef CPP_TEMPLATE_WORDLIST_H
#define CPP_TEMPLATE_WORDLIST_H
#include <string_view>
#include <vector>
#include "Random.h"

namespace WordList {
    inline std::vector<std::string_view> words{
        "mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"
    };

    inline std::string_view getRandomWord() {
        return words[(Random::get<std::size_t>(0,words.size() - 1))];
    }
}
#endif //CPP_TEMPLATE_WORDLIST_H
