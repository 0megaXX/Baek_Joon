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

#define MAXX 987654321
using namespace std;

vector<long long> input(1000001);
vector<long long> input_sum(1000001); // 누적합
vector<long long> same_num(1001); // 나누어 떨어지는수

long long make_len(long long same) 
{
    long long ret = 0;
    if (same >= 2) 
        ret = (same * (same - 1)) / 2;
    

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    long long n, m;
    cin >> n >> m;

    long long ret = 0;

    for (int a = 1; a <= n; a++) 
    {
        cin >> input[a];
        input_sum[a] = (input[a] + input_sum[a - 1]);
        same_num[input_sum[a] % m]++; // 나머지가 같다면 둘의 차이가 같다는것
    }
    same_num[0]++;

    for (int a = 0; a <= m; a++) 
        ret += make_len(same_num[a]);
    
    cout << ret << '\n';


}
