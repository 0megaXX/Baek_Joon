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



int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    int n;
    cin >> n;
    
    int ans=1;
	string s, tmp;
    
	cin >> s;
	tmp = s;

	for (int a = 1; a < n; a++) 
    {
		if (s[a] == s[0]) // 돌림노래의 시작을 할 수 있다면
        {
			for (int b = a + 1, idx = 1; idx < n; b++, idx++) 
            {
				if ( b >= n) // 주어진 문자열이 끝나는 경우
                    tmp += s[idx];
				else if (s[b] != s[idx]) // 다르다면 종료
                    break;
			}
			if (tmp.length() >= 2 * n - 1) // 문자열 끝에서 돌림노래를 만든경우 
                break;
		}
	}

    int idx;
	for (int a = 1, b; a < n; a++) 
    {
		idx = 0;
		for (b = 0; idx < n; b++, idx++) 
			if (tmp[a + b] != s[idx]) break;
        
		if (idx == n) 
            ans++;
	}
    
	cout << ans;

    

    return 0;
}