#include "NGpch.h"
#include "FrontendProcess.h"

#include "Log/Log.h"

namespace NG
{
    void FrontendProcess::Init()
    {
        if (!FrontendProcessInstance)
        {
            NG_TRACE("Frontend starting up");

            FrontendProcessInstance = ShellExecute(NULL, NULL, exe, NULL, NULL, SW_SHOW);

            if ((INT_PTR)FrontendProcessInstance > 32)
                NG_TRACE("Frontend started up successful");
            else
            {
                Error = GetLastError();
                NG_ERROR("Frontend process creation failed! Error code: {0}", Error);
            }
        }
        else
            NG_INFO("Frontend started up already but Init is called another time!");
    }
}
