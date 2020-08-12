#include "widget.h"
#include "ui_widget.h"

/*
 * 单冒号后面是对某些成员变量做初始化
 * 例如ui(new Ui::Widget) 代表把ui变量初始化为new Ui::Widget
 * 即初始化一个Widget界面指针，其变量名为ui。
*/
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    // ui->setupUi(this);
    /* Coding by YangQing  */
    this->setWindowTitle("Powered by YangQing");
    QGridLayout *gridLayout = new QGridLayout;
// 温度
    label_temp = new QLabel();
    label_temp->setText("Temp:");        // 温度 Temperature

    label_tempNum = new QLabel();
    label_tempNum->setText("0");

    label_centigrade = new QLabel();
    label_centigrade->setText("℃");     // 摄氏度 Centigrade
// 湿度
    label_humi = new QLabel();
    label_humi->setText("Humi:");        // 湿度 Humidity
    label_humiNum = new QLabel();
    label_humiNum->setText("0");
    label_rh = new QLabel();
    label_rh->setText("%RH");            // 相对湿度（Relative humidity）
// 光强
    label_light = new QLabel();
    label_light->setText("Light:");      // 照度 Illuminance
    label_lightNum = new QLabel();
    label_lightNum->setText("0");
    label_lux = new QLabel();
    label_lux->setText("lux");           // 勒克斯
// 风扇
    label_fan = new QLabel();
    label_fan->setText("Fan:");
	button_stop = new QPushButton();
    button_stop->setText("Stop");
	button_first = new QPushButton();
    button_first->setText("First");
	button_second = new QPushButton();
    button_second->setText("Second");
	button_third = new QPushButton();
    button_third->setText("Third");
// LED灯
    label_led = new QLabel();
    label_led->setText("LED:");  
	button_ledOpen = new QPushButton();
    button_ledOpen->setText("Open");  
	button_ledClose = new QPushButton();
    button_ledClose->setText("Close");
// 蜂鸣器警报
    label_buzzer = new QLabel();
    label_buzzer->setText("Buzzer:");
    button_buzzerOpen = new QPushButton();
    button_buzzerOpen->setText("Open");
    button_buzzerClose = new QPushButton();
    button_buzzerClose->setText("Close");
// 工作端口
    label_port = new QLabel();
    label_port->setText("Port:");

    comboBoxPort= new QComboBox();
    QString str = "COM";

    for(int i=1;i<15;i++)
    {
        comboBoxPort->addItem(str+(QString::number(i)));
    }

    comboBoxPort->setCurrentText("COM7");

    button_openPort=new QPushButton;
    button_openPort->setText("Open port");

    button_closePort = new QPushButton;
    button_closePort->setText("Close port");

    // button_closePort->setEnabled(false);
    textEdit=new QTextEdit;
    textEdit->setText("");


    connect(button_stop,SIGNAL(clicked()),this,SLOT(on_button_stop_clicked()));
    connect(button_first,SIGNAL(clicked()),this,SLOT(on_button_first_clicked()));
    connect(button_second,SIGNAL(clicked()),this,SLOT(on_button_second_clicked()));
    connect(button_third,SIGNAL(clicked()),this,SLOT(on_button_third_clicked()));
    connect(button_ledOpen,SIGNAL(clicked()),this,SLOT(on_button_ledOpen_clicked()));
    connect(button_ledClose,SIGNAL(clicked()),this,SLOT(on_button_ledClose_clicked()));
    connect(button_buzzerOpen,SIGNAL(clicked()),this,SLOT(on_button_buzzerOpen_clicked()));
    connect(button_buzzerClose,SIGNAL(clicked()),this,SLOT(on_button_buzzerClose_clicked()));
    connect(button_openPort,SIGNAL(clicked()),this,SLOT(on_button_openPort_clicked()));
    connect(button_closePort,SIGNAL(clicked()),this,SLOT(on_button_closePort_clicked()));

    gridLayout->addWidget(label_temp,0,0);          // 温度
    gridLayout->addWidget(label_tempNum,0,1);
    gridLayout->addWidget(label_centigrade,0,2);

    gridLayout->addWidget(label_humi,1,0);          // 湿度
    gridLayout->addWidget(label_humiNum,1,1);
    gridLayout->addWidget(label_rh,1,2);

    gridLayout->addWidget(label_light,2,0);         // 光强
    gridLayout->addWidget(label_lightNum,2,1);
    gridLayout->addWidget(label_lux,2,2);

    gridLayout->addWidget(label_led,3,0);           // LED灯
    gridLayout->addWidget(button_ledOpen,3,1);
    gridLayout->addWidget(button_ledClose,3,2);

    gridLayout->addWidget(label_buzzer,4,0);        // 蜂鸣器警报
    gridLayout->addWidget(button_buzzerOpen,4,1);
    gridLayout->addWidget(button_buzzerClose,4,2);

    gridLayout->addWidget(label_fan,5,0);           // 风扇
    gridLayout->addWidget(button_stop,5,1);
    gridLayout->addWidget(button_first,5,2);
    gridLayout->addWidget(button_second,5,3);
    gridLayout->addWidget(button_third,5,4);

    gridLayout->addWidget(label_port,6,0);          // 工作端口
    gridLayout->addWidget(comboBoxPort,6,1);
    gridLayout->addWidget(button_openPort,6,2);
    gridLayout->addWidget(button_closePort,6,3);
    gridLayout->addWidget(textEdit,7,0,1,30,Qt::AlignHCenter);

    setLayout(gridLayout);

    my_serialport = new QSerialPort();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::my_readuart()                  // 读取串口数据
{
    QByteArray requestData;
    requestData = my_serialport->readAll(); // 接收数据

    if(requestData.length()>=12)
    {
        // qDebug(requestData);

        float tem = 0;                      // 温度
        float hum = 0;                      // 湿度
        float lti = 0;                      // 光强

        // unsigned char ch = 0;

        tem = (int)requestData.at(5)+((int)requestData.at(6))/100.0;
        hum = (int)requestData.at(7)+((int)requestData.at(8))/100.0;
		lti = (int)requestData.at(12);
		
        // ch=requestData.at(12);
        // lti = (int)ch;

        // textEdit->append(requestData));

        label_tempNum->setText(QString::number(tem));
        label_humiNum->setText(QString::number(hum));
        label_lightNum->setText(QString::number(lti));

        static bool isfan_auto   = false;   // 自动开风扇标识
        static bool isalert_auto = false;   // 自动开警报标识
        static bool islight_auto = false;   // 自动开灯光标识
// 温度
        if(tem>30)                          // 温度超过30度，自动启动风扇
        {
            textEdit->append("The temperature is over 30 degrees, start the fan ...");
            sent(0x42);                     // 风扇二档
            isfan_auto = true;
        }
        else                                // 否则恢复到温度正常时
        {
            if(isfan_auto)                  // 如果是自动开风扇的话，温度正常时自动关闭风扇，如果是人为打开则不关闭
            {
              sent(0x40);                   // 关闭风扇
              textEdit->append("The temperature returns to normal, close the fan ...");
              isfan_auto = false;
            }
        }

        if(tem>36)                          // 温度超过36度，启动警报
        {
            textEdit->append("The temperature is over 36 degrees, start the alarm ...");
            sent(0x51);                     // 开启警报
            isalert_auto = true;
        }
        else                                // 温度恢复正常，关闭警报
        {
            if(isalert_auto)
            {
              sent(0x50);                   // 关闭警报
              textEdit->append("The temperature returns to normal, close the alarm ...");
              isalert_auto = false;
            }
        }
// 光度
        if(lti<40)                          // 光度低于40lx，自动启动照明
        {
            textEdit->append("The luminosity is less than 40lx, start lighting automatically...");
            sent(0x61);                     // 开启LED
            islight_auto = true;
        }
        else if(lti>80)                     // 光度高于80lx，自动关闭照明...
        {
            if(islight_auto)
            {
              sent(0x60);                   // 关闭LED
              textEdit->append("The luminosity is more than 80lx, close lighting automatically...");
              islight_auto = false;
            }
        }

    }
// 非正常数据
    else                                   // 数据长度不足12位，非正常数据!
    {
        QString errMess="The data's length is less than 12, abnormal data!";
        errMess.append(requestData);
        textEdit->append(errMess);
    }
    requestData.clear();
}

/*槽函数*/

// 风扇
void Widget::on_button_stop_clicked()
{
    sent(0x40); // 关闭风扇
}
void Widget::on_button_first_clicked()
{
    sent(0x41); // 风扇一档
}

void Widget::on_button_second_clicked()
{
    sent(0x42); // 风扇二档
}
void Widget::on_button_third_clicked()
{
    sent(0x43); // 风扇三档
}
// LED灯
void Widget::on_button_ledOpen_clicked()
{
    sent(0x61); // 开启LED
}

void Widget::on_button_ledClose_clicked()
{
    sent(0x60); // 关闭LED
}

void Widget::on_button_buzzerOpen_clicked()
{
    sent(0x51); // 开启警报
}

void Widget::on_button_buzzerClose_clicked()
{
    sent(0x50); // 关闭警报
}
// 串口
void Widget::on_button_openPort_clicked()    //开启串口按钮槽函数
{
    qDebug("button_openPort_clicked");

    my_serialport->setPortName(comboBoxPort->currentText());

    if(my_serialport->open(QIODevice::ReadWrite))                  // 打开模式
    {                                                              // 初始化
        my_serialport->setBaudRate(QSerialPort::Baud115200);       // 波特率设置，我们设置为115200
        my_serialport->setDataBits(QSerialPort::Data8);            // 数据位设置，我们设置为8位数据位
        my_serialport->setParity(QSerialPort::NoParity);           // 奇偶校验设置，我们设置为无校验
        my_serialport->setStopBits(QSerialPort::OneStop);          // 停止位设置，我们设置为1位停止位
        my_serialport->setFlowControl(QSerialPort::NoFlowControl); // 控制流

        connect(my_serialport,SIGNAL(readyRead()),this,SLOT(my_readuart()));
        //      ( 信号发出者，发出信号动作，信号接收者，信号接收动作 )
        //        button_9->setEnabled(false);//禁止打开串口按钮
        //        button_10->setEnabled(true);//允许关闭串口按钮

    }
    else
    {
        textEdit->setText("Port not open!");
        qDebug("Port not open!");
    }

}

void Widget::on_button_closePort_clicked()
{
    my_serialport->close();

    if(my_serialport->isOpen())
    {
        textEdit->append("Failed to close port!");
        qErrnoWarning("Failed to close port!！");
    }
    else
    {
        textEdit->append("The port is closed");
    }
}

bool Widget::sent(int num)  // 发送单个数据
{
    const unsigned char ch[1] = {num};
    if(my_serialport->write((char *)ch, 1))
    {
        return true;
    }

    return false;
}

/*
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
*/
