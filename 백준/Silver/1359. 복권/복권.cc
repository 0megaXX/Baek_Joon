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


int fn(int num) 
{
    if (num <= 1) 
        return 1;
    else 
        return num * fn(num - 1);
    
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;	

    int dm;	// N개 중 M개를 선택할 경우의 수 (분모)
    int nm;		// 적어도 K개가 같을 경우의 수 (분자)

    cin >> N >> M >> K;

    dm = fn(N) / (fn(M) * fn(N - M));
    nm = 0;

    for (int a = K; a <= M; a++) 
    {
        int f1 = fn(M) / (fn(a) * fn(M - a));

        int f2 = fn(N - M) / (fn(M - a) * fn(N - M - M + a));

        nm += f1 * f2;
    }

    double rs = double(nm) / double(dm);

    cout.precision(10);
    cout << rs;


    return 0;
}