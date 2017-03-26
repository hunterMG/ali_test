#include <iostream>
#include <stdlib.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

static char *top_address = NULL;
static const long long _10M = 10000000;
static const long long _2M = 2000000;
static const long long ns = 1000000000;
static long long counter = 0;
steady_clock::time_point start;
steady_clock::time_point stop;

int max(int a, int b) {
	return (((a) > (b)) ? (a) : (b));
}
int f(int x) {
	++counter;
	char c;
	char* cur_address = &c;
	if ((long long)top_address - (long long)cur_address > _2M){
		stop = std::chrono::high_resolution_clock::now();
		cout << "total clock counter:" << chrono::duration_cast<chrono::nanoseconds>(stop - start).count() << "	ns" << endl;
			cout << "iteration counter:" << counter << endl;
			cout << "max x value is:" << x << endl;
			exit(0);
	}
	int s = 0;
	while (x++ > 0) s += f(x);
	return max(s, 1);
}
int main()
{
	start = chrono::high_resolution_clock::now();
	char c;
	top_address = &c;
	f(35);
	return 0;
}
