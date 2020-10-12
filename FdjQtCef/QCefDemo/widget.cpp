#include "widget.h"
#include "ui_widget.h"
#include <QDesktopWidget>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    HWND wnd = (HWND)ui->widget->winId();

    CefWindowInfo cefWndInfo;
    //QString strUrl = "https://www.douyu.com";
    QString strUrl ="https://wb2.fudaojun.com/qt6";
    //QString strUrl = "chrome://version";

    RECT winRect;

    QDesktopWidget* pDeskTop = QApplication::desktop();
    QRect qtRect = pDeskTop->screenGeometry();
    winRect.left = qtRect.left();
    winRect.top = qtRect.top();
    winRect.right = qtRect.right();
    winRect.bottom = qtRect.bottom();

    cefWndInfo.SetAsChild(wnd, winRect);  //将cef界面嵌入qt界面中

    CefBrowserSettings cefBrowSetting;
    m_browserEvent = CefRefPtr<SimpleHandler>(new SimpleHandler(this));
    bool browser = CefBrowserHost::CreateBrowser(cefWndInfo, m_browserEvent, strUrl.toStdString(), cefBrowSetting, NULL);
    connect(ui->goButton, SIGNAL(clicked()), this, SLOT(onUrl()));
    showMaximized();
}

Widget::~Widget()
{
    delete ui;
}
CefRefPtr<CefBrowser> Widget::GetBrowserByID(int nWebBrowserID)
{

    for (auto it = m_browserEvent->GetBrowserList().begin(); it != m_browserEvent->GetBrowserList().end(); it++)
    {

        if (nWebBrowserID == it->get()->GetIdentifier())
        {
            return it->get();
        }
    }

    return nullptr;
}
void Widget::onUrl()
{
    CefRefPtr<CefBrowser> pBrower = GetBrowserByID(browserId);
    if (pBrower)
    {
        pBrower->GetMainFrame()->LoadURL(ui->lineEdit->text().toStdString());
    }
}
