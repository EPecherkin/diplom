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
  void on_viewCB_currentTextChanged(const QString&);
  void on_groupByCB_currentTextChanged(const QString&);
  void on_exportPB_clicked();

private:
  Ui::StatisticsWidget* ui;
  User* _user;

  void renderData();
};

#endif // STATISTICSWIDGET_H
