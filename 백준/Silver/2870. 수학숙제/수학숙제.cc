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


int N;
string str;
vector<string> nums;
bool cmp(const string& a, const string& b)
{
    if (a.size() == b.size())
        return a <= b;
    else
        return a.size() <= b.size();

}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while (N--)
    {
        cin >> str;
        string num;
        for (char& c : str)
        {
            if (c >= '0' && c <= '9')
            {
                if (num.size() == 1 && num.front() == '0')
                    num = c;
                
                else
                    num += c;
                
            }
            else if (!num.empty())
            {
                nums.push_back(num);
                num.clear();
            }
        }

        if (!num.empty())
        
            nums.push_back(num);
        
    }

    sort(nums.begin(), nums.end(), cmp);

    for (string& num : nums)
    {
        cout << num << "\n";
    }
    return 0;

}
