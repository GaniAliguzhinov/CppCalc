#include "parser.hpp"

using namespace std;

int main() {
    
    Parser p;

    p.
    do {
        Tok t = lx.readNextTok();
        if (t.code == TokCode::t_name) {
            cout << t.name;
        } else if (t.code == TokCode::t_number) {
            cout << t.value;
        } else if (t.code == TokCode::t_symbol) {
            cout << t.symbol;
        } else {
            cout << lx.to_string(t.code);
        }
        cout << " ";
    } while(lx.CurTok.code != t_eof);

    return 0;
}
