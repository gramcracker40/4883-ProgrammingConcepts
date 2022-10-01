#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool battle(char p1, char p2){
  if(p1 == 'R' && p2 == 'P')
    return false;
  else if(p1 == 'P' && p2 == 'S')
    return false;
  else if(p1 == 'S' && p2 == 'R')
    return false;
  else if(p1 == 'S' && p2 == 'S')
    return false;
  else if(p1 == 'R' && p2 == 'R')
    return false;
  else if(p1 == 'P' && p2 == 'P')
    return false;
  else
    return true;
}

bool onWorld(int r, int c, int rows, int cols){
  return r < rows && r >= 0 && c < cols && c >= 0;
}

int main() {
  
  int testCases = 0, rows = 0, columns = 0, n = 0;
  char holder;

  cin >> testCases;
  
  while(testCases--){
    cin >> rows >> columns >> n;
    char arr[rows][columns];
    
    for(int j = 0; j < rows; j++){
      for(int i = 0; i < columns; i++) {
        cin >> holder;
        arr[j][i] = holder;
      }
    }

    //evaluate changes n times
    while(n--){
      char temp[rows][columns];

      //copying arr into temp
      for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
          temp[i][j] = arr[i][j];
        }
      }

      
      for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
          int battler = arr[i][j];
          bool result; 

          if(onWorld(i, j+1, rows, columns)){
            result = battle(battler, arr[i][j+1]);
            if(result)
              temp[i][j+1] = arr[i][j];
            }

          if(onWorld(i, j-1, rows, columns)){
            result = battle(battler, arr[i][j-1]);
            if(result)
              temp[i][j-1] = arr[i][j];
            }

          if(onWorld(i+1, j, rows, columns)){
            result = battle(battler, arr[i+1][j]);
            if(result)
              temp[i+1][j] = arr[i][j];
            }

          if(onWorld(i-1, j, rows, columns)){
            result = battle(battler, arr[i-1][j]);
            if(result)
              temp[i-1][j] = arr[i][j];
            }
            
        }
      }

      //copying temp back into arr
      for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
          arr[i][j] = temp[i][j];
        }
      } 
      
    }

    //printing out the results formatted as wanted
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < columns; j++) {
        // outputF << arr[i][j];
        cout << arr[i][j];
      }
      // outputF << endl;
      cout << endl;
    }
    if(testCases != 0)
      cout << endl;
    // outputF << endl;
  }
}
