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
#include <numeric>
#include <stack>

using namespace std;



struct compare
{
 
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first || (a.first == b.first && a.second< b.second);
        //return a.second < b.second || (a.second == b.second && a.first > b.first);
    }

    
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int jyual_cass, bag_cass;
    cin >> jyual_cass >> bag_cass;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> monos;

    for (int a = 0; a < jyual_cass; a++)
    {
        int weight, value;
        cin >> weight >> value;
        monos.push(make_pair(weight, value));

    }
  // priority_queue<int,vector<int>,greater<int>>bag;
    vector<int>bag;

    for (int a = 0; a < bag_cass; a++)
    {
        int b;
         cin >> b;
         bag.push_back(b);
    }

  
    sort(bag.begin(), bag.end());

    /*for (int a = 0; a < jyual_cass; a++)
    {
        cout << monos.top().first << " "<<monos.top().second;
        monos.pop();
    }*/


    /*for (int a = 0; a < bag_cass; a++)
    {
        cout << bag.top() << " ";
        bag.pop();
    }*/


    unsigned long long summ = 0;
    
    priority_queue<int> sub;

    int ct = 0;
    for (int a = 0; a < bag_cass; a++)
    {
        while (!monos.empty() && bag[a] >= monos.top().first)
        {
           
            ct++;
            sub.push(monos.top().second);
            monos.pop();
            if (monos.empty())
                break;
        }
        
        if (!sub.empty())
        {
            summ += sub.top();
            sub.pop();
        }
      
        


    }
    
    cout << summ;
    
}