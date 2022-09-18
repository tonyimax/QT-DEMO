#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        int count = 5;
        QList<QString> list = { "C++", "Python", "Qml" };
        QMap<QString,QList<QString>> map;
        map.insert("QT编程语言",list);

        //行与列数
        ui->tableWidget->setRowCount(count);	//表格行数
        ui->tableWidget->setColumnCount(3);		//表格列数

        //表列头
        ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("类型"));	//修改行表头文字
        //ui->tableWidget->horizontalHeaderItem(0)->setTextColor(QColor(200,111,30));		//QT5 文字颜色
        ui->tableWidget->horizontalHeaderItem(0)->setForeground(QBrush(QColor(200,111,30)));//QT6 文字颜色
        ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("语言"));
        //ui->tableWidget->horizontalHeaderItem(1)->setTextColor(QColor(200,111,30));
         ui->tableWidget->horizontalHeaderItem(1)->setForeground(QBrush(QColor(200,111,30)));//QT6 文字颜色
        ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("操作"));
        //ui->tableWidget->horizontalHeaderItem(2)->setTextColor(QColor(200,111,30));
         ui->tableWidget->horizontalHeaderItem(2)->setForeground(QBrush(QColor(200,111,30)));//QT6 文字颜色

        //表可视与行为控制
        ui->tableWidget->verticalHeader()->setVisible(true);//行头数字列是否可见
        ui->tableWidget->horizontalHeader()->setVisible(true);//列头数字列是否可见
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//表格不可编辑
        ui->tableWidget->showGrid();//显示表格线条

        if(count <= 0) return;
        int row = 0;

        for (QMap<QString,QList<QString>>::iterator i = map.begin(); i != map.end(); i++) {
            if(i.value().size() > 1)	// i中元素项数大于1 才合并单元格
            ui->tableWidget->setSpan(row,0,i.value().size(),1);	//合并单元格
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(i.key()));  //将数据添加到单元格中
            int index = 0;
            for (QList<QString>::iterator j = i.value().begin(); j != i.value().end(); j++) {
                ui->tableWidget->setItem(row,1,new QTableWidgetItem(*j));
                QTableWidgetItem* del = new QTableWidgetItem("删除");
                del->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                //del->setTextColor(QColor(Qt::red));//qt5特性 文字颜色
                del->setForeground(QColor(Qt::red));//qt6特性 文字颜色
                ui->tableWidget->setItem(row,2,del);
                ui->tableWidget->item(row,1)->setCheckState(Qt::Unchecked); //单元格内添加checkbox,Qt::Unchecked 不选择
                row++;
                index++;
            }
        }
        ui->tableWidget->horizontalHeader()->resizeSection(1,300); //调整为以像素为单位的大小

}

MainWindow::~MainWindow()
{
    delete ui;
}

