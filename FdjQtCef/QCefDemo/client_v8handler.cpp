#include "client_v8handler.h"
#include <QDebug>

//ClientV8Handler::ClientV8Handler()
//{

//}

bool ClientV8Handler::Execute(const CefString &name, CefRefPtr<CefV8Value> object,
                              const CefV8ValueList &arguments, CefRefPtr<CefV8Value> &retval,
                              CefString &exception)
{
    if (name == "NativeLogin")
    {
        if (arguments.size() == 2)
        {
            CefString strUser = arguments.at(0)->GetStringValue();
            CefString strPassword = arguments.at(1)->GetStringValue();

            qDebug()<<"user - "<<QString::fromStdWString(strUser.c_str())<<" ,password -"<<QString::fromStdWString(strPassword.c_str());

            //TODO: doSomething() in native way

            retval = CefV8Value::CreateInt(0);
        }
        else
        {
            retval = CefV8Value::CreateInt(2);
        }
        return true;
    }
    else if (name == "GetId")
    {
        if (arguments.size() == 0)
        {
            // execute javascript
            // just for test
            CefRefPtr<CefFrame> frame = CefV8Context::GetCurrentContext()->GetBrowser()->GetMainFrame();
            frame->ExecuteJavaScript("alert('Hello, I came from native world.')", frame->GetURL(), 0);
            //CefFrame::ExecuteJavaScrip 在native代码中执行JS代码


            // return to JS
            retval = CefV8Value::CreateString("72395678");
            return true;
        }
    }
    // Function does not exist.
    return false;
}
