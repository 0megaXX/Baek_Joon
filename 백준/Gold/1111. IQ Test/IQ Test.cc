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

using namespace std;
#define MAXX 2147483647



vector<int>v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int n;
    cin >> n;
    v.resize(n);
	for (int a = 0; a < n; a++)
		cin >> v[a];

	if (n == 1) // 알 방도가 없음.
    {
		cout << 'A';
		return 0;
	}
    
	else if (n == 2) // 알 방도가 거의 없음
    {
		if (v[0] == v[1]) 
			cout << v[0];
		else
			cout << 'A';
		return 0;
	}
        
	else
    {
		int a = 0;
		if (v[1] - v[0] != 0) // 두 간격간 차이가 있다면
			a = (v[2] - v[1]) / (v[1] - v[0]); // 서로 몇배의 차이가 나는지

		int b = v[1] - v[0] * a;
       // int b = v[0] % a; 음수인 경우 오작
		
		for (int i = 1; i < n; i++)
			if (v[i] != v[i - 1] * a + b) // 다른 방법으로 생성이 가능하다면 
            {
				cout << 'B';
				return 0;
			}
		
		
		cout << v[n - 1] * a + b;
	}

	return 0;
}
