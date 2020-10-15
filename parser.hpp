#include "lexer.hpp"
#include <vector>

using std::vector;

struct Matrix {
    vector<unsigned int> shape;
    vector<double> data;
};

struct Parser {
    TokStream lx;

    Parser() : lx {} { lx.readNextTok(); }

    Matrix parseExpr() {
        Matrix mat;
        if (lx.CurTok.code == t_eof)
            return mat;
        if (lx.CurTok.code == t_name)
            return mat; // TODO: implement
        while (lx.CurTok.code == t_number) {
            mat.data.push_back(lx.CurTok.value);
            lx.readNextTok();
        }
    }
};
