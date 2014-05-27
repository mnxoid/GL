#include <iostream>
using namespace std;
#define DllExport __declspec(dllexport)
extern "C" int DllExport sum(int a, int b);