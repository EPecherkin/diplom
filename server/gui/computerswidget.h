#ifndef COMPUTERSWIDGET_H
#define COMPUTERSWIDGET_H

#include <QWidget>
#include "user.h"

namespace Ui {
class ComputersWidget;
}

class ComputersWidget : public QWidget {
  Q_OBJECT

public:
  explicit ComputersWidget(User* user, QWidget* parent = 0);
  ~ComputersWidget();

private slots:
  void renderData();

private:
  Ui::ComputersWidget* ui;
  User* _user;

};

#endif // COMPUTERSWIDGET_H
