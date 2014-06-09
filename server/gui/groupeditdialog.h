#ifndef GROUPEDITDIALOG_H
#define GROUPEDITDIALOG_H

#include <QDialog>
#include "group.h"
#include "normal.h"

namespace Ui {
class GroupEditDialog;
}

class GroupEditDialog : public QDialog {
  Q_OBJECT

public:
  explicit GroupEditDialog(Group* group, Normal* normal, QWidget* parent = 0);
  ~GroupEditDialog();

private slots:
  void renderData();

  void on_usersPB_clicked();
  virtual void done(int r);

private:
  Ui::GroupEditDialog* ui;
  Group* _group;
  Normal* _normal;

};

#endif // GROUPEDITDIALOG_H
