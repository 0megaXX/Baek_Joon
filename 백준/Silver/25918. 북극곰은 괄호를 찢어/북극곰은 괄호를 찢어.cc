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



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char>st;
    string s;
    int rs = 0;
    int n;
    cin >> n >> s;

    for (int a = 0; a < n; a++)
    {
        if (s[a] == '(' && !st.empty() && st.top() == ')')
            st.pop();
        
        else if (s[a] == '(')
            st.push(s[a]);

        else if (s[a] == ')' && !st.empty() && st.top() == '(')
            st.pop();

        else if (s[a] == ')')
            st.push(s[a]);

        rs = max((int)st.size(), rs);
    }

    // 원하는 문자열을 만들지 못했다면 
    if (!st.empty())
        cout << -1;
    else
        cout << rs;
	return 0;

}