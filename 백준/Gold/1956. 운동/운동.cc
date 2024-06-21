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

using namespace std;
struct Mystruct
{
	int start, end, len;
};
int city, cass;
int MAXX = 987654321;
int arr[401][401];
vector<Mystruct>v;


void floydWarshall() {

    
    for (int a = 1; a <= city; a++)
        for (int b = 1; b <= city; b++) 
           arr[a][b] = MAXX;


    // 입력 받은 간선 정보를 통해 초기 거리 설정
    for (auto& e : v) 
        arr[e.start][e.end] = min(arr[e.start][e.end], e.len);
    

    // 플로이드-와샬 알고리즘 적용
    for (int a = 1; a <= city; a++) 
        for (int b = 1; b <= city; b++) 
            for (int c = 1; c <= city; c++) 
                if (arr[b][c] > arr[b][a] + arr[a][c])  //b에서 c로 바로 가는거보다 도중 a를 거쳐가는게 더 빠르면
                    arr[b][c] = arr[b][a] + arr[a][c];
                
            
        
    
}


int findMinimumCycle() {

    int minimumCycle = MAXX;
    for (int i = 1; i <= city; i++) 
        if (arr[i][i] < minimumCycle) {
            minimumCycle = arr[i][i];
        
    }
    return minimumCycle;
}


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> city >> cass;
	for (int a = 0; a < cass; a++)
	{
		int start, end, len;
		cin >> start >> end >> len;
		v.push_back({ start,end,len });
	}
    floydWarshall();
    int result = findMinimumCycle();

    if (result == MAXX)
        cout << -1;
    else
        cout << result;

}
