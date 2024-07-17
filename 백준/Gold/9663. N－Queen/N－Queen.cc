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
#define MAXX 987654321
using namespace std;

int col[17];
int n;
int ans = 0;
void queen(int x) {
    if (n == x) 
        ans++; // 카운트 증가
    
    else {
        for (int a = 0; a < n; a++) {
            col[x] = a; // 퀸의 위치를 정함
            bool can = true;
            for (int b = 0; b < x; b++) {
                if (col[x] == col[b] // 1. 같은 행에 있는가
                    || abs(col[x] - col[b]) == x - b) // 2. 대각선에 있는가
                {
       
                    can = false; //충돌하면 다른 열의 위치로 놓아야함
                    break;
                }
            }
            if (can)  // 충돌하지 않는다면 다음 행.
                queen(x + 1);
            
        }
    }
} //백트래킹
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    queen(0);
    cout << ans;
  

}
