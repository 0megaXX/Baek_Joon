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


int summ[200001]{0};
int all_summ = 0;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int,pair<int,int>>>v;
    vector<int>LIST;
    int N;
    cin>>N;
    LIST.resize(N);
    for (int a=0;a<N ;a++ )
        {
            int num,val;
            cin>>num>>val;
            v.push_back({val,{num,a}});
        }

    sort(v.begin(),v.end());

   // 전체 값들에 대해 등장한 횟수와 색깔별 등장 횟수를 추적
    map<int, int> value_count;  // 전체값 -> 등장 횟수
    map<int, map<int, int>> color_value_count;  // 색 -> 값 -> 등장 횟수

    for (int a = 0; a < N; a++) {
        int val = v[a].first;              // 현재 공의 값
        int color = v[a].second.first;     // 현재 공의 색깔
        int pos = v[a].second.second;      // 현재 공의 원래 위치


        int tmp = all_summ - summ[color];  // 전체 누적합에서 해당 색깔의 누적합을 뺀 값

      
        int same_val = (value_count[val]-color_value_count[color][val]) * val; // 전체 같은 값에서 현재 같은 값을 빼면 유추가능(현재 색의 누적합은 이미 뺏기에)
       // cout<<same_val<<"-------------------"<<endl;
        tmp-=same_val;



        LIST[pos] = tmp; 

        // 색과 값의 등장 횟수를 기록
        value_count[val]++;
        color_value_count[color][val]++;
        
        
        // 누적합을 업데이트
        summ[color] += val;
        all_summ += val;
    }


    for (int a=0;a<N ;a++ )
        cout<<LIST[a]<<'\n';


}

