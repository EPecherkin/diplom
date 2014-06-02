#ifndef COMPUTERSWIDGET_H
#define COMPUTERSWIDGET_H

#include <QWidget>

namespace Ui {
class ComputersWidget;
}

class ComputersWidget : public QWidget {
  Q_OBJECT

public:
  explicit ComputersWidget(QWidget* parent = 0);
  ~ComputersWidget();

private:
  Ui::ComputersWidget* ui;

};

#endif // COMPUTERSWIDGET_H
