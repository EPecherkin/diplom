#ifndef STATISTICSWIDGET_H
#define STATISTICSWIDGET_H

#include <QWidget>

namespace Ui {
class StatisticsWidget;
}

class StatisticsWidget : public QWidget {
  Q_OBJECT

public:
  explicit StatisticsWidget(QWidget* parent = 0);
  ~StatisticsWidget();

private:
  Ui::StatisticsWidget* ui;

};

#endif // STATISTICSWIDGET_H
