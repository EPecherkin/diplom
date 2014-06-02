#include "groupeditdialog.h"
#include "ui_groupeditdialog.h"

GroupEditDialog::GroupEditDialog(QWidget* parent) : QDialog(parent), ui(new Ui::GroupEditDialog) {
  ui->setupUi(this);
}

GroupEditDialog::~GroupEditDialog() {
  delete ui;
}
