#pragma once

namespace NG
{
    class FrontendProcess
    {
    public:
        static void Init();
        inline static  DWORD GetStatus() { return Error; }
    protected:
        inline static HINSTANCE FrontendProcessInstance = nullptr;
        inline static constexpr LPCWSTR exe = L"..\\Frontend\\Frontend.exe";
        inline static DWORD Error = 0;
    };
}
