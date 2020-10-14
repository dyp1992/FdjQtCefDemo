#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "simple_handler.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int browserId;
private:
    Ui::Widget *ui;
    CefRefPtr<SimpleHandler> m_browserEvent;
    CefRefPtr<CefBrowser> GetBrowserByID(int nWebBrowserID);
public slots:
    void onUrl();

};

#endif // WIDGET_H

/*
 * Browser进程，需要CefApp（SimpleApp实现了这个接口）和CefClient（SimpleHandler实现了这个接口）。
 * 而Renderer进程只要CefApp。
 *
 *CefBrowserProcessHandler和CefRenderProcessHandler两个接口，分别来处理Browser进程和Render进程的个性化的通知
 *
 *
 *示例中的SimpeApp，没有实现CefRenderProcessHandler接口，没有针对Renderer进程做特别处理，
 * 所以当它作为Render进程时，会缺失一部分功能。比如JS与Native代码交互
 *
 * ClientAppBrowser、ClientAppRenderer、ClientAppOther三种CefApp，分别对应Browser、Render及其它类别的三种进程。
 */
