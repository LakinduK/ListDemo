#include "widget.h"
#include "ui_widget.h"
#include "QInputDialog"

widget::widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    connect(ui->listWidget->selectionModel(),
    SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this,
    SLOT(updateDeleteEnabled()));
}

widget::~widget()
{
    delete ui;
}


void widget::on_addButton_clicked()
{
    QString newText = QInputDialog::getText(this, "Enter text", "Text:");
    if( !newText.isEmpty() )
     ui->listWidget->addItem(newText);

}

void widget::on_deleteButton_clicked()
{
    foreach (QListWidgetItem *item, ui->listWidget->selectedItems())
    delete item;
}

void widget::on_clearButton_clicked()
{

}

void widget::updateDeleteEnabled()
{
    ui->deleteButton->setEnabled(ui->listWidget->selectedItems().count() !=0);
}



