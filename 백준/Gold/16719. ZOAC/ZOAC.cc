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
string s;
bool visited[101];
void fn(int start, int eend)
{
    if (start == eend) // 한글자면 의미 탐색 종료
        return;

    char min_c = 'Z'+1; // 

    int idx = 0; // 가장 작은 글자의 위치
    for (int a = start; a < eend; a++)
        if (s[a] < min_c)
        {
            min_c = s[a]; // 가장 작은 문자 갱신
            idx = a; // 위치 갱신
        }
    
    visited[idx] = 1;
    for (int a = 0; a < s.length(); a++) 
        if (visited[a]) 
            cout << s[a];
    
    cout << '\n';

    fn(idx + 1, eend); // 뒤에를 먼저 완성
    fn(start, idx); // 남은 앞을 완성
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> s;
    fn(0, s.length());
}
