#ifndef GROUPEDITDIALOG_H
#define GROUPEDITDIALOG_H

#include <QDialog>

namespace Ui {
class GroupEditDialog;
}

class GroupEditDialog : public QDialog {
  Q_OBJECT

public:
  explicit GroupEditDialog(QWidget* parent = 0);
  ~GroupEditDialog();

private slots:
  void on_usersPB_clicked();

private:
  Ui::GroupEditDialog* ui;

};

#endif // GROUPEDITDIALOG_H
