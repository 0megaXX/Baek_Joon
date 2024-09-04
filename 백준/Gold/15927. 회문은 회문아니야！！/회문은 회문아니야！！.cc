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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
   
    bool is_pal = true;

    for (int a = 0; a < s.length() / 2; a++)
        if (s[a] != s[s.length() - 1 - a]) // 팰린드롬이 아니라면
        {
            is_pal = false;
            break;
        }

    bool is_same = true;

    for (int a = 0; a < s.length()-1; a++)
        if (s[a] != s[a + 1]) // 한글자라도 다르단 것은 한글자만 제거해도 팰린드럼이 될수 있다는것
        {
            is_same = false;
            break;
        }


    if (is_same) // 모든글자가 같다면 어떠한 경우에도 팰린드럼
        cout << -1;

    else if (is_pal) // 모든글자가 같지 않은 팰린드럼은 한글자만 제거해도 팰린드럼이 아님.
        cout << s.length()-1;

    else           // 애초에 팰린드럼이 아니라면 그냥 길이 출력
        cout << s.length();


}
