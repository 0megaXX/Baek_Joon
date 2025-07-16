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

int N;

int s[26], e[26], n[26];
int rs;

void fn(int idx, int summ)
{
    if(idx >= N) // 끝이면 갱신 후 종료
    {
        rs = max(rs, summ);
        return;
    }

    fn(idx + 1, summ); //현재 값 스킵
    fn(idx + 2, summ + n[idx]); //현재 값 선택
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int a=0; a<N; a++)
        cin >> s[a] >> e[a] >> n[a];
    

    fn(0, 0); // 탐색시작

    cout << rs;

    return 0;
}

