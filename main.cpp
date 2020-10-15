#include "lexer.hpp"

using namespace std;

int main() {
    
    TokStream ts;

    do {
        Tok t = ts.readNextTok();
        if (t.code == TokCode::t_name) {
            cout << t.name;
        } else if (t.code == TokCode::t_number) {
            cout << t.value;
        } else if (t.code == TokCode::t_symbol) {
            cout << t.symbol;
        } else {
            cout << ts.to_string(t.code);
        }
        cout << " ";
    } while(ts.CurTok.code != t_eof);

    return 0;
}
