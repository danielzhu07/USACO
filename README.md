# USACO
Hard Problems to Review:
- 2018 January Gold Problem 3: Stamp Painting : Combinatorics
- 2018 February Gold Problem 1: Snow Boots : Very Interesting
- 2018 February Gold Problem 3: Taming the Herd : DP

Come back to:
- 2018 US Open Gold (already did prob 2)

#include <bits/stdc++.h>
using namespace std;
const int maxm = 5e4, maxn = 1e5;
int N, M, X = -1;
vector<vector<int>> obs(maxm), ans(maxn);

int main(){
	ifstream fin("milkorder.in");
	ofstream fout("milkorder.out");
	fin>>N>>M;
	for(int i = 0; i < M; i++){
		int x; fin>>x;
		for(int j = 0; j < x; j++){
			int y; fin>>y;
			obs[i].push_back(y-1);
		}
	}
	int l = 0, r = M-1, mid;
	while(l <= r){
		mid = l + (r-l)/2;
		//mid = (l+r)/2;
		vector<vector<int>> adj(N);
		vector<int> indeg(N, 0);
		for(int i = 0; i <= mid; i++){
			for(int j = 0; j < obs[i].size()-1; j++){
				adj[obs[i][j]].push_back(obs[i][j+1]);
				indeg[obs[i][j+1]]++;
			}
		}
		priority_queue<int, vector<int>, greater<int>> pq;
		for(int i = 0; i < N; i++){
			if(indeg[i] == 0) pq.push(i);
		}
		while(!pq.empty()){
			auto temp = pq.top();
			pq.pop();
			ans[mid].push_back(temp);
			for(int i = 0; i < adj[temp].size(); i++){
				indeg[adj[temp][i]]--;
				if(indeg[adj[temp][i]] == 0) pq.push(adj[temp][i]);
			}
		}
		if(ans[mid].size() != N){
			r = mid-1;
		}
		else{
			X = mid;
			l = mid+1;
		}
	}
	for(int i = 0; i < ans[X].size(); i++){
		fout<<ans[X][i]+1;
		if(i != ans[X].size()-1) fout<<" ";
	}
	fout<<endl;
	return 0;
}
		
