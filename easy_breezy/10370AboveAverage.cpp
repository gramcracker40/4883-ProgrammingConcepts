#include <fstream>
#include <iostream>
using namespace std;
int main() {

  int testCases, gradeHolder;
  double percentAboveAvg;

  cin >> testCases;

  while (testCases--) {
    double aboveAverage = 0, numStudents;

    cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
      cin >> gradeHolder;

      if (gradeHolder >= 80) {
        aboveAverage++;
      }
    }
    percentAboveAvg = (aboveAverage / numStudents) * 100;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(3);
    cout << percentAboveAvg << "%" << endl;
  }
}
