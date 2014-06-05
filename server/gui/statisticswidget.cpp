#include "statisticswidget.h"
#include "ui_statisticswidget.h"
#include "exportwidget.h"

StatisticsWidget::StatisticsWidget(QWidget* parent) : QWidget(parent), ui(new Ui::StatisticsWidget) {
  ui->setupUi(this);
  ui->groupByCB->setVisible(false);
}

StatisticsWidget::~StatisticsWidget() {
  delete ui;
}

void StatisticsWidget::on_viewCB_currentTextChanged(const QString& text) {
  if(text == "All") {
    ui->groupByCB->setVisible(false);
  } else {
      ui->groupByCB->setVisible(true);
  }
}

void StatisticsWidget::on_groupByCB_currentTextChanged(const QString& text) {

}

void StatisticsWidget::on_exportPB_clicked() {
  ExportWidget* ew = new ExportWidget;
  ew->show();
}
