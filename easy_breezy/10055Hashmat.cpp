#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main() {

  // ifstream inputF;
  // inputF.open("input.txt");
  // ofstream outputF;
  // outputF.open("output.txt");
  
  long long int num1, num2, result, lastnum1, lastnum2;
  
  
  while(!cin.eof()){
    result = 0;

    cin >> num1 >> num2;

    if (lastnum1 == num1 && lastnum2 == num2) break;
    
    result = abs(num1 - num2);
    cout << result << endl; 

    lastnum1 = num1; 
    lastnum2 = num2; 

  }
}
