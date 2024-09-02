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

int fn(string s, int remove_ct) {
    int start = 0;
    int eend = s.length() - 1;

    while (start < eend)
    {
        if (s[start] == s[eend]) // 양끝이 같다면 투포인터는 다음절차
        {
            start++;
            eend--;
        }
        else // 다르다면 하나지우는 절차
        {
            if (remove_ct == 0)
            {
                // 두 가지 경우를 재귀적으로 확인
                if (fn(s.substr(start + 1, eend - start), 1) == 0 ||
                    fn(s.substr(start, eend - start), 1) == 0) 
                    return 1;  // 유사회문 (한 글자 삭제해서 회문)
                
                else 
                    return 2;  // 회문 아님
                
            }
            else {
                return 2;  // 이미 한 글자를 삭제했으므로 회문 아님
            }
        }
    }
    return 0;  // 회문
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cass;
    cin >> cass;
    while (cass--) 
    {
        string s;
        cin >> s;
        cout << fn(s, 0) << '\n';
    }
}
