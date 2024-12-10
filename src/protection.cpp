#include"protection.h"




extern "C" __declspec(dllexport) void StartProtection(){
    MessageBoxA(0, "start Protection", "info", 0); 
}

DWORD WINAPI StartFunction(LPVOID lpParam){
    MessageBoxA(0, "yee", "info", 0);    
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH: {
           
            if(!isRundll32()){
                CreateThread(NULL, 0, StartFunction, NULL, 0, NULL);
            }
            break;
        }
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}