#include "groupeditdialog.h"
#include "ui_groupeditdialog.h"
#include "macros.h"
#include "userswidget.h"

GroupEditDialog::GroupEditDialog(QWidget* parent) : QDialog(parent), ui(new Ui::GroupEditDialog) {
  ui->setupUi(this);
}

GroupEditDialog::~GroupEditDialog() {
  delete ui;
}

void GroupEditDialog::on_usersPB_clicked() {
  FUNCTION
  UsersWidget* uw = new UsersWidget;
  uw->show();
}
