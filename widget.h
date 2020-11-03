#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class widget; }
QT_END_NAMESPACE

class widget : public QMainWindow
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();

private slots:
    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_clearButton_clicked();

     void updateDeleteEnabled();

private:
    Ui::widget *ui;
};
#endif // WIDGET_H
