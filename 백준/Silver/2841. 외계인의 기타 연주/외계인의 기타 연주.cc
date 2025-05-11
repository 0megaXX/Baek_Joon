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

using namespace std;
#define MAXX 2147483647

    stack<int> st[8];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n, p;
    cin >> n >> p;



   
    int ans = 0;
    for (int a = 0; a < n; a++)  
    { 
        int b, c;
        cin >> b >> c;
        if (st[b].empty())
        {
            st[b].push(c); 
            ans++;
        }
        else if (st[b].top() < c) 
        { 
            st[b].push(c);
            ans++;
        }
        else if (st[b].top() > c) {
           
            while (st[b].top() > c) {
                st[b].pop(); 
                ans++; 
                if (st[b].empty()) {
           
                    st[b].push(c); 
                    ans++; 
                }
            }
            if (st[b].top() < c)
            {
              
                st[b].push(c); 
                ans++;
            }
          
        }
    }
    cout << ans;

    return 0;
}

 