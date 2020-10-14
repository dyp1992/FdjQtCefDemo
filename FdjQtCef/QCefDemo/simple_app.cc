#include "simple_app.h"

#include <string>

#include "simple_handler.h"
#include "include/cef_browser.h"
#include "include/cef_command_line.h"
#include "include/wrapper/cef_helpers.h"

#include <QDebug>
SimpleApp::SimpleApp()
{
    qDebug()<<__func__;
}

void SimpleApp::OnContextInitialized()
{
  CEF_REQUIRE_UI_THREAD();

}
void SimpleApp::OnBeforeCommandLineProcessing(const CefString & process_type, CefRefPtr<CefCommandLine> command_line)
{
    //加载flash插件
    command_line->AppendSwitchWithValue("--ppapi-flash-path", "ppflash/18_0_0_209/pepflashplayer32_18_0_0_209.dll");
    //manifest.json中的version
    command_line->AppendSwitchWithValue("--ppapi-flash-version", "18.0.0.209");
    command_line->AppendSwitch("--disable-extensions");
}
