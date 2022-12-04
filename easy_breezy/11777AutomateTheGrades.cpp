#include <iostream>
#include <fstream>
using namespace std; 

int main() {
  int termOne, termTwo, finals, attendance, testCases, caseNum = 0; 
  int classTestOne, classTestTwo, classTestThree, totalMarks;

  ifstream inputF; 
  inputF.open("input.txt");

  inputF >> testCases; 
  while(testCases--){
    inputF >> termOne >> termTwo >> finals >> attendance >> classTestOne >> classTestTwo >> classTestThree;

    caseNum++; 
    int averageOfTest = 0;
    
    if(classTestOne >= classTestThree && classTestTwo >= classTestThree){
      averageOfTest = (classTestOne + classTestTwo) / 2;
    } else if(classTestTwo >= classTestOne && classTestThree >= classTestOne){
      averageOfTest = (classTestThree + classTestTwo) / 2;
    } else if(classTestOne >= classTestTwo && classTestThree >= classTestTwo){
      averageOfTest = (classTestThree + classTestOne) / 2;
    }
    
    totalMarks = termOne + termTwo + finals + attendance + averageOfTest; 
    
    char letterGrade;

    cout << totalMarks << endl; 
    
    if(totalMarks >= 90)
      letterGrade = 'A';
    else if(totalMarks >= 80 && totalMarks < 90)
      letterGrade = 'B';
    else if(totalMarks >= 70 && totalMarks < 80)
      letterGrade = 'C'; 
    else if(totalMarks >= 60 && totalMarks < 70)
      letterGrade = 'D';
    else if(totalMarks < 60)
      letterGrade = 'E';

    cout << "Case " << caseNum << ": " << letterGrade << endl;
  }

  
}
