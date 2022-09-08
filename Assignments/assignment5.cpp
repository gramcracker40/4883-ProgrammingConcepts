#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

#define MAX 100000

using namespace std;
//https://www.udebug.com/UVa/161

//below two lines are link to problem
//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&
//page=show_problem&problem=97

void pullInData(vector<int>& stopLights, ifstream &iFile);
bool greenCheck(vector<int> &stopLights, int currT);

int main() {
  ifstream iFile;
  iFile.open("input.txt");
  ofstream oFile;
  oFile.open("output.txt");
  int min = MAX;
  int currT = 0;
  vector<int> stopLights;
  
  //run until the file is empty
  while(!iFile.eof()){
    //arbitrarily large number to make sure the for loop is able to grab
    //the true lowest number
    min = MAX;
    //making sure stopLights has no retained values
    stopLights.clear();

    //storing each set of lights in stopLights
    pullInData(stopLights, iFile);

  
    //grabs the least element and stores in minimum
    for(int i = 0; i< stopLights.size();i++){
      if(stopLights[i] < min){
        min = stopLights[i];
      }
    }
    min -= 5; // to account for yellow

    currT = min; //start the time where the first light turns yellow

    while(currT < 18000){ 
      // if the loop in green check completes, it will return true
      // and the current time that the greens lined up at
      if(greenCheck(stopLights, currT)){
        //setting up the hours minutes and seconds for conversion 
        int hours = (currT/3600);
        int minutes = (currT-(3600*hours))/60;
        int seconds = (currT -(3600*hours)-(minutes*60)); 

        //formatting for the outfile
        oFile <<setfill('0')<<setw(2)<< hours <<":"
              <<setfill('0')<<setw(2)<<minutes<<":"
              <<setfill('0')<<setw(2)<<seconds<< endl;    
        break;
      }
      currT++; // increment time
    }
    // if green check never completes the loop it failed
    if(currT == 18000) {
      oFile << "Signals fail to synchronise in 5 hours\n";
    }
  }
}

//puls in data to the vector to allow processing
void pullInData(vector<int>& stopLights, ifstream &iFile){
  int light = 1;
  while(light!=0){
    
    iFile >> light;             
    stopLights.push_back(light);
  
  }
  stopLights.pop_back();    // pops zero off of back of the vector

  if (stopLights[0] == 0) { // prevents the triple zero at back from running
   exit(0);
  }
  
}

//function call that checks if every element in the vector is green at
//the same time
bool greenCheck(vector<int> &stopLights,int currT){
  //bool green = true;

  for(int i = 0; i < stopLights.size();i++){
    //checking if light is red, will return false
    if(currT % (stopLights[i] * 2)  >= stopLights[i] - 5){ //logic lmao
      return false;
    }
  }

  //if loop complete then they are all green, finally
  return true;
  
}
