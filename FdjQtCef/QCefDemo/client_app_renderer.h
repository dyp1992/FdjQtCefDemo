#ifndef CLIENTAPPRENDERER_H
#define CLIENTAPPRENDERER_H

#include "include/cef_app.h"
#include "include/cef_client.h"
#include "client_v8handler.h"


//与simple_app对应浏览器进程使用
//ClientAppRenderer主要供render进程使用
class ClientAppRenderer :public CefApp,
        public CefRenderProcessHandler
{
public:
    ClientAppRenderer();

    // CefApp methods:
    //This method is called on the render process main thread.
    CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override
    {
        return this;
    }

    // CefRenderProcessHandler methods:
    void OnContextCreated(CefRefPtr<CefBrowser> browser,
                        CefRefPtr<CefFrame> frame,
                        CefRefPtr<CefV8Context> context) override;
    void OnWebKitInitialized() override;

private:
    CefRefPtr<ClientV8Handler> m_v8Handler;

    // Include the default reference counting implementation.
    IMPLEMENT_REFCOUNTING(ClientAppRenderer);
};

#endif // CLIENTAPPRENDERER_H


/*
 * 当我们实现了CefRenderProcessHandler接口，就可以在其OnContextCreated()方法中获取到CefFrame对应的window对象，
 * 在它上面绑定一些JS函数或对象，然后JS代码里就可以通过window对象访问，
 * 如果是函数，就会调用到我们实现的CefV8Handler接口的Execute方法。
 *
 */
