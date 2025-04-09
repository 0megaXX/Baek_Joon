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


int ans = -1;
int N;
string from, to;

char change(char c)
{
    if(c == '0')
        return '1';
    else 
        return '0';
}

void solution(string &s, int cnt, int x)
{
    if(x == N)
    {
        if(s[x-1] == to[x-1])
        {
            if(ans == -1) ans = cnt;
            else ans = min(ans, cnt);
        }
        return;
    }

    if(s[x-1] == to[x-1])
        solution(s, cnt, x+1);
        
    else // 뒤집기
    {
        s[x-1] = change(s[x-1]);
        s[x] = change(s[x]);
        if(x+1 < N)
            s[x+1] = change(s[x+1]);
            solution(s, cnt+1, x+1);
    }
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> N;
    cin >> from >> to; 
    
    string tmp = from;
    solution(from, 0, 1);

    if(ans == -1)
    {
        from = tmp;
        from[0] = change(from[0]);
        from[1] = change(from[1]);
        solution(from, 1, 1);
    }
    cout << ans;
    return 0;
}

