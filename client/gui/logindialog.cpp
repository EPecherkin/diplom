#include "logindialog.h"
#include "ui_logindialog.h"
#include "server.h"
#include "desktopservice.h"
#include "QFile"

LoginDialog::LoginDialog(QWidget* parent) : QDialog(parent), ui(new Ui::LoginDialog) {
  ui->setupUi(this);

  renderData();
}

LoginDialog::~LoginDialog() {
  delete ui;
}

void LoginDialog::renderData() {
  QString fileName = "user.conf";
  QFile configFile(fileName);
  if(configFile.exists()) {
    configFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream config(&configFile);
    QString host;
    QString port;
    QString login;
    QString password;
    config >> host >> port >> login >> password;
    ui->adressLE->setText(host);
    ui->portLE->setText(port);
    ui->loginLE->setText(login);
    ui->passwordLE->setText(password);
  }
}

void LoginDialog::done(int r) {
  if(r != Accepted) {
    QDialog::done(r);
    return;
  }

  QString host = ui->adressLE->text();
  qint32 port = ui->portLE->text().toInt();
  QString login = ui->loginLE->text();
  QString password = ui->passwordLE->text();

  DesktopService::_instance->server = new Server(host, port, this);
  if(!DesktopService::_instance->server->ping()) {
    ui->statusL->setText("can't connect");
    return;
  }

  User* user = DesktopService::_instance->server->getUser(login, password);
  if(user == 0) {
    ui->statusL->setText("can't find user");
    return;
  }

  if(!user->save()) {
    ui->statusL->setText("can't save user");
    return;
  }

  DesktopService::_instance->currentUser = user;

  QString fileName = "user.conf";
  QFile configFile(fileName);
  configFile.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream config(&configFile);
  config << host << '\n' << port << '\n' << login << '\n' << password;

  QDialog::done(r);
}
