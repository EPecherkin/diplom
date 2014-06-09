#include "logindialog.h"
#include "ui_logindialog.h"
#include "server.h"
#include "desktopservice.h"

LoginDialog::LoginDialog(QWidget* parent) : QDialog(parent), ui(new Ui::LoginDialog) {
  ui->setupUi(this);
}

LoginDialog::~LoginDialog() {
  delete ui;
}

void LoginDialog::done(int r) {
  if(r != Accepted) {
    QDialog::done(r);
    return;
  }

  QString host = ui->adressLE->text();
  qint32 port = ui->portLE->text().toInt();

  DesktopService::_instance->server = new Server(host, port, this);
  if(!DesktopService::_instance->server->ping()) {
    ui->statusL->setText("can't connect");
    return;
  }

  User* user = DesktopService::_instance->server->getUser(ui->loginLE->text(), ui->passwordLE->text());
  if(user == 0) {
    ui->statusL->setText("can't find user");
    return;
  }

  if(!user->save()) {
    ui->statusL->setText("can't save user");
    return;
  }

  DesktopService::_instance->currentUser = user;

  QDialog::done(r);
}
