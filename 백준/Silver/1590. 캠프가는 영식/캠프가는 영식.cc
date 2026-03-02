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





int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rs = -1;

    int N, T;
    cin >> N >> T;
    int minn = 1000000;

    for (int i = 1; i <= N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int tmp = a; // 시작

        for (int j = 1; j <= c; j++)
        {
            if (tmp >= T)
            {
                rs = tmp - T;
                break;
            }
            tmp += b; 
        }
        if (rs == -1) 
            continue; 
        minn = min(rs, minn); //최소값 저장
    }

    cout << ((rs == -1) ? -1 : minn);


    return 0;
}