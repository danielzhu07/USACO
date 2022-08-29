/*
LANG: C++
PROG: word
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("word.in");
	ofstream fout("word.out");
	int N, K;
	fin>>N>>K;
	vector<string> words;
	for(int i=0; i<N; i++){
		string temp;
		fin>>temp;
		words.push_back(temp);
	}
	int count=K;
	for(int i=0; i<N; i++){
		if(words[i].length()<=count){
			fout<<words[i];
			count-=words[i].length();
		}
		else{
			fout<<endl<<words[i];
			count=K-words[i].length();
		}
		if(i+1<N && words[i+1].length()<=count)
			fout<<" ";
	}
	return 0;
}
