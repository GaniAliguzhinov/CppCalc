#include "lexer.hpp"
#include <vector>

using std::vector;

struct Parser {
    Lexer lx;

    Parser() : lx {} { lx.readNextTok(); }

};
