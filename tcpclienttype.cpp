#include "tcpclienttype.h"

TcpClientType::TcpClientType()
{

}

bool TcpClientType::operator ==(const TcpClientType &type) const
{
    if(this->clientfd == type.clientfd)
    {
        return true;
    }else
    {
        return false;
    }
}

bool TcpClientType::operator !=(const TcpClientType &type) const
{
    if(this->clientfd != type.clientfd)
    {
        return true;
    }else
    {
        return false;
    }
}
