#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stddef.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <sstream>
#include <cmath>
#include<map>
#include <queue>
#include <stack>
#include <cstring>
#include <deque>
#include <set>
#include <unordered_set>
#include <chrono>

using namespace std;
#define MAXX 2147483647


vector<int>weight;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
  int n, c;
  int rs = 0;
  cin >> n >> c;
  weight.resize(n);
    
  for(int a = 0; a < n; a++)
    cin >> weight[a];
  
  sort(weight.begin(), weight.end());

  int left = 0, right = n-1;
  while(left < right)
  {
    if(rs)
        break;

    for(int a = 0; a < n; a++)
    {
        
      if(a == left || a == right)
        continue;
      

      if(weight[left] == c || weight[right] == c || weight[a] == c)
          rs = 1;
      else if(weight[left] + weight[right] == c) 
          rs = 1;
      else if(weight[left] + weight[right] + weight[a] == c)
          rs = 1;

    }
      
    if(weight[left] + weight[right] < c)
        left++;
        
    else if(weight[left] + weight[right] > c) 
        right--;
  }
  cout << rs;

}