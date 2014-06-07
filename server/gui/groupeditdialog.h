#ifndef GROUPEDITDIALOG_H
#define GROUPEDITDIALOG_H

#include <QDialog>
#include "group.h"

namespace Ui {
class GroupEditDialog;
}

class GroupEditDialog : public QDialog {
  Q_OBJECT

public:
  explicit GroupEditDialog(Group* group = 0, QWidget* parent = 0);
  ~GroupEditDialog();

private slots:
  void on_usersPB_clicked();

private:
  Ui::GroupEditDialog* ui;
  Group* _group;

};

#endif // GROUPEDITDIALOG_H
