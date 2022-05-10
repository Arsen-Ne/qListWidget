#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QMainWindow>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ListWidget; }
QT_END_NAMESPACE

class ListWidget : public QMainWindow
{
    Q_OBJECT

public:
    ListWidget(QWidget *parent = nullptr);
    ~ListWidget();

private slots:


    void move(QListWidget*,QListWidget*);
    void on_pbRight_clicked();

    void on_pbLeft_clicked();

    void on_pbMore_clicked();

    void on_pbLess_clicked();

private:
    Ui::ListWidget *ui;
};
#endif // LISTWIDGET_H
