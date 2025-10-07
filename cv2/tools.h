// #pragma once -- jenom jednou bude includit
// lepsi pres ifndef
#ifndef H_TOOLS
#define H_TOOLS


#define PI 3.14159

// makro s parametrem
// #define DEBUG
#ifdef DEBUG
#define DEBUG_MSG(val) printf("[DEBUG] val = %d\n", (int)val);
#else
#define DEBUG_MSG(val)
#endif

void print(double d);
double circleArea(double r);
int divide(int a, int b);
#endif