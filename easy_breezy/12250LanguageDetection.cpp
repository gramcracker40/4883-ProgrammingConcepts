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

    auto mapIterator = languageMap.find(word);
    if (mapIterator == languageMap.end())
      cout << "Case " << caseNumber << ": "
           << "UNKNOWN" << endl;
    else
      cout << "Case " << caseNumber << ": " << languageMap[word] << endl;
  }
}
