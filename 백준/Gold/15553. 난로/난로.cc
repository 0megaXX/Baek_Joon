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

using namespace std;
#define MAXX 2147483647

vector<int> v;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
	cin >> N >> K;
    int last =  -1e9;
    for (int a=0; a<N; a++)
    {
        int b;
        cin >> b;
        v.push_back(b - last);
        last = b+1; // 다음
    }
    
    sort(v.begin(), v.end());
    int ans = N;
    for (int a=0; a<N-K; a++) 
        ans += v[a];
    
    cout << ans ;
	return 0;

}