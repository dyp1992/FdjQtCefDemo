#include "client_app_renderer.h"

#include <QDebug>

ClientAppRenderer::ClientAppRenderer()
    :m_v8Handler(new ClientV8Handler)
{
    qDebug()<<__func__;
}

void ClientAppRenderer::OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
                                         CefRefPtr<CefV8Context> context)
{
    qDebug()<<"ClientAppRenderer::OnContextCreated, create window binding";

    // Retrieve the context's window object.
    CefRefPtr<CefV8Value> object = context->GetGlobal();

    // Create the "NativeLogin" function.
    CefRefPtr<CefV8Value> func = CefV8Value::CreateFunction("NativeLogin", m_v8Handler);

    // Add the "NativeLogin" function to the "window" object.
    object->SetValue("NativeLogin", func, V8_PROPERTY_ATTRIBUTE_NONE);
/*
 * OnContextCreated给window对象绑定了一个NativeLogin函数，这个函数将由ClientV8Handler类来处理，
 * 当HTML中的JS代码调用window.NativeLogin时，ClientV8Handler的Execute方法会被调用。
 */
}

void ClientAppRenderer::OnWebKitInitialized()
{
    qDebug()<<"ClientAppRenderer::OnWebKitInitialized, create js extensions";
    std::string app_code =
        "var app;"
        "if (!app)"
        "    app = {};"
        "(function() {"
        "    app.GetId = function() {"
        "        native function GetId();"
        "        return GetId();"
        "    };"
        "})();";

    CefRegisterExtension("v8/app", app_code, m_v8Handler);
    /*
     * OnWebKitInitialized注册了一个名为app的JS扩展，在这个扩展里为app定义了GetId方法，
     * app.GetId内部调用了native版本的GetId()。HTML中的JS代码可能如下：
     *
     * alert(app.GetId());
     */
}
//当浏览器执行上面的代码时，ClientV8Handler的Execute方法会被调用

