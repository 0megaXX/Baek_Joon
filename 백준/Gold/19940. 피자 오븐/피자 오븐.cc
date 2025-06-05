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
#include <tuple>
#include <regex>

using namespace std;
#define MAXX 2147483647


int arr[10]={0};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n,o=0;
	bool check1=false;
    bool check2=false;
    
	cin>>n;
    
	for(int i=0;i<n;i++)
	{
		check1=false;
		check2=false;
            
		for(int a=0;a<5;a++)
			arr[a]=0;

        int k;
        
		cin>>k;
        
		do{

			if(k==0)
				break;
            
			if(check1==false && check2==false)
			{
				if(k>=60 && check1==false && check2==false)
				{
					k = k-60;
					arr[0]++;
                }
                
				else if(check1==false && k>=36)
				{
					o=60;
					check1=true;
					arr[0]++;
				}
                    
				else
					check2=true;
				
			}
            
			if(check1==true)
			{
				if(o-k>=10)
				{
					arr[2]++;
					o=o-10;
				}
				else
				{
					if(o-k>=6)
					{
						arr[2]++;
						arr[3]=arr[3]+10-(o-k);
						break;
					}
					else
					{
						arr[4] = arr[4]+o-k;
						break;
					}
				}
			}
            
			if(check2==true)
			{
				if(k>=10)
				{
					arr[1]++;
					k=k-10;;
				}
				else
				{
					if(k>=6)
					{
						arr[1]++;
						arr[4]=arr[4]+(10-k);
						break;
					}
					else
					{
						arr[3]=arr[3]+(k);
						break;
					}
				}
			}
            
		}while(true);
        
		for(int a=0;a<5;a++)
			cout<<arr[a]<<' ';
		
		cout<<"\n";
	}

    return 0;
}

