#ifndef CLIENTV8HANDLER_H
#define CLIENTV8HANDLER_H

#include "include/cef_v8.h"

class ClientV8Handler : public CefV8Handler
{
public:
    //ClientV8Handler();

    bool Execute(const CefString& name,
               CefRefPtr<CefV8Value> object,
               const CefV8ValueList& arguments,
               CefRefPtr<CefV8Value>& retval,
               CefString& exception);


private:
    IMPLEMENT_REFCOUNTING(ClientV8Handler)
};

#endif // CLIENTV8HANDLER_H
