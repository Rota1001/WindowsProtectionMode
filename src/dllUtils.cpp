#include"dllUtils.h"

bool isRundll32(){
    char processName[MAX_PATH] = {0};
    if(GetModuleFileNameA(NULL, processName, MAX_PATH)){
        std::string processNameStr = processName;
        if(processNameStr.find("rundll32.exe") != std::string::npos){
            return 1;
        }
    }
    return 0;
}