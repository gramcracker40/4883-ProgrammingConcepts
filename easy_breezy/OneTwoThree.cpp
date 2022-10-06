#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {

  int wordCount;
  string word;
  string two = "two", one = "one";

  cin >> wordCount;
  while (wordCount--) {
    cin >> word;

    if (word.length() == 5) {
      cout << "3" << endl;
      continue;
    }

    for (int i = 0; i < word.length(); i++) {
      if (word[i] == one[i] && word[i + 1] == one[i + 1]) {
        cout << "1" << endl;
        break;
      } else if (word[i] == two[i] && word[i + 1] == two[i + 1]) {
        cout << "2" << endl;
        break;
      }
    }
  }
}
