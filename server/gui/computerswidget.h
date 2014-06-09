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
  explicit ComputersWidget(User* user = 0, QWidget* parent = 0);
  ~ComputersWidget();

private:
  Ui::ComputersWidget* ui;
  User* _user;

  void renderData();

};

#endif // COMPUTERSWIDGET_H
