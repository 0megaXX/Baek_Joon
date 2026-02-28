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


    int T;
    cin >> T;
    while (T--)
    { 
        int A, B;
        cin >> A >> B;

        while (A != B) 
        {
            if (A > B)
                A = A / 2; //큰 값 기준으로 부모

            else 
                B = B / 2;
        }
        cout << A * 10 << "\n";
    }

    return 0;
}