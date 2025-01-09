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

int arr[10010]{0};
int n;
int ans = 0;


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

    cin>>n;
    
    for(int a = 1; a <= n; a++)
        cin >> arr[a];

    
    for(int a = 1; a <= n; a++)
    {
        if(arr[a+1] > arr[a+2]) // 왼쪽이 오른쪽보다 더 많아 가운데만 남는 경우
        {
            int count = min(arr[a], arr[a+1] - arr[a+2]); // 오른쪽만큼 왼쪽을 남겨둬야 비용이 최소화.
            ans += 5*count; // 시작과 왼쪽에 대한 2번 구매 연산

            arr[a] -= count;
            arr[a+1] -= count;

            int count2 = min({arr[a],arr[a+1], arr[a+2]});
            ans += 7*count2; // 시작부터 오른쪽까지 3번 연산

            arr[a] -= count2;
            arr[a+1] -= count2;
            arr[a+2] -= count2;
        } 
            
        else
        { 
            
            int count = min({arr[a],arr[a+1], arr[a+2]}); // 최대한 3번 연산
            ans += 7*count;

            arr[a] -= count;
            arr[a+1] -= count;
            arr[a+2] -= count;

            int count2 = min(arr[a], arr[a+1]); // 남은거끼리 2번 연산
            ans += 5*count2;

            arr[a] -= count2;
            arr[a+1] -= count2;
        }
        ans += 3*arr[a]; // 남은 처음 무조건 1번연산밖에 못함
        arr[a] = 0;
    }

    cout << ans;
	return 0;

}
