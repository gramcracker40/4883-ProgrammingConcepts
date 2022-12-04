#include <iostream>
#include <fstream> 
using namespace std;



int main() {

  int testCases, holdOne, holdTwo, sum, caseNumber = 0;

  cin >> testCases;
  
  while(testCases--){

    cin >> holdOne >> holdTwo;
    
    sum = 0;
    caseNumber++;
    
    for(int i = holdOne; i <= holdTwo; i+=2){
      if(i%2 == 0)
        continue;
      else
        sum += i; 
    }

    cout << "Case " << caseNumber << ": " << sum << endl;
  }
  
}
