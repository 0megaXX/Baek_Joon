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


vector<long long> v;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    v.resize(n);
    
    for (int a=0; a<n;a++)
         cin>> v[a];
 
    
    long long cur = v[n - 1];
    
    int num = -1;   // 현재 값 기준으로 가장 가까우며, 다르게 등장하는 수의 인덱스
    
    stack<int>st;
 
    for (int a = n - 1; a >= 0; a--) 
    {
        if (v[a] == cur) // 기준과 같으면, 기존 기준에서 찾은 인덱스 유지
            st.push(num);
            
        else // 다른 값 발견 > 기준 갱신
        {  
            num = a + 2;    // 1-based 인덱스로 저장
            cur = v[a];
            st.push(num);
        }
    }
 
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

