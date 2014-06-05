#ifndef LOGSWIDGET_H
#define LOGSWIDGET_H

#include <QWidget>

namespace Ui {
class LogsWidget;
}

class LogsWidget : public QWidget {
  Q_OBJECT

public:
  explicit LogsWidget(QWidget* parent = 0);
  ~LogsWidget();

private:
  Ui::LogsWidget* ui;

};

#endif // LOGSWIDGET_H
