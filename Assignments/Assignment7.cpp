#include <iostream>
#include <fstream> 
#include <vector>
#include <stack> 

using namespace std;

vector<int> feedInNumbers(int numOfTracks){
  int holder; 
  vector<int> numbers; 

  for(int i = 0; i < numOfTracks; i++){
    cin >> holder;
    numbers.push_back(holder);
  }

  return numbers;
  
}

int main() {
  int numOfCarts, holder = 1, peak;
  vector<int> numbers;
  bool end = false, loop = false;


  while(end == false){
    cin >> numOfCarts;

    while(loop == false){
      vector<int> nums; 
      cin.get();
      char peek = cin.peek();

      if(peek == '0'){
        loop = true;
        break;
      }
      
      nums = feedInNumbers(numOfCarts);
      
      vector<int> order, finals; 
      
      for(int i = 0; i < nums.size(); i++){
        order.push_back(i + 1); 
      }
      
      stack<int> check; 
      bool finalizer = false;
      int counter = 0, place = 0, sec_counter = 0; 
      
      while(finalizer == false){
        if(order.size() != 0){
          while(order.size() != 0){
            if(nums[counter] == order[sec_counter]){
              finals.push_back(order[sec_counter]);
              order.erase(order.begin());
              counter++;
            }
            else if(check.size() > 0 && nums[counter] == check.top()){
              finals.push_back(check.top());
              check.pop(); 
              counter++;
            }
            else{
              check.push(order[sec_counter]);  
              order.erase(order.begin());
            } 
          }
        }

        if(check.size() != 0){
          place = check.top();
          if(place != nums[counter]){
            cout << "No" << endl; 
            finalizer = true;
          }else{
            finals.push_back(nums[counter]);
            counter++;
          }
          check.pop();
        }

        if(order.size() == 0 && check.size() == 0 && finalizer == false){
          cout << "Yes" << endl;
          finalizer = true;
        }
      }
      
    }
    cout << endl;
    cin >> holder >> ws; 
    char peek = cin.peek();

    if(peek == '0'){
      end = true;
    }
    loop = false;
  }

  }
  
