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
#include <unordered_map>


using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    int t, n, num, start, finish;
    cin >> t;
    vector<int> ary;
    for (int a = 0; a < t; a++)
    {
        cin >> num;
        ary.push_back(num);
    }
    cin >> n;
    for (int a = 0; a < ary.size(); a++)
    {
        if (ary[a] == n)
        {
            cout << 0;
            return 0;
        }
    }
    // n을 포함한 좋은 구간의 개수를 출력해야하니 삽입
    ary.push_back(n);

    sort(ary.begin(), ary.end()); // ary에서 n에 위치를 알 수 있음
    start = n;
    for (int a = 0; a < ary.size(); a++)
    {
        if (ary[a] == n)
        {
            start = ary[a - 1];
            finish = ary[a + 1];
            break;
        }
    }
    int ct = 0;
  
    for (int a = start + 1; a <= n; a++)
    {
        for (int b = n; b <= finish - 1; b++)
        {
            if (a == b)
                continue;
            ct++;
        }
    }
    cout << ct;
	return 0;
}