#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int N, res = 0;
	fin >> N;

	char cur, next = '0';
	fin >> cur;

	for (int i = 1; i < N; i++) {

		fin >> next;
		if (cur != next) { // если блины не равны, то переворачиваем

			res++;
			cur = next; 
		}
	}
	if (next == 'B') res++;

	fout << res;
}

/*
6
wbbbwb

bwbbbw 1

wbbbbw 2

bbbbww 3

wwbbbb 4


wbbbbw

wb -> 1
bb -> 0
bw -> 1

*/
