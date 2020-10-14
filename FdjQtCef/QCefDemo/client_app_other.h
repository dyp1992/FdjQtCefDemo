#ifndef CLIENTAPPOTHER_H
#define CLIENTAPPOTHER_H

#include "include/cef_app.h"

class ClientAppOther: public CefApp
{
public:
    ClientAppOther();

private:
    IMPLEMENT_REFCOUNTING(ClientAppOther);
};

#endif // CLIENTAPPOTHER_H
