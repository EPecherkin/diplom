#ifndef USEREDITDIALOG_H
#define USEREDITDIALOG_H

#include <QDialog>
#include <QList>
#include "group.h"
#include "user.h"

namespace Ui {
class UserEditDialog;
}

class UserEditDialog : public QDialog {
  Q_OBJECT

public:
  explicit UserEditDialog(User* user, QWidget* parent = 0);
  ~UserEditDialog();

private slots:
  void renderData();

  void on_computersPB_clicked();
  void on_statisticsPB_clicked();
  void on_exportDataPB_clicked();
  virtual void done(int r);

private:
  Ui::UserEditDialog* ui;
  User* _user;
  QList<Group*> _groups;

};

#endif // USEREDITDIALOG_H
