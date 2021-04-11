#include <iostream>
#include <list>
#include <regex>
using namespace std;

class Grammar {
public:
string programm = "name; float: for;";
string reserved[15] = {"int", "float", "bool", "ass", "if", "then", "else", "for", "to", "do", "while", "read", "write", "true", "false"};
string separators[20] = {" ", "{", "}", ";", "(", ")", ":", "/", "\0", "[", "]", "<", ">", "=", "+", "-", "*", "or", "and", "not"};
list <string> names;
list <int> id_table;
list <int> id_element;
};

void scanner (Grammar* g) {
        string str;
        smatch m;
        int position = 0;
        int count_names = 0;
        //for (int i = 0; i < 20; i++) {
        const regex sep(";|:");
        if (regex_search(g->programm, m, sep)) {
                cout << "!" << endl;
                int start = m.position();
                int end = m.position() + m.size();
                str.clear();
                if (start == 0) {
                        g->id_table.push_back(1);
                        g->id_element.push_back(8);
                }
                else {
                        for (int j = position; j < start; j++) {
                                str += g->programm[j];
                        }
                        position = end++;
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
                        g->id_table.push_back(1);
                        g->id_element.push_back(8);
                }

        }
        //}
        for (int n : g->id_table)
                cout << n << " ";
        cout << endl;
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
