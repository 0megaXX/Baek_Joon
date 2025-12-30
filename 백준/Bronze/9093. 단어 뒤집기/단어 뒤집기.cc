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
#include <tuple>
#include <regex>

using namespace std;
#define MAXX 2147483647


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
   
    int n;
    cin >> n;
   
    cin.ignore();      
    while(n--)
    {
        stack<char> st;
        string s;
        getline(cin, s);
        s += " ";

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
            {
                while(!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
                cout << s[i];
            }
            else
                st.push(s[i]);
           
        }
        cout<<'\n';
    }

    return 0;
}