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
#define MAXX 99999999



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;

     bool is_cpp = true;
    
     for(int a=0;a<s.length();a++)
         if(s[a]<=90) // 대문자면
         {
             is_cpp = false;
             break;
         }


  if ((is_cpp && (s[0] == '_' || isdigit(s[0]))) || 
        (!is_cpp && (s[0] == '_' || isupper(s[0]) ||
         s.find('_') != string::npos))
         || s[s.length()-1] =='_')
  {
        cout << "Error!";
        return 0;
    }
    for (int a = 1; a < s.length(); a++) 
        if (s[a] == '_' && s[a-1] == '_') 
        {  // 연속된 언더바가 있으면
            cout << "Error!";
            return 0;
        }

    
    string tmp="";

    if(is_cpp)  // c++ -> java
      for(int a=0;a<s.length();a++)
          {
                if(s[a] == 95) //'_'의 아스키
                    tmp += (s[++a] - 32);

                else // 소문자면
                    tmp+=s[a];

          }
    else // java -> c++
          for(int a=0;a<s.length();a++)
          {
                if(s[a] <=90) // 대문자면
                {
                    tmp+='_';
                    tmp += ((s[a] + 32));
                }
                else // 소문자면
                    tmp+=s[a];

          }

    cout<<tmp;

}

