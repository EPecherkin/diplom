#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget* parent) : QWidget(parent), ui(new Ui::LoginDialog) {
  ui->setupUi(this);
}

LoginDialog::~LoginDialog() {
  delete ui;
}

int LoginDialog::result() {
  return _result;
}

void LoginDialog::on_loginPB_clicked() {
  _result = QDialog::Accepted;
  this->close();
  emit finished(QDialog::Accepted);
}

void LoginDialog::on_exitPB_clicked() {
  _result = QDialog::Rejected;
  this->close();
  emit finished(QDialog::Rejected);
}
