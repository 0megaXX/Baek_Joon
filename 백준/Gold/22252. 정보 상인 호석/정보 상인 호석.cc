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

long long Q, N, K, B, C;
long long idx = 0;
string name;
unordered_map<string, int> m;
priority_queue<long long> pq[10001];
long long ans = 0;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>Q;

    for (int a = 0; a < Q; a++) 
    {
		cin >> N >> name;
        
		if (m.find(name) == m.end()) 
			m.insert({name, idx++});
		
		if (N == 1) // 고릴라가 정보 획득
        {
			cin >> K;
			for (int b = 0; b < K; b++) 
            {
				cin >> C;
				pq[m[name]].push(C);
			}
		}
            
		else if (N == 2) // 고릴라에게 정보 구매
        {
			cin >> B;
			long long pq_size = pq[m[name]].size();
            long long len = min(B, pq_size); // 살수 있는 만큼 구매
            
			for (int b = 0; b < len; b++)
            {
				ans += pq[m[name]].top();
				pq[m[name]].pop();
			}
		}

        
	}
   cout<<ans;
	return 0;

}