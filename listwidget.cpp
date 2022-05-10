#include "listwidget.h"
#include "ui_listwidget.h"

#include <QListWidgetItem>
#include <QMessageBox>

ListWidget::ListWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ListWidget)
{
    ui->setupUi(this);

    QStringList list = {"sds", "bla","30","20","+375 99-99-999","3675-5465-7687-3680","206","Hello world!",
                        "05.05.2022","собеседование","хвост за прошлую лабу","пузыыырики","гиги за шаги","Полковнику никтооо...."};
    ui->lwFirst->addItems(list);

}

ListWidget::~ListWidget(){
    delete ui;
}

void ListWidget::move(QListWidget* lw1, QListWidget* lw2){
    if(lw1->selectedItems().empty()){
        QMessageBox::warning(this,"Ошибка","Элементы для перемещения не были выделены.");
        return;
    }
    for(auto i : lw1->selectedItems()){
        lw2->addItem(i->clone());
    }
    qDeleteAll(lw1->selectedItems());
}



void ListWidget::on_pbRight_clicked(){
    if(ui->lwSecond->count() == 0){
        QMessageBox::warning(this,"Ошибка","Список пустой");
        return;
    }
    ui->lwSecond->sortItems(Qt::AscendingOrder);
}

void ListWidget::on_pbLeft_clicked(){
    if(ui->lwFirst->count() == 0){
        QMessageBox::warning(this,"Ошибка","Список пустой");
        return;
    }
    ui->lwFirst->sortItems(Qt::DescendingOrder);
}

void ListWidget::on_pbMore_clicked()
{
    move(ui->lwFirst,ui->lwSecond);
}

void ListWidget::on_pbLess_clicked()
{
    move(ui->lwSecond,ui->lwFirst);
}
