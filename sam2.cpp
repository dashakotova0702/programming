#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    cout << "Неверное количество параметров" << endl;
    return 1;  //в интернете написали, что это закрытие программы с ошибкой, наверное, это нужно
  }
  setlocale(LC_ALL, "rus");
  ifstream file1;
  file1.open(argv[1]);
  if (!(file1.is_open())){
    cout << "Ошибка открытия файла" << endl;
    return 1;
  }
  ofstream file2;
  file2.open(argv[2]);
  if (!(file2.is_open())){
    cout << "Ошибка открытия файла" << endl;
    return 1;
  }
  string str1, str2;
  int i, length;
  while(!file1.eof()){
    getline (file1, str1);
    cout << str1 << endl; //чисто проверочка
    length = str1.length();
    for (i = 0; i < length; i++) {
      if (str1[i] == ' '){
        if (str1[i+1] != ' ')
          str2 += str1[i];
      }
      if (str1[i] != ' ')
        str2 += str1[i];
    }
  }
    cout << str2 << endl; //чисто проверочка
    length = str2.length();
    if (str2[0] == ' ' || str2[length-1] == ' ') {
      if (str2[length-1] == ' ') {
        for (i = 1; i < (length-1); i++) {
          file2 << str2[i];
        }
      }
      else {
        for (i = 1; i < length; i++){
          file2 << str2[i];
        }
      }
    }
    else
      file2 << str2;
  file1.close();
  file2.close();
  return 0;
}
