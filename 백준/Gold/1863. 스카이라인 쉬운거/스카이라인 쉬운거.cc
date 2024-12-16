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

	int n,ans=0; 
    cin>>n;
    stack <int> st;
    for(int a=0; a<=n; a++)
    {
        int x,y; // x는 의미없음. 중요한건 높이인 y
        
        if(a!=n) 
            cin >> x >> y; 
            
        else
            y = 0; // 마지막에 0넣어줌

        while(!st.empty() && st.top()>=y) // 스카이라인이 같거나 바뀌었다면
        {
            if(st.top()!=y) // 스카이라인이 낮게 바뀌었다면 건물이 하나 있었던 거임
                ans++;
            
            st.pop(); // 기존의 스카이 라인 제거
        }
        
        st.push(y);
    }
    cout<< ans;
}
