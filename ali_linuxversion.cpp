#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
 static char *top_address = NULL;
    static const long long _10M = 10000000;
    static const long long _2M = 2000000;
    static const long long ns = 1000000000;
    static long long counter = 0;
    timespec start;
    timespec stop;
int max(int a, int b) {
        return (((a) > (b)) ? (a) : (b));
}
long long diff(timespec start, timespec stop)
{
    return (stop.tv_sec-start.tv_sec)*ns +(stop.tv_nsec - start.tv_nsec);
}
int f(int x) {
        ++counter;
        char c;
        char* cur_address = &c;
        if((long long)top_address-(long long)cur_address> _2M)
        {
           clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
           cout<<"total clock counter:"<< diff(start, stop) <<"ns"<<endl;
           cout<<"iteration counter:"<< counter <<endl;
           cout<<"max x value is:"<< x <<endl;
           exit(0);                                                                     }
        int s = 0;
        while (x++ > 0) s += f(x);
        return max(s, 1);
}
int main()
{
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
        char c;
        top_address = &c;
        f(35);
        return 0;
}
