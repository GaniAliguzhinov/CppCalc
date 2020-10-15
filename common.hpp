#ifndef common_hpp
#define common_hpp

#include <iostream>
#include <string>
#include <map>
#include <memory>


using S = std::string;
template <typename T1, typename T2> using M = std::map<T1, T2>; 
using std::unique_ptr;
using std::make_unique;
using std::move;
using std::cin;
using std::cout;

// Reads characters into ch as 
// long as condintion l is satisfied, then reads one more char
// into ch and returns all read chars as a string
template<typename Lambda>
S consume(char& ch, Lambda l) {
    S r {ch};
    while (cin.get(ch) && l(ch))
        r += ch;
    return r;
}

#endif
