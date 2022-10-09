#pragma once

#include "NGpch.h"

namespace NG
{
    class IPCMessageHandler
    {
    public:
        static void Init();

        static void RunMessageHandling();
    protected:
        static Ref<zmq::context_t> cont;
        static Ref<zmq::socket_t> socket;
    };
}
