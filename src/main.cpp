#include "list.hpp"
using namespace std;

// string string_treatment(string s) {
// 	int size = s.size();
// 	string aux;

// 	for (int i = 0; i < size; i++) {
// 		if (s[i] != '.' && s[i]!= ',' && s[i] != ':' && s[i] != ';' && s[i] != '?' && s[i] != '!' && s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']' && s[i] != '{'
// 			&& s[i] != '}' && s[i] != '+'&& s[i] != '=' && s[i] != '-' && s[i] != '*' && s[i] != '/') {
// 			s[i] = tolower(s[i]);
//             aux += s[i];
// 		}
// 	}
 
// 	return aux;
// }

int main () {
    size_t t;
    t = clock();
    tf_idf();
    t = clock() - t;

    cout << endl << "TEMPO DE EXECUÇÃO EM TICK: " << t << endl;
    cout << "TEMPO DE EXECUÇÃO EM SEGUNDOS: " << float(t) / CLOCKS_PER_SEC << endl;
}