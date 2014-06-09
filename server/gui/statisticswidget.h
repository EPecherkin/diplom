#ifndef STATISTICSWIDGET_H
#define STATISTICSWIDGET_H

#include <QWidget>
#include "user.h"

namespace Ui {
class StatisticsWidget;
}

class StatisticsWidget : public QWidget {
  Q_OBJECT

public:
  explicit StatisticsWidget(User* user, QWidget* parent = 0);
  ~StatisticsWidget();

private slots:
  void renderData();

  void on_exportPB_clicked();

private:
  Ui::StatisticsWidget* ui;
  User* _user;

};

#endif // STATISTICSWIDGET_H
