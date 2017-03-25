#include <iostream>
#include <stdlib.h>

using namespace std;

int times = 0;
int max(int a, int b) {
	return (((a) > (b)) ? (a) : (b));
}
int f(int x) {
	printf("times:%d\n", ++times);
	int s = 0;
	while (x++ > 0) s += f(x);
	return max(s, 1);
}
int main()
{
	int i;
	f(35); 
	return 0;
}
