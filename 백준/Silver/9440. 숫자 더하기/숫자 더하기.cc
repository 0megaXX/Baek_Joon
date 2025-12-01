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


string addString(const string& a, const string& b) {
    string A = a, B = b;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    string res;
    int carry = 0;
    int n = max(A.size(), B.size());
    for (int i = 0; i < n; ++i) 
    {
        int x = (i < (int)A.size() ? A[i] - '0' : 0);
        int y = (i < (int)B.size() ? B[i] - '0' : 0);
        int s = x + y + carry;
        res.push_back(char('0' + (s % 10)));
        carry = s / 10;
    }
    if (carry)
        res.push_back(char('0' + carry));

    reverse(res.begin(), res.end());
    // remove leading zeros (하지만 둘 다 "0"이면 하나는 남김)
    int i = 0;
    while (i + 1 < (int)res.size() && res[i] == '0')
        ++i;
    if (i > 0) 
        return res.substr(i);

    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) 
    {
        int n;
        if (!(cin >> n)) 

            return 0;
        if (n == 0) 
            break;

        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        sort(v.begin(), v.end());

        bool allZero = true;
        for (int x : v) 
            if (x != 0)
        { allZero = false; 
            break; 
            }
        if (allZero) 
        {
            cout << 0 << '\n';
            continue;
        }

        // 첫 자리로 사용할 non-zero 값들 찾기 (가능하면 두 개)
        vector<bool> used(n, false);
        string num1 = "", num2 = "";

        int idx1 = -1;
        for (int i = 0; i < n; ++i) {
            if (v[i] != 0) { idx1 = i; break; }
        }
        if (idx1 != -1) { num1 += char('0' + v[idx1]); used[idx1] = true; }

        int idx2 = -1;
        for (int i = idx1 + 1; i < n; ++i) {
            if (v[i] != 0) { idx2 = i; break; }
        }
        if (idx2 != -1) { num2 += char('0' + v[idx2]); used[idx2] = true; }

        // 만약 두 번째 non-zero를 못 찾았으면 (non-zero가 1개뿐)
        // num2는 아직 비어있을 수 있음. 그 경우 다음 들어오는 숫자(0 포함)를 num2 첫 자리로 허용.
        if (num2 == "") {
            // 찾을 수 있는 첫 unused 값(0 포함)을 num2에 넣자.
            for (int i = 0; i < n; ++i) {
                if (!used[i]) {
                    num2 += char('0' + v[i]);
                    used[i] = true;
                    break;
                }
            }
        }

        // 남은 숫자들을 길이가 짧은 쪽부터 번갈아 배치
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            if (num1.size() <= num2.size()) num1 += char('0' + v[i]);
            else num2 += char('0' + v[i]);
        }

        // 문자열 덧셈으로 합 출력
        string ans = addString(num1, num2);
        cout << ans << '\n';
    }

    return 0;
}