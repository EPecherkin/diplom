#include "statisticswidget.h"
#include "ui_statisticswidget.h"
#include "macros.h"
#include "exportwidget.h"

StatisticsWidget::StatisticsWidget(QWidget* parent) : QWidget(parent), ui(new Ui::StatisticsWidget) {
  ui->setupUi(this);
  ui->groupByCB->setVisible(false);
}

StatisticsWidget::~StatisticsWidget() {
  delete ui;
}

void StatisticsWidget::on_viewCB_currentTextChanged(const QString& text) {
  FUNCTION
  if(text == "All") {
    ui->groupByCB->setVisible(false);
  } else {
      ui->groupByCB->setVisible(true);
  }
}

void StatisticsWidget::on_groupByCB_currentTextChanged(const QString& text) {
  FUNCTION
}

void StatisticsWidget::on_exportPB_clicked() {
  FUNCTION
  ExportWidget* ew = new ExportWidget;
  ew->show();
}
