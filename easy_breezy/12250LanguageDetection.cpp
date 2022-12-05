#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  map<string, string> languageMap = {
      {"HELLO", "ENGLISH"},  {"HOLA", "SPANISH"}, {"HALLO", "GERMAN"},
      {"BONJOUR", "FRENCH"}, {"CIAO", "ITALIAN"}, {"ZDRAVSTVUJTE", "RUSSIAN"}};

  string word;
  int caseNumber = 0;

  while (cin >> word) {
    if (word == "#")
      break;
    caseNumber++;

    cout << "Case Number: " << caseNumber << " " << languageMap[word] << endl;
  }
}
