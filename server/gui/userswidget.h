#ifndef USERSWIDGET_H
#define USERSWIDGET_H

#include <QWidget>
#include "group.h"

namespace Ui {
class UsersWidget;
}

class UsersWidget : public QWidget {
  Q_OBJECT

public:
  explicit UsersWidget(Group* group = 0, QWidget* parent = 0);
  ~UsersWidget();

private slots:
  void on_usersTW_doubleClicked(const QModelIndex&);
  void on_addPB_clicked();

private:
  Ui::UsersWidget* ui;
  Group* _group;

};

#endif // USERSWIDGET_H
