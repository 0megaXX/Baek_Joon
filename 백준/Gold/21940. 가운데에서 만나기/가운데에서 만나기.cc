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

#define MAXX 1000000000
using namespace std;



int arr[201][201];
int city, road;

void floyd()
{

    for (int a = 1; a <= city; a++)
        for (int b = 1; b <= city; b++)
            for (int c = 1; c <= city; c++)
                if (arr[b][c] > arr[b][a] + arr[a][c])
                    arr[b][c] = arr[b][a] + arr[a][c];


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int a = 0; a <= 200; a++)
        for (int b = 0; b <= 200; b++)
            arr[a][b] = MAXX;
    cin >> city >> road;

    for (int a = 1; a <= city; a++)
        arr[a][a] = 0;

    for (int a = 0; a < road; a++)
    {
        int start, end, len;
        cin >> start >> end >> len;
        arr[start][end] = len;
    }

    floyd();

    int choice;
    cin >> choice;

    vector<int> friends(choice);
    for (int a = 0; a < choice; a++) 
        cin >> friends[a];
    

    int minDistance = MAXX;
    vector<int> resultCities;

    // 각 도시 a에 대해 왕복 시간이 최소가 되는 도시 찾기
    for (int a = 1; a <= city; a++) 
    {
        int maxRoundTrip = 0;

        for (int friendCity : friends)
            maxRoundTrip = max(maxRoundTrip, arr[friendCity][a] + arr[a][friendCity]);
            // 거리 갱신
        

        if (maxRoundTrip < minDistance) 
        {
            minDistance = maxRoundTrip;
            resultCities.clear();       // 새로운 최소값 발견 시 기존 결과 초기화
            resultCities.push_back(a);  // 최소 도시 번호 추가
        }
        else if (maxRoundTrip == minDistance) 
            resultCities.push_back(a);  // 동일한 최소값의 도시 추가
        
    }

    // 오름차순 출력
    for (int city : resultCities) 
        cout << city << " ";
    
  

    return 0;
}


  