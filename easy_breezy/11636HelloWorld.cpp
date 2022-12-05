#include <iostream>
#include <fstream> 
#include <bits/stdc++.h>
using namespace std; 

int main() {
  int helloWorlds, caseNum=0; 

  while(helloWorlds != -1){
    int totalCount = 0, pasteCommands = 0;
    
    caseNum++; 
    cin >> helloWorlds; 

    if(helloWorlds == -1)
      break; 

    if(helloWorlds == 2){
      pasteCommands = 1; 
    }else{
      while(helloWorlds>totalCount){ 
        pasteCommands++; 
        totalCount = pow(pasteCommands, 2);
      }
    }
    
    if(helloWorlds == 1){
      pasteCommands = 0; 
    } 
    cout << "Case " << caseNum << ": " << pasteCommands << endl;
  }
}
