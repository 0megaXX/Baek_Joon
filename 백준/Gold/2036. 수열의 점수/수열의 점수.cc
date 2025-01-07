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



vector<long long>minus_and_zero;
vector<long long>plus_and;

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int n;
  
    cin>>n;
    for (int a=0;a<n ;a++ )
        {
            int b;
            cin>>b;
            if(b<=0)
                minus_and_zero.push_back(b);
            else
                plus_and.push_back(b);

        }

    long long rs = 0;
    bool have;
    if(minus_and_zero.size()>1)
    {
        sort(minus_and_zero.begin(),minus_and_zero.end());

   have = true;
    
    long long tmp_minus = minus_and_zero[0];
    
      for (int a=1;a<minus_and_zero.size() ;a++ )
          {

                if (have)
                {   rs+=(tmp_minus* minus_and_zero[a]);
                    have = false;
                    tmp_minus = 0;
                }
                else
                {
                    tmp_minus= minus_and_zero[a];
                    have = true;
                }

          }

    rs+=tmp_minus;

   
    }
    if(plus_and.size()>=1)
    { 
       sort(plus_and.rbegin(),plus_and.rend());
        long long tmp_plus = plus_and[0];
         have = true;
      for (int a=1;a<plus_and.size() ;a++ )
      {

            if (have)
            {   
                if(plus_and[a]==1)
                {
                    rs+=(tmp_plus+1);
                    
                }
                else
                    rs+=(tmp_plus*plus_and[a]);
                have = false;
                tmp_plus = 0;

             
            }
            else
            {
                tmp_plus=plus_and[a];
                have = true;
            }

      }

    rs+=tmp_plus;

    }
    cout<<rs;
    
	return 0;

}
