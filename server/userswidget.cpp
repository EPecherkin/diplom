#include "userswidget.h"
#include "ui_userswidget.h"
#include "usereditdialog.h"

UsersWidget::UsersWidget(QWidget* parent) : QWidget(parent), ui(new Ui::UsersWidget) {
  ui->setupUi(this);

  ui->usersTW->setRowCount(1);

  QTableWidgetItem* item00 = new QTableWidgetItem("00");
  QTableWidgetItem* item01 = new QTableWidgetItem("01");
  QTableWidgetItem* item02 = new QTableWidgetItem("02");

  ui->usersTW->setItem(0, 0, item00);
  ui->usersTW->setItem(0, 1, item01);
  ui->usersTW->setItem(0, 2, item02);
}

UsersWidget::~UsersWidget() {
  delete ui;
}

void UsersWidget::on_usersTW_doubleClicked(const QModelIndex& index) {
  UserEditDialog* ued = new UserEditDialog;
  ued->show();
}

void UsersWidget::on_addPB_clicked() {
  UserEditDialog* ued = new UserEditDialog;
  ued->show();
}
