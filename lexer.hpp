#ifndef lexer_hpp
#define lexer_hpp

#include "common.hpp"

enum TokCode {t_eof, t_name, t_number, t_symbol, t_LF};
typedef struct Tok { TokCode code {t_eof}; S symbol {"X"}; S name {"<X>"}; double value {0.0}; } Tok;

struct TokStream { 
    M<S, TokCode> keywords; 
    Tok CurTok; 
    char ch;

    TokStream() : keywords {}, ch {' '} {} 

    S to_string(TokCode c) { return (c == t_eof ? "eof" : c == t_name ? "name" : c == t_number ? "number" : c == t_symbol ? "symbol" : c == t_LF ? "\n" :"unknown"); }
    Tok readNextTok() {
        Tok cur;
        if (isspace(ch) && ch != '\n') eatWS();
        if (isalpha(ch)) {
            cur.name = readName();
            if (findKeyword(cur)) {
                return CurTok = cur;
            }
            cur.code = TokCode::t_name;
            return CurTok = cur;
        } 
        if (isdigit(ch)){
            cur.value = readDouble();
            cur.code = TokCode::t_number;
            return CurTok = cur;
        }
        if (std::cin.eof()) {
            cur.code = TokCode::t_eof;
            return CurTok = cur;
        }
        if (ch == '\n') {
            cur.code = t_LF;
            cin.get(ch);
            return CurTok = cur;
        }
        if (ch == '<')
            return finishSymbol(cur, '-');
        cur.symbol = S {ch};
        cin.get(ch);
        cur.code = t_symbol;
        return CurTok = cur;
    }
    private:
    bool findKeyword(Tok& t) {
        for (auto k: keywords)
            if (t.name == k.first) { 
                t.code = k.second; 
                return true; 
            }
        return false;
    }
    Tok finishSymbol(Tok t, char last) {
        char first = ch;
        S full = S{first} + S{last};
        if (cin.get(ch) && ch == last) {
            t.symbol = full;
            cin.get(ch);
        } else
            t.symbol = S{first};
        t.code = t_symbol;
        return CurTok = t;
    }
    void eatWS() {
        auto lambda = [](char ch) {return isspace(ch) && ch != '\n';};
        consume(ch, lambda);
    }
    S readName() {
        auto lambda = [](char ch) {return isalnum(ch);};
        return consume(ch, lambda);
    }
    double readDouble() {
        auto lambda = [](char ch) {return isdigit(ch);};
        S r = consume(ch, lambda);
        if (ch == '.') 
            r += consume(ch, lambda);
        return strtod(r.c_str(), nullptr);
    }
};

#endif
