#include "groupswidget.h"
#include "ui_groupswidget.h"
#include "groupeditdialog.h"

GroupsWidget::GroupsWidget(QWidget* parent) : QWidget(parent), ui(new Ui::GroupsWidget) {
  ui->setupUi(this);

  ui->groupsTW->setRowCount(1);

  QTableWidgetItem* item00 = new QTableWidgetItem("00");
  QTableWidgetItem* item01 = new QTableWidgetItem("01");

  ui->groupsTW->setItem(0, 0, item00);
  ui->groupsTW->setItem(0, 1, item01);
}

GroupsWidget::~GroupsWidget() {
  delete ui;
}

void GroupsWidget::on_groupsTW_doubleClicked(const QModelIndex& index) {
  GroupEditDialog* ged = new GroupEditDialog;
  ged->show();
}

void GroupsWidget::on_addPB_clicked() {
  GroupEditDialog* ged = new GroupEditDialog;
  ged->show();
}
