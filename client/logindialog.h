#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QWidget {
  Q_OBJECT

public:
  explicit LoginDialog(QWidget* parent = 0);
  ~LoginDialog();

  int result();

signals:
  void finished(int);

private slots:
  void on_loginPB_clicked();

  void on_exitPB_clicked();

private:
  Ui::LoginDialog* ui;
  int _result;

};

#endif // LOGINDIALOG_H
