#include "groupeditdialog.h"
#include "ui_groupeditdialog.h"
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "macros.h"
#include "userswidget.h"

GroupEditDialog::GroupEditDialog(Group* group, Normal* normal, QWidget* parent) : QDialog(parent), ui(new Ui::GroupEditDialog), _group(group), _normal(normal) {
  ui->setupUi(this);

  renderData();
}

GroupEditDialog::~GroupEditDialog() {
  delete ui;
}

void GroupEditDialog::on_usersPB_clicked() {
  FUNCTION
  UsersWidget* uw = new UsersWidget(_group);
  uw->show();
}

void GroupEditDialog::done(int r) {
  if(r == Accepted) {
    _group->name(ui->nameLE->text());
    _group->save();

    _normal->speed(ui->normalTypeSpeedLE->text().toInt());
    _normal->save();
  }

  QDialog::done(r);
}

void GroupEditDialog::renderData() {
  ui->usersPB->setVisible(_group->pk().isValid());

  ui->nameLE->setText(_group->name());
  ui->normalTypeSpeedLE->setText(QString::number(_normal->speed()));
}
