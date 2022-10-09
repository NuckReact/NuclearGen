#include "NGpch.h"
#include "IPCMessageHandler.h"

#include "Log/Log.h"

namespace NG
{
    Ref<zmq::context_t> IPCMessageHandler::cont;
    Ref<zmq::socket_t> IPCMessageHandler::socket;
    
    void IPCMessageHandler::Init()
    {
        cont = CreateRef<zmq::context_t>();
        socket = CreateRef<zmq::socket_t>(*cont, zmq::socket_type::rep);

        socket->bind("ipc://NG");
    }

    void IPCMessageHandler::RunMessageHandling()
    {
        for(;;)
        {
            static const std::string data{"World"};
            zmq::message_t request;
            
            socket->recv(request, zmq::recv_flags::none);
            socket->send(zmq::buffer(data), zmq::send_flags::none);
            
            if(request.to_string() == "Hello") break;
        }
    }
}
