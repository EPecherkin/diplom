#include "statisticswidget.h"
#include "ui_statisticswidget.h"

StatisticsWidget::StatisticsWidget(QWidget* parent) : QWidget(parent), ui(new Ui::StatisticsWidget) {
  ui->setupUi(this);
}

StatisticsWidget::~StatisticsWidget() {
  delete ui;
}
