#include "groupeditdialog.h"
#include "ui_groupeditdialog.h"
#include "macros.h"
#include "userswidget.h"

GroupEditDialog::GroupEditDialog(Group* group, QWidget* parent) : QDialog(parent), ui(new Ui::GroupEditDialog), _group(group) {
  ui->setupUi(this);
}

GroupEditDialog::~GroupEditDialog() {
  delete ui;
}

void GroupEditDialog::on_usersPB_clicked() {
  FUNCTION
  UsersWidget* uw = new UsersWidget(_group);
  uw->show();
}
