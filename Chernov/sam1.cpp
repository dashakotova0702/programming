#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {
  setlocale(LC_ALL, "rus");
  ifstream file1;                //открытие на чтение 1ого файла
  file1.open(argv[1]);
  ofstream file2;                //открытие на запись 2ого файла
  file2.open(argv[2]);
  string word1 = "0", word2;     //строки для слов
  while(!file1.eof()){
    getline (file1, word2, ' '); //считываем 1 слово
    cout << word2;               //чисто проверка, что все считалось
    if (word1 == "0") {         //проверка для самого первого слова
      word1 = word2;            //запись считанного первого слова в другую строчку
      file2 << word1 << " ";    //вывод слова в файл
    }
    if (word1 != word2) {      //проверка на рядом одинаковые слова
      file2 << word2 << " ";   //вывод слов в файл
      word1 = word2;           //перемещаем считанное слово в строку 1, чтобы потом сравнивать с новым словом
    }
    int length;                //длина слова
    length = word2.length();   //считываем длину
    if (word2[length-1] == '.') //проверяем
      break;                   //если последний символ - точка, то выходим из цикла
  }
  file1.close();               //закрываем файлы
  file2.close();
  return 0;
}
