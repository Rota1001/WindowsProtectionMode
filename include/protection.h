#include<Windows.h>
#include<string>
#include"dllUtils.h"

DWORD WINAPI StartFunction(LPVOID);

extern "C" __declspec(dllexport) void StartProtection();