#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;

int main() {

  map<string, double> treeCount;
  int treeNumber, totalTrees;
  string holder;
  
  ifstream inputFile;
  inputFile.open("input.txt");

  //grabbing first integer in input
  inputFile >> treeNumber;
  
  //loop through each line of the file, turning holder into the line itself
  while (getline(inputFile, holder)) {
    //if the find method returns the end of the map, it found nothing, insert it
    if (treeCount.end() == treeCount.find(holder)) 
    {
      treeCount.insert({holder, 1});
      totalTrees++; 
    }
    else
    {
      treeCount.find(holder)->second++;
      totalTrees++;
    } 
  }

  //auto sorts the map because of how maps are implemented on the backend
  for(auto iter = treeCount.begin(); iter != treeCount.end(); ++iter){
    cout << iter->first << ": " << (iter->second / totalTrees) * 100 << "\n"; 
  }
}
