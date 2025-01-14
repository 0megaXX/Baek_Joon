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


vector<long long>v;
stack<long long>st;


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    long long n, ans=0; 
    cin >> n;
    for(int a=0; a<n; a++)
    {
        long long b;
        cin >> b;
        if(v.empty() || v.back()!=b) // 붙어있는 수는 연산시 같이 증가하기에 붙어있는건 삽입 안해도 됨 
            v.push_back(b);
   }
    for(int a=0; a<v.size(); a++)
    {
        if(!st.empty() && st.top()<v[a]) // 현재 값이 스택값들 보다 크다면
        {
            ans+=v[a]-st.top(); // add연산을 함 -> 뒤에 값들은 같거나 크기에 현재 값이 최대 연산
                //같은 값이 붙어을 경우 제거해도 무방
            while(!st.empty() && st.top()<v[a]) 
                st.pop();
        }
        st.push(v[a]);
    }

    long long tmp;
    while(st.size()>1) // 남은것들 제거
    {
        tmp=st.top();
        st.pop();
        ans+=st.top()-tmp; // 차이만큼 연산 
    }
    cout << ans;

}
