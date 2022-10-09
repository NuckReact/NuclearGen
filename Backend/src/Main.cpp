#include "NGpch.h"

#include "FrontendProcess/FrontendProcess.h"
#include "IPCMessageHandler/IPCMessageHandler.h"
#include "Log/Log.h"


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cmdShow)
{
    try
    {
        NG::Log::Init();
        NG::FrontendProcess::Init();
        
        DWORD FrontendProcessStatus = NG::FrontendProcess::GetStatus();
        if (FrontendProcessStatus) return FrontendProcessStatus;

        NG::IPCMessageHandler::Init();

        NG::IPCMessageHandler::RunMessageHandling();
    }
    catch (std::runtime_error& e)
    {
        NG_ERROR(e.what());
    }

    return 0;
}
