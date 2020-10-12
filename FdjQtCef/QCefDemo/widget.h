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
