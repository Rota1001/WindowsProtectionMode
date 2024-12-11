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

void killFuncs(){
    std::set<std::wstring> whitelist = {L"C:\\Windows\\System32\\smartscreen.exe", L"C:\\Microsoft Shared\\Phone Tools\\CoreCon\\11.0\\bin\\IpOverUsbSvc.exe" ,L"C:\\Program Files (x86)\\Common Files\\VMware\\USB\\vmware-usbarbitrator64.exe", L"C:\\Program Files (x86)\\VMware\\VMware Workstation\\vmware-authd.exe", L"C:\\Windows\\System32\\consent.exe", L"C:\\Windows\\regedit.exe" ,L"C:\\Program Files (x86)\\VMware\\VMware Workstation\\vmware-tray.exe" ,L"C:\\Program Files\\WindowsApps\\AppleInc.iTunes_12134.4.3008.0_x64__nzyj5cx40ttqa\\AMDS64\\AppleMobileDeviceProcess.exe" ,L"C:\\Program Files\\WindowsApps\\Microsoft.WindowsTerminal_1.21.3231.0_x64__8wekyb3d8bbwe\\OpenConsole.exe" ,L"C:\\Program Files\\WindowsApps\\Microsoft.WindowsTerminal_1.21.3231.0_x64__8wekyb3d8bbwe\\WindowsTerminal.exe" ,L"C:\\Program Files\\WindowsApps\\Microsoft.YourPhone_1.24111.82.0_x64__8wekyb3d8bbwe\\PhoneExperienceHost.exe" ,L"C:\\Program Files\\WindowsApps\\Microsoft.ZuneMusic_11.2410.8.0_x64__8wekyb3d8bbwe\\Microsoft.Media.Player.exe" ,L"C:\\Program Files\\WindowsApps\\Microsoft.ZuneVideo_10.24101.10041.0_x64__8wekyb3d8bbwe\\Video.UI.exe" ,L"C:\\ProgramData\\Microsoft\\Windows Defender\\Platform\\4.18.24090.11-0\\MpDefenderCoreService.exe" ,L"C:\\ProgramData\\Microsoft\\Windows Defender\\Platform\\4.18.24090.11-0\\MsMpEng.exe" ,L"C:\\Users\\rota1001\\.vscode\\extensions\\ms-vscode.cpptools-1.22.11-win32-x64\\bin\\cpptools-srv.exe" ,L"C:\\Users\\rota1001\\.vscode\\extensions\\ms-vscode.cpptools-1.22.11-win32-x64\\bin\\cpptools.exe" ,L"C:\\Users\\rota1001\\AppData\\Local\\Microsoft\\OneDrive\\24.221.1103.0003\\FileCoAuth.exe" ,L"C:\\Users\\rota1001\\AppData\\Local\\Microsoft\\OneDrive\\OneDrive.exe"  ,L"C:\\Windows\\ImmersiveControlPanel\\SystemSettings.exe" ,L"C:\\Windows\\SysWOW64\\vmnat.exe" ,L"C:\\Windows\\SysWOW64\\vmnetdhcp.exe" ,L"C:\\Windows\\System32\\AggregatorHost.exe" ,L"C:\\Windows\\System32\\ApplicationFrameHost.exe" ,L"C:\\Windows\\System32\\CompPkgSrv.exe" ,L"C:\\Windows\\System32\\DriverStore\\FileRepository\\dal.inf_amd64_af50fdb80983f7bc\\jhi_service.exe" ,L"C:\\Windows\\System32\\DriverStore\\FileRepository\\icst_service.inf_amd64_498370087736dc57\\intel_cst_service_standalone.exe" ,L"C:\\Windows\\System32\\DriverStore\\FileRepository\\igcc_dch.inf_amd64_eb09d8513be92967\\OneApp.IGCC.WinService.exe" ,L"C:\\Windows\\System32\\DriverStore\\FileRepository\\iigd_dch.inf_amd64_9489d75a0d766622\\IntelCpHDCPSvc.exe" ,L"C:\\Windows\\System32\\DriverStore\\FileRepository\\intcoed.inf_amd64_cbcebe813d4324dc\\AS\\IAS\\IntelAudioService.exe" ,L"C:\\Windows\\System32\\DriverStore\\FileRepository\\ipf_cpu.inf_amd64_cf5beef3831571d4\\ipf_helper.exe" ,L"C:\\Windows\\System32\\DriverStore\\FileRepository\\ipf_cpu.inf_amd64_cf5beef3831571d4\\ipf_uf.exe" ,L"C:\\Windows\\System32\\DriverStore\\FileRepository\\mewmiprov.inf_amd64_d51901c26227fb29\\WMIRegistrationService.exe" ,L"C:\\Windows\\System32\\DriverStore\\FileRepository\\realtekservice.inf_amd64_3cf99e411755df38\\RtkAudUService64.exe" ,L"C:\\Windows\\System32\\RuntimeBroker.exe" ,L"C:\\Windows\\System32\\SearchIndexer.exe" ,L"C:\\Windows\\System32\\SecurityHealthHost.exe" ,L"C:\\Windows\\System32\\SecurityHealthService.exe" ,L"C:\\Windows\\System32\\SecurityHealthSystray.exe" ,L"C:\\Windows\\System32\\SgrmBroker.exe" ,L"C:\\Windows\\System32\\WUDFHost.exe" ,L"C:\\Windows\\System32\\audiodg.exe" ,L"C:\\Windows\\System32\\conhost.exe" ,L"C:\\Windows\\System32\\csrss.exe" ,L"C:\\Windows\\System32\\ctfmon.exe" ,L"C:\\Windows\\System32\\dllhost.exe" ,L"C:\\Windows\\System32\\drivers\\RivetNetworks\\Killer\\KAPS.exe" ,L"C:\\Windows\\System32\\drivers\\RivetNetworks\\Killer\\KAPSService.exe" ,L"C:\\Windows\\System32\\drivers\\RivetNetworks\\Killer\\KNDBWM.exe" ,L"C:\\Windows\\System32\\drivers\\RivetNetworks\\Killer\\KNDBWMService.exe" ,L"C:\\Windows\\System32\\drivers\\RivetNetworks\\Killer\\KSPS.exe" ,L"C:\\Windows\\System32\\drivers\\RivetNetworks\\Killer\\KSPSService.exe" ,L"C:\\Windows\\System32\\drivers\\RivetNetworks\\Killer\\KillerAnalyticsService.exe" ,L"C:\\Windows\\System32\\drivers\\RivetNetworks\\Killer\\KillerNetworkService.exe" ,L"C:\\Windows\\System32\\dwm.exe" ,L"C:\\Windows\\System32\\fontdrvhost.exe" ,L"C:\\Windows\\System32\\lsass.exe" ,L"C:\\Windows\\System32\\oobe\\UserOOBEBroker.exe" ,L"C:\\Windows\\System32\\services.exe" ,L"C:\\Windows\\System32\\sihost.exe" ,L"C:\\Windows\\System32\\smss.exe" ,L"C:\\Windows\\System32\\spoolsv.exe" ,L"C:\\Windows\\System32\\svchost.exe" ,L"C:\\Windows\\System32\\taskhostw.exe" ,L"C:\\Windows\\System32\\wbem\\WmiPrvSE.exe" ,L"C:\\Windows\\System32\\wininit.exe" ,L"C:\\Windows\\System32\\winlogon.exe" ,L"C:\\Windows\\System32\\wlanext.exe" ,L"C:\\Windows\\SystemApps\\Microsoft.Windows.Search_cw5n1h2txyewy\\SearchApp.exe" ,L"C:\\Windows\\SystemApps\\Microsoft.Windows.SecHealthUI_cw5n1h2txyewy\\SecHealthUI.exe" ,L"C:\\Windows\\SystemApps\\Microsoft.Windows.StartMenuExperienceHost_cw5n1h2txyewy\\StartMenuExperienceHost.exe" ,L"C:\\Windows\\SystemApps\\MicrosoftWindows.Client.CBS_cw5n1h2txyewy\\TextInputHost.exe" ,L"C:\\Windows\\SystemApps\\ShellExperienceHost_cw5n1h2txyewy\\ShellExperienceHost.exe" ,L"C:\\Windows\\explorer.exe" ,L"C:\\intelFPGA_lite\\18.1\\quartus\\bin64\\jtagserver.exe"};
    if(DEBUG){
        whitelist.insert(L"C:\\Users\\rota1001\\Desktop\\tools\\procexp64.exe");
        whitelist.insert(L"C:\\Windows\\System32\\rundll32.exe");
        whitelist.insert(L"C:\\Program Files (x86)\\Microsoft\\EdgeUpdate\\MicrosoftEdgeUpdate.exe");
        whitelist.insert(L"C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe");
    }
    while(true){
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if(hSnapshot == INVALID_HANDLE_VALUE){
            continue;
        }
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof(PROCESSENTRY32W);
        if(Process32FirstW(hSnapshot, &pe)){
            do{
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID);
                if(hProcess){
                    wchar_t processPath[MAX_PATH];
                    if(GetModuleFileNameExW(hProcess, NULL, processPath, MAX_PATH)){
                        if(whitelist.find(processPath) == whitelist.end()){
                            // MessageBoxW(0, processPath, L"info", 0);
                            bool result = TerminateProcess(hProcess, 0);
                            if(!result){
                                // MessageBoxA(0, std::to_string(GetLastError()).c_str(), "info", 0);
                            }else{
                                // MessageBoxW(0, processPath, L"kill", 0);
                            }
                        }
                    }else{

                    }
                    CloseHandle(hProcess);
                }else{
                    // MessageBoxA(0, std::to_string(GetLastError()).c_str(), "get process error", 0);
                }
                
            }while(Process32NextW(hSnapshot, &pe));
        }
        // MessageBoxA(0, "success", "info", 0);
    }
}