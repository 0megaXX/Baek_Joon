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
#include <unordered_map>

using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin >> s;
	stack<char>st;
    int sum = 0;
    int num = 1;
    for (int a = 0; a < s.length(); a++) {
        if (s[a] == '(') 
        {
            st.push(s[a]);
            num *= 2;
        }
        else if (s[a] == '[')
        {
            st.push(s[a]);
            num *= 3;
        }
        else if (s[a] == ')')
        {
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            if (s[a - 1] == '(') 
                sum += num;
            st.pop();
            num /= 2;
        }
        else //a[i]==']'
        {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (s[a - 1] == '[')
                sum += num;
            st.pop();
            num /= 3;
        }
    }
    if (st.empty()) cout << sum;
    else cout << 0;
}