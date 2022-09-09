#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector> 
#include <iomanip>
using namespace std;

int main() {

  map<string, double> treeCount;
  int numCases, totalTrees;
  string holder;
  vector<map<string, double>> cases;
  vector<int> treeCounts; 
  // ifstream inputFile;
  // ofstream outputFile; 
  // inputFile.open("input.txt");
  // outputFile.open("output.txt");
  
  //grabbing first integer in input
  cin >> numCases;
  
  cin.ignore(2); 
  for(int i = 0; i < numCases; i++){
    //inputFile.ignore();
    //loop through each line of the file, turning holder into the line itself
    totalTrees = 0; 
    while (getline(cin, holder)) {
      //if the find method returns the end of the map, it found nothing, insert it
      if (holder == ""){
        
        cases.push_back(treeCount);
        treeCounts.push_back(totalTrees); 
        treeCount.clear();
        break;
      }
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
    
  }

  cases.push_back(treeCount);
  treeCounts.push_back(totalTrees); 

  cout << fixed;
  cout << setprecision(4); 
  
  for(int i = 0; i < cases.size(); i++){
    for(auto iter = cases[i].begin(); iter != cases[i].end(); ++iter){
      cout << iter->first << " " << (iter->second / treeCounts[i]) * 100 << "\n"; 
    }
    if(i == cases.size() - 1)
      break;
    else
      cout << endl;
  }
  //auto sorts the map because of how maps are implemented on the backend
  
}

  //MAP NOTES
  //checking if a key exists within a map
  // if (wordMap.count("hat") > 0)
  //   {
  //       std::cout << "'hat' Found" << std::endl;
  //   }
  
  // myMap.insert(pair<string, int>("stringVal", 0));
  // myVector.push_back("stringVal");

  // treeCount.insert({"Hardwood", 2});

  // auto place = treeCount.find("Hardwood");

  // cout << place->first;
  // cout << place->second;

