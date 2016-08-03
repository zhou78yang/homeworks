#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

bool book[55] = {0}; 
int set[55][10005];
int lens[55];

void unique(int x)
{
    if(book[x]) return ;
    
    book[x] = true;
	sort(set[x], set[x]+lens[x]);

	int j = 0;
	for(int i = 1; i < lens[x]; i++)
	{
		if(set[x][i] != set[x][j])
		{
			set[x][++j] = set[x][i];
		}
	}
	lens[x] = j + 1;
}

double run(int set1, int set2)
{
	unique(set1);
	unique(set2);
	
    int nc = 0, nt = lens[set1] + lens[set2];
	int i = 0, j = 0;
	while(i < lens[set1] && j < lens[set2])
	{
        if(set[set1][i] < set[set2][j]) i++;
        else if(set[set1][i] > set[set2][j]) j++;
        else
		{
			nc++; i++; j++;
		}
	}
    nt -= nc;
	
	return (double)nc / nt * 100;
}

int main()
{
	int n, k;
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> lens[i];
		for(int j = 0; j < lens[i]; j++) cin >> set[i][j];
	}
	
	int set1, set2;
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		cin >> set1 >> set2;
		printf("%.2lf", run(set1, set2));
		cout << "%" << endl;
	}
	return 0;
}
	
