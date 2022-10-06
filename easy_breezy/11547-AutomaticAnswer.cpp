#include <iostream>
using namespace std;

int main() {
  int t, num, calculator, result;

  cin >> t;

  while (t--) {
    cin >> num;

    calculator = (((((num * 567) / 9) + 7492) * 235) / 47) - 498;

    result = (calculator % 100) / 10;

    cout << abs(result) << endl; 
  }
}
