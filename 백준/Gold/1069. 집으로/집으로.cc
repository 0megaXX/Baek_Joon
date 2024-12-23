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
#define MAXX 99999999


vector<int>w; // 가로 
vector<int>h; // 세로  
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double X, Y, D, T, ans;
    
	cin >> X >> Y >> D >> T;

	double dist = sqrt(pow(X, 2) + pow(Y, 2)); // 대각선 최단 길이

    // 소수점 9자리를 맞추기 위한 세팅
	cout << fixed;
	cout.precision(9);

	if (D < T) // 점프 가성비가 안나오면
		cout << dist;
	
	else
	{
		ans = dist; // 기본은 걸어가기

		int jump = dist / D; // 점프 횟수 = 거리/점프길이
		dist -= jump * D; // 점프 후 남은 거리

		if (jump == 0) // 점프가 집을 지나갔다면 즉 1번 점프하고 뒤로 돌아 걸어야함
            ans = min(ans, min(T + (D - dist), 2.0 * T)); 
            // 최소 시간은 걸어가는것 혹은 min(점프 후 거꾸로 걸어가는것 vs 한번에 대각선으로 점프 두번해서 가기 )
            
		else  // 점프를 하고 마저 걸어야함
            ans = min(ans, min(jump * T + dist, (jump + 1.0) * T)); 
            // 최소 시간은 걸어가는것 혹은 최대한 일자로 점프후  min( 남은 거리를 걸어가기 vs 남은거리를 걷지 않고 대각선으로 점프 두번해서 가기 )
        
		
		cout << ans;
	}


}

