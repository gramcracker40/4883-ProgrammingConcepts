#include <fstream>
#include <iostream>
using namespace std;

int main() {
  int testCases, num1, num2, num3, caseNum = 0;

  cin >> testCases;

  while (testCases--) {
    caseNum++;
    int arr[3];
    cin >> num1 >> num2 >> num3;

    arr[0] = num1;
    arr[1] = num2;
    arr[2] = num3;

    int maximum = 1000, minimum = 10000;
    for (int i = 0; i < 3; i++) {
      if (arr[i] > maximum) {
        maximum = arr[i];
      }
      if (arr[i] < minimum) {
        minimum = arr[i];
      }
    }

    if (num1 != maximum && num1 != minimum)
      cout << "Case " << caseNum << ": " << num1 << endl;
    else if (num2 != maximum && num2 != minimum)
      cout << "Case " << caseNum << ": " << num2 << endl;
    else if (num3 != maximum && num3 != minimum)
      cout << "Case " << caseNum << ": " << num3 << endl;
  }
}
