#include "logindialog.h"
#include "ui_logindialog.h"
#include "server.h"

LoginDialog::LoginDialog(QWidget* parent) : QDialog(parent), ui(new Ui::LoginDialog) {
  ui->setupUi(this);
}

LoginDialog::~LoginDialog() {
  delete ui;
}

void LoginDialog::done(int r) {
  if(r != Accepted) {
    done(r);
    return;
  }

  QString host = ui->adressLE->text();
  qint32 port = ui->portLE->text().toInt();

  Server* server = new Server(host, port, this);
  server->ping();
}
