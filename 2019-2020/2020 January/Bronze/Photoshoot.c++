/*
LANG: C++
PROG: photo
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("photo.in");
	ofstream fout("photo.out");
	int N;
	fin>>N;
	int b[N-1];
	for(int i=0; i<N-1; i++)
		fin>>b[i];
	vector<int> a;
	set<int> cows;
	for(int i=1; i<=N; i++){
		a.push_back(i);
		for(int j=1; j<N; j++){
			a.push_back(0);
			a[j]=b[j-1]-a[j-1];
			if(a[j]>0 && a[j]<=N)
				cows.insert(a[j]);
			else{
				break;
			}
		}
		if(cows.size()==N-1)
			break;
		a.clear();
		cows.clear();
	}
	for(int i=0; i<a.size(); i++){
		fout<<a[i];
		if(i<a.size()-1)
			fout<<" ";
		else
			fout<<endl;
	}
	return 0;
}
