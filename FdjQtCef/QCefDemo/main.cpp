#include "widget.h"
#include <QApplication>
#include <QStandardPaths>
#include <QDebug>

#include "simple_app.h"
#include "simple_handler.h"


void QCefInitSettings(CefSettings & settings)
{
    QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QString cachePath   = QString("%1/%2_cef_cache").arg(appDataPath).arg("DYPCef");

    std::string cache_path = cachePath.toStdString();//缓存地址
    qDebug()<<"cache_path:"<<cachePath;
    CefString(&settings.cache_path) = CefString(cache_path);
    settings.multi_threaded_message_loop = true;//多线程消息循环
    settings.log_severity = LOGSEVERITY_DISABLE;//日志

    settings.no_sandbox = true;//沙盒
}



int QCefInit(int& argc, char** argv)
{
    HINSTANCE hInstance = static_cast<HINSTANCE>(GetModuleHandle(nullptr));

    CefMainArgs mainArgs(hInstance);

    CefRefPtr<SimpleApp> app(new SimpleApp); //CefApp实现，用于处理进程相关的回调。
//检测是否要启动其它的子进程。此处的CefExecuteProcess是在libcef_dll_wrapper.cc中的，
//它内部又调用了cef_execute_process方法（libcef_dll.cc），
//cef_execute_process又调用了libcef/browser/context.cc文件内实现的CefExecuteProcess方法
    int exit_code = CefExecuteProcess(mainArgs, app.get(), nullptr);
    if (exit_code >= 0) {
        return exit_code;
    }
    //创建Browser进程

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
