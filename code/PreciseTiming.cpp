#include <windows.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	LARGE_INTEGER freq;
	LARGE_INTEGER start_t, stop_t;
	double exe_time;
	QueryPerformanceFrequency(&freq);
	fprintf(stdout, "The frequency of your pc is %d.\n", freq.QuadPart);
	QueryPerformanceCounter(&start_t);
	Sleep(1000);
	QueryPerformanceCounter(&stop_t);
	exe_time = 1e3*(stop_t.QuadPart - start_t.QuadPart) / freq.QuadPart;
	fprintf(stdout, "Your program executed time is %fms.\n", exe_time);
	return 0;
}