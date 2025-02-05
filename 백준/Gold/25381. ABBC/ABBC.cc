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
#define MAXX 99999999


int main() {

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    string abbc;
    int ans = 0, a = 0, b = 0; // a = A의 등장 횟수, b = B의 등장횟수
    cin >> abbc;
    queue<int>q;

    for(int i = 0; i < abbc.length(); i++)
    {
        if(abbc[i] == 'B')
        {
            b++;
            q.push(i);
        }
        
        if(abbc[i] == 'C' && b > 0) // B가 이전에 나왔다면 함께 펑
        {
            b--;
            ans++;
            abbc[q.front()] = 'C';
            q.pop();
        }
    }
    for(int i = 0; i < abbc.size(); i++)
    {
        if(abbc[i] == 'A') 
            a++;
        
        if(abbc[i] == 'B' && a > 0) // A가 이전에 나왔다면 함께 펑
        {
            a--;
            ans++;
            
        }
    }
    cout << ans;

}