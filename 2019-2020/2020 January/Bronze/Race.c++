/*
LANG: C++
PROG: race
*/

#include <bits/stdc++.h>
using namespace std;
int len;
int calc(int maxspeed){
	int rise=0, fall=0, time=0, speed=1;
	while(true){
		rise+=speed;//speed=distance
		time++;
		if(rise+fall>=len)
			return time;
		if(speed>=maxspeed){
			fall+=speed;
			time++;
		}
		if(rise+fall>=len)
			return time;
		speed++;
	}        
}
int main(){
	ifstream fin("race.in");
	ofstream fout("race.out");
	int N;
	fin>>len>>N;
	for(int i=0; i<N; i++){
		int maxspeed;
		fin>>maxspeed;
		fout<<calc(maxspeed)<<endl;
	}
	return 0;
}
		
