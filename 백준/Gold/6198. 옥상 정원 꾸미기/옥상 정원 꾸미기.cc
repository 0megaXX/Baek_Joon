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

#define MAXX 987654321
using namespace std;

vector<int>v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cass;
    cin >> cass;

    vector<int> v(cass);
    for (int a = 0; a < cass; a++)
        cin >> v[a];

    stack<int> st;
    long long rs = 0; // 결과값

    for (int i = 0; i < cass; i++) {
        // 현재 건물보다 높은 건물이 있을 때까지 pop
        while (!st.empty() && st.top() <= v[i]) 
            st.pop();
        
        // 스택에 남은 빌딩들의 수만큼 현재 건물이 볼 수 있는 건물
        rs += st.size();
        // 현재 건물을 스택에 추가
        st.push(v[i]);
    }

    cout << rs;
}
