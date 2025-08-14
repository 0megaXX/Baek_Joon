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


vector<int>v; // 건물 높이
vector<int>v2; // 볼수있는 건물 수
vector<int>v3; // 가장 가까운 건물높이

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    
    v.resize(n);
    v2.resize(n);
    v3.resize(n, -1); // 기본값 -1로 초기화

    for (int i = 0; i < n; i++)
        cin >> v[i];

    // 왼쪽에서 볼 수 있는 건물
    stack<int> st;
    for (int i = 0; i < n; i++) 
    {
        while (!st.empty() && v[st.top()] <= v[i])
            st.pop();

        if (!st.empty()) 
        {
            v2[i] += st.size();
            int dist = i - st.top();
            if (v3[i] == -1 || dist < abs(i - v3[i]) || (dist == abs(i - v3[i]) && st.top() < v3[i])) 
                v3[i] = st.top();
            
        }

        st.push(i);
    }

    while (!st.empty()) st.pop();

    // 오른쪽에서 볼 수 있는 건물
    for (int i = n - 1; i >= 0; i--) 
    {
        while (!st.empty() && v[st.top()] <= v[i])
            st.pop();

        if (!st.empty()) {
            v2[i] += st.size();
            int dist = st.top() - i;
            if (v3[i] == -1 || dist < abs(i - v3[i]) || (dist == abs(i - v3[i]) && st.top() < v3[i])) 
                v3[i] = st.top();
            
        }

        st.push(i);
    }

    // 출력
    for (int i = 0; i < n; i++) 
    {
        cout << v2[i];
        if (v2[i] > 0)
            cout << " " << v3[i] + 1; // 1-based index
        cout << '\n';
    }
    
    return 0;
}

