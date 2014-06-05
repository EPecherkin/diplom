#include "usereditdialog.h"
#include "ui_usereditdialog.h"
#include "computerswidget.h"
#include "statisticswidget.h"

UserEditDialog::UserEditDialog(QWidget* parent) : QDialog(parent), ui(new Ui::UserEditDialog) {
  ui->setupUi(this);
}

UserEditDialog::~UserEditDialog() {
  delete ui;
}

void UserEditDialog::on_computersPB_clicked() {
  ComputersWidget* cw = new ComputersWidget;
  cw->show();
}

void UserEditDialog::on_statisticsPB_clicked() {
  StatisticsWidget* sw = new StatisticsWidget;
  sw->show();
}
