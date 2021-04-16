#include <iostream>
#include <list>
#include <regex>
using namespace std;

class Grammar {
public:
string programm = "{name; float: for) notation}";
string reserved[15] = {"int", "float", "bool", "ass", "if", "then", "else", "for", "to", "do", "while", "read", "write", "true", "false"};
string separators[20] = {"\s", "{", "}", ";", "(", ")", ":", "/", "\n", "[", "]", "<", ">", "=", "+", "-", "*", "or", "and", "not"};
list <string> names;
list <int> id_table;
list <int> id_element;
};

void scanner (Grammar* g) {
        cout << g->programm << endl;
        string str;
        smatch m;
        int count_names = -1;
        string sprtrs;
        for (int i = 0; i < 20; i++) {
                if (i < 17) {
                        sprtrs += "\\";
                        sprtrs += g->separators[i];
                }
                else {
                        sprtrs += "\\s";
                        sprtrs += g->separators[i];
                        sprtrs += "\\s";
                }
                if (i != 19)
                        sprtrs += "|";
        }
        const regex sep(sprtrs);
        while (regex_search(g->programm, m, sep)) {
                int start = m.position();
                str.clear();
                if (start != 0) {
                        for (int j = 0; j < start; j++) {
                                str += g->programm[j];
                        }
                        int count = 0;
                        for (int j = 0; j < 15; j++) {
                                if (str == g->reserved[j]) {
                                        g->id_table.push_back(0);
                                        g->id_element.push_back(j);
                                        count++;
                                }
                        }
                        if (count == 0) {
                                count_names++;
                                g->names.push_back(str);
                                g->id_table.push_back(2);
                                g->id_element.push_back(count_names);
                        }
                }
                int id;
                for (int i = 0; i < 20; i++) {
                        if (m.str() == g->separators[i]) {
                                id = i;
                        }
                }
                if (m.str() != " ") {
                        g->id_table.push_back(1);
                        g->id_element.push_back(id);
                }
                g->programm = m.suffix();
        }
        cout << "Number of table:   ";
        for (int n : g->id_table)
                cout << n << " ";
        cout << endl << "Number of element: ";
        for (int n : g->id_element)
                cout << n << " ";
        cout << endl;
}

int main (int argc, char const *argv[]) {
        if (argc == 1)  {
                Grammar g;
                scanner(&g);
                return 0;
        }
        else {
                return -1;
        }
}
