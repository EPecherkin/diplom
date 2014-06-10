#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog {
  Q_OBJECT

public:
  explicit LoginDialog(QWidget* parent = 0);
  ~LoginDialog();

private slots:
  void renderData();
  virtual void done(int r);

private:
  Ui::LoginDialog* ui;

};

#endif // LOGINDIALOG_H
