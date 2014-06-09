#include "statisticswidget.h"
#include "ui_statisticswidget.h"
#include "macros.h"
#include "exportwidget.h"

StatisticsWidget::StatisticsWidget(User* user, QWidget* parent) : QWidget(parent), ui(new Ui::StatisticsWidget), _user(user) {
  ui->setupUi(this);
  connect(ui->viewCB, SIGNAL(currentTextChanged(QString)), this, SLOT(renderData()));
  connect(ui->groupByCB, SIGNAL(currentTextChanged(QString)), this, SLOT(renderData()));

  renderData();
}

StatisticsWidget::~StatisticsWidget() {
  delete ui;
}

void StatisticsWidget::on_exportPB_clicked() {
  FUNCTION
  ExportWidget* ew = new ExportWidget(_user);
  ew->show();
}

void StatisticsWidget::renderData() {
  FUNCTION
  if(ui->viewCB->currentText() == "All") {
    ui->groupByCB->setVisible(false);
  } else {
    ui->groupByCB->setVisible(true);
  }
}
