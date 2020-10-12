#include "widget.h"
#include <QApplication>
#include "simple_app.h"
#include "simple_handler.h"

void QCefInitSettings(CefSettings & settings)
{
   // qDebug()<<"QCefInitSettings";

    //std::string cache_path = AppGetWorkingDirectory().toStdString() + "/.cache";//缓存地址
   // CefString(&settings.cache_path) = CefString(cache_path);
    settings.multi_threaded_message_loop = true;//多线程消息循环
    settings.log_severity = LOGSEVERITY_DISABLE;//日志

    settings.no_sandbox = true;//沙盒
}



int QCefInit(int& argc, char** argv)
{
    HINSTANCE hInstance = static_cast<HINSTANCE>(GetModuleHandle(nullptr));

    CefMainArgs mainArgs(hInstance);
    CefRefPtr<SimpleApp> app(new SimpleApp); //CefApp实现，用于处理进程相关的回调。

    int exit_code = CefExecuteProcess(mainArgs, app.get(), nullptr);
    if (exit_code >= 0) {
        return exit_code;
    }

    CefSettings settings;
    QCefInitSettings(settings);

    CefInitialize(mainArgs, settings, app, nullptr);

    return -1;
}

void CefQuit()
{
    CefShutdown();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int result = QCefInit(argc, argv);
    if (result >= 0) {
        return result;
    }
    Widget w;
    w.show();
    a.exec();

    CefQuit();

    return 0;
}
