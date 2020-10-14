#include "client_v8handler.h"
#include <QDebug>

//ClientV8Handler::ClientV8Handler()
//{

//}

bool ClientV8Handler::Execute(const CefString &name, CefRefPtr<CefV8Value> object,
                              const CefV8ValueList &arguments, CefRefPtr<CefV8Value> &retval,
                              CefString &exception)
{
//    qDebug()<<__func__<<" name: "<<QString::fromStdWString(name.c_str());
//    if (name == "NativeLogin")
//    {
//        if (arguments.size() == 2)
//        {
//            CefString strUser = arguments.at(0)->GetStringValue();
//            CefString strPassword = arguments.at(1)->GetStringValue();

//            qDebug()<<"user - "<<QString::fromStdWString(strUser.c_str())<<" ,password -"<<QString::fromStdWString(strPassword.c_str());

//            //TODO: doSomething() in native way

//            retval = CefV8Value::CreateInt(0);
//        }
//        else
//        {
//            retval = CefV8Value::CreateInt(2);
//        }
//        return true;
//    }
//    else if (name == "GetId")
//    {
//        if (arguments.size() == 0)
//        {
//            // execute javascript
//            // just for test
//            CefRefPtr<CefFrame> frame = CefV8Context::GetCurrentContext()->GetBrowser()->GetMainFrame();
//            frame->ExecuteJavaScript("alert('Hello, I came from native world.')", frame->GetURL(), 0);
//            //CefFrame::ExecuteJavaScrip 在native代码中执行JS代码


//            // return to JS
//            retval = CefV8Value::CreateString("72395678");
//            return true;
//        }
//    }
//    // Function does not exist.
//    return false;

    //分发消息
    CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create(name);

    msg->GetArgumentList()->SetSize(arguments.size());

    for (size_t i = 0; i < arguments.size(); ++i)
    {
        if(arguments[i]->IsInt())
            msg->GetArgumentList()->SetString(i,QString::number(arguments[i]->GetIntValue()).toStdString());
        else if(arguments[i]->IsDouble())
            msg->GetArgumentList()->SetString(i,QString::number(arguments[i]->GetDoubleValue()).toStdString());
        else if(arguments[i]->IsBool())
            msg->GetArgumentList()->SetString(i,arguments[i]->GetBoolValue() ? "true" : "false");
        else if(arguments[i]->IsString())
            msg->GetArgumentList()->SetString(i,arguments[i]->GetStringValue());
        else
            msg->GetArgumentList()->SetString(i,"Unknown value");

    }

    //browser->SendProcessMessage(PID_BROWSER, msg);

    return true;

}
