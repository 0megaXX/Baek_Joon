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

vector<int>v;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int N;
 
    int val = 0;
 
    cin >> N;

    v.resize(N);
   
    for (int a = 0; a < N; a++)
        cin >> v[a];
   
    //내림 차순 정렬
    sort(v.rbegin(), v.rend());
   
    val = v[0] + 1;
    int rs = 1;
 
    for (int a = 1; a < N; a++)
    {    
        if (v[a] + N >= val)  //1등할 가능성이 있다면 rs++
            rs++;

        // 최고값 갱신
        val = max(val, v[a] + a + 1);
    }
   
    cout << rs;
   
    return 0;
}