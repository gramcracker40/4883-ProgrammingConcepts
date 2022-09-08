#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main() {

  ifstream inputF;
  inputF.open("input.txt");
  int num1, num2, result;

  
  while(!inputF.eof()){
    cin >> num1 >> num2;
    cout << num1 << num2;
    result = abs(num1 - num2);

    cout << result << endl;
  }
  
}
