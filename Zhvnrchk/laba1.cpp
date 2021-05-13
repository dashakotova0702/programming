#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <regex>
using namespace std;

class Rules {
public:
    string left_symb;
    string right_symb;
};
struct First {
    string unterm;
    list <string> first;
};

class Grammar {
public:
    string programm;
    string reserved[15] = { "int", "float", "bool", "ass", "if", "then", "else", "for", "to", "do", "while", "read", "write", "true", "false" };
    string separators[20] = { "\s", "{", "}", ";", "(", ")", ":", "/", "\n", "[", "]", "<", ">", "=", "+", "-", "*", "or", "and", "not" };
    list <string> names;
    list <int> id_table;
    list <int> id_element;
};

void scanner(Grammar* g) {
    ifstream file("code.txt");
    string code;
    while (getline(file, code))
        g->programm += code;
    file.close();
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
    cout << sprtrs << endl;
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
void find_unterm(Rules* r, Grammar* g, First* f, int count_r) {
    string temp;
    smatch m;
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
    int c = 0;
    const regex sep(sprtrs);
    for (int i = 0; i < count_r; i++) {
        f[c].unterm = r[i].left_symb;
        if (regex_search(r[i].right_symb, m, sep)) {
            int start = m.position();
            if (start == 0) {
                f[c].first.push_front(m[0]);
                c++;
            }
            else {
                f[c].first.push_front(m.prefix());
                if (i + 1 != count_r) {
                    while (r[i + 1].left_symb == f[c].unterm) {
                        if (regex_search(r[i + 1].right_symb, m, sep)) {
                                if (f[c].first.front() != m.prefix())
                                    f[c].first.push_front(m.prefix());
                                i++;
                        }
                        else {
                            if (f[c].first.front() != r[i + 1].right_symb)
                                f[c].first.push_front(r[i + 1].right_symb);
                            i++;
                        }
                        /*    string temp1;
                            smatch m1;
                            temp1 = g->first[c].front();
                            if (f[c].unterm == temp1) {
                                regex_search(r[k].right_symb, m1, sep);
                                int start = m1.position();
                                if (start == 0) {
                                    f[c]->first.push_front(m1[0]);
                                }
                                f[c]->first.push_front(m1.prefix());
                        */
                    }
                }
                c++;
            }
        }
        else {
            f[c].first.push_front(r[i].right_symb);
            if (i + 1 != count_r) {
                while (r[i + 1].left_symb == f[c].unterm) {
                    if (regex_search(r[i + 1].right_symb, m, sep)) {
                        int start = m.position();
                        if (start == 0) {
                            f[c].first.push_front(m[0]);
                        i++;
                    }
                        else {
                            if (f[c].first.front() != m.prefix())
                                f[c].first.push_front(m.prefix());
                            i++;
                        }
                    }
                    else {
                        if (f[c].first.front() != r[i + 1].right_symb)
                            f[c].first.push_front(r[i + 1].right_symb);
                        i++;
                    }
                }
            }
            c++;
        }
    }
    for (int i = 0; i < count_r; i++) {
        if (f[i].unterm != "") {
            cout << endl << "Unterm: " << f[i].unterm << endl << "First: " << endl;
            for (string n : f[i].first)
                cout << n << " ";
        }
    }
}
void parser(Rules* r, First* f, Grammar* g) {
    string rule;
    fstream fout;
    fout.open("rules.txt");
    smatch m;
    int count = 0;
    while (getline(fout, rule)) {
        count++;
    }
    fout.clear();
    fout.seekg(0);
    r = new Rules[count];
    f = new First[count];
    for (int i = 0; i < count; i++) {
        getline(fout, rule);
        const regex r1("\\->");
        regex_search(rule, m, r1);
        r[i].left_symb = m.prefix();
        r[i].right_symb = m.suffix();
    }
    find_unterm(r, g, f, count);
}

int main(int argc, char const* argv[]) {
    Rules r;
    Grammar g;
    First* f = new First;
    scanner(&g);
    parser(&r, f, &g);
    return 0;
}
