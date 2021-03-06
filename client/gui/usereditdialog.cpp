#include "usereditdialog.h"
#include "ui_usereditdialog.h"
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "macros.h"
#include "desktopservice.h"
#include "computerswidget.h"
#include "statisticswidget.h"
#include "exportwidget.h"

UserEditDialog::UserEditDialog(User* user, QWidget* parent) : QDialog(parent), ui(new Ui::UserEditDialog), _user(user), _groups(QList<Group*>()) {
  ui->setupUi(this);

  renderData();
}

UserEditDialog::~UserEditDialog() {
  delete ui;
}

void UserEditDialog::on_updateProfilePB_clicked() {
  _user->login(ui->loginLE->text());
  _user->firstName(ui->firstNameLE->text());
  _user->lastName(ui->lastNameLE->text());
  _user->middleName(ui->middleNameLE->text());

  QString password = ui->passwordLE->text();
  if(password.isEmpty())
    _user->password(password);

  if(_user->save() && DesktopService::_instance->server->ping()) {
    DesktopService::_instance->server->updateUser(_user);
  }
}

void UserEditDialog::on_computersPB_clicked() {
  FUNCTION
  ComputersWidget* cw = new ComputersWidget(_user);
  cw->show();
}

void UserEditDialog::on_statisticsPB_clicked() {
  FUNCTION
  StatisticsWidget* sw = new StatisticsWidget(_user);
  sw->show();
}

void UserEditDialog::on_exportDataPB_clicked() {
  FUNCTION
  ExportWidget* ew = new ExportWidget(_user);
  ew->show();
}

void UserEditDialog::renderData() {
  FUNCTION
  ui->loginLE->setText(_user->login());
  ui->firstNameLE->setText(_user->firstName());
  ui->lastNameLE->setText(_user->lastName());
  ui->middleNameLE->setText(_user->middleName());
}
