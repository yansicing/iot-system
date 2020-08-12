#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QLayout>
#include <QtWidgets>

#include <QSerialPort>
#include <QSerialPortInfo>
// QSerialPort类提供了对串口的操作
// QSerialPortInfo类提供了对串口信息的获取。
namespace Ui
{
    class Widget;
}
// class 派生类名 : 继承方式 基类名
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
/* Coding by YangQing  */
// 标签
    QLabel *label_temp;                   // 温度
    QLabel *label_tempNum;                // 温度数值
    QLabel *label_centigrade;             // 温度单位

    QLabel *label_humi;
    QLabel *label_humiNum;
    QLabel *label_rh;

    QLabel *label_light;
    QLabel *label_lightNum;
    QLabel *label_lux;

    QLabel *label_fan;

    QLabel *label_led;

    QLabel *label_buzzer;

    QLabel *label_port;
// 按钮
    QPushButton *button_stop;
    QPushButton *button_first;
    QPushButton *button_second;
    QPushButton *button_third;

    QPushButton *button_ledOpen;
    QPushButton *button_ledClose;

    QPushButton *button_buzzerOpen;       // 蜂鸣器开
    QPushButton *button_buzzerClose;      // 蜂鸣器关

    QPushButton *button_openPort;         // 打开串口
    QPushButton *button_closePort;        // 关闭串口
// 串口
    QSerialPort *my_serialport;           // 串口

    QComboBox *comboBoxPort ;             // 下拉列表框

    QTextEdit *textEdit ;                 // 多行文本框

    bool sent(int num);

private slots:
// 槽函数
    void my_readuart();                   // 串口接收数据槽函数

    void on_button_stop_clicked();        // 停止风扇
    void on_button_first_clicked();       // 一档风扇
    void on_button_second_clicked();      // 二档风扇
    void on_button_third_clicked();       // 三档风扇

    void on_button_ledOpen_clicked();     // 开led灯
    void on_button_ledClose_clicked();    // 关led灯

    void on_button_buzzerOpen_clicked();  // 开警报
    void on_button_buzzerClose_clicked(); // 关警报

    void on_button_openPort_clicked();    // 串口开始工作
    void on_button_closePort_clicked();   // 串口停止工作
};

#endif // WIDGET_H

/*****************************************************************
 * namespaceUi{classWidget;}是前向声明，
 * Ui::Widget类就是在生成项目时，
 * 用uic工具编译widget.ui得到的ui_widget.h里的辅助构建界面类的名字。
 * 使用前向声明配合后续定义的类成员指针（Ui::Widget *ui），
 * 就可以方便地使用辅助构建界面类Ui::Widget，而不需要在头文件里包含ui_widget.h。
 * 全局类 Widget ，和Ui::Widget有重名，但有名字空间前缀区别。在Ui名字空间里的是辅助构建界面的类。
 * 不带名字空间前缀的是全局类，从QWidget继承而来，这是真正的窗口类，
 * 类定义开头必须要有Q_OBJECT宏以支持元对象系统。
 * 元对象系统最主要的一个功能就是实现信号和槽.
 * 将 Q_OBJECT 放在类声明的私有段落，以启用元对象特性，
 * 如动态属性、信号和槽等。之前遇到的例子 Q_OBJECT 都是在类声明里的第一行，
 * 没有加 private 字样，因为类声明默认就是私有的。
 * explicit关键字是强调必须显式构造该类对象，
 * 不使用隐式转换间接生成该类的对象。
 * 构造函数里的参数只有父类对象指针，默认的0（NULL）代表没有父窗口，
 * 也就是以操作系统桌面为父窗口的意思。类定义里最后一行定义了 Ui::Widget类的指针，
 * 这时还没有创建实际的辅助构建类的对象，指针目前没有初始化，只是起到占位的作用，以后才会给它赋值。

 */

/*
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
*/
