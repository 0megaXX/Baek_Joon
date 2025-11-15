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

vector<int> v;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int n, num, a, b;
    long long rs = 0;
    cin >> n;

    if (n == 1) // 한명이면 의미없음
    {
        cin >> num;
        cout << num;
        return 0;
    }

    v.resize(n);
   
    for (int a = 0; a < n; a++)
        cin>>v[a];
   
    sort(v.begin(), v.end()); // 오름차순 정렬

    for (int a = 0; a < n / 2; a++)
        rs += (v[n - 1 - a] - v[a]); // 정렬하여 차이가 가장 큰 값 두개의 차이만큼 더함.

    if (n % 2)
        rs += v[n / 2];  // 첫번째 숫자 더하기
    else
        rs += v[n / 2 - 1];

    cout << rs;
   

    return 0;
}