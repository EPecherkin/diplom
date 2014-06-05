#ifndef USERSWIDGET_H
#define USERSWIDGET_H

#include <QWidget>

namespace Ui {
class UsersWidget;
}

class UsersWidget : public QWidget {
  Q_OBJECT

public:
  explicit UsersWidget(QWidget* parent = 0);
  ~UsersWidget();

private slots:
  void on_usersTW_doubleClicked(const QModelIndex&);
  void on_addPB_clicked();

private:
  Ui::UsersWidget* ui;

};

#endif // USERSWIDGET_H
