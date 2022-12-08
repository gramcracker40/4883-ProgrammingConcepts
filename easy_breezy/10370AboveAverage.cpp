#include <fstream>
#include <iostream>
using namespace std;
int main() {

  int testCases;

  cin >> testCases;

  while (testCases--) {
    int aboveAverage = 0, numStudents, gradeHolder;
    cin >> numStudents;

    int total = 0;
    int grades[numStudents];
    
    for (int i = 0; i < numStudents; i++) {
      cin >> gradeHolder;
      total += gradeHolder;
      grades[i] = gradeHolder;
    }
    
    double average = total / numStudents;
    
    for (int j = 0; j < numStudents; j++) {
      if (grades[j] > average)
        aboveAverage++;
    }
    double percentAboveAvg = ((double)aboveAverage / (double)numStudents) * 100;
    
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(3);
    cout << percentAboveAvg << "%" << endl;
  }
  cout << endl; 
}
