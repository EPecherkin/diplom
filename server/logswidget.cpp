#include "logswidget.h"
#include "ui_logswidget.h"

LogsWidget::LogsWidget(QWidget* parent) : QWidget(parent), ui(new Ui::LogsWidget) {
  ui->setupUi(this);
}

LogsWidget::~LogsWidget() {
  delete ui;
}
