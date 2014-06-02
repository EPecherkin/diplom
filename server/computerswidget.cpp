#include "computerswidget.h"
#include "ui_computerswidget.h"

ComputersWidget::ComputersWidget(QWidget* parent) : QWidget(parent), ui(new Ui::ComputersWidget) {
  ui->setupUi(this);
}

ComputersWidget::~ComputersWidget() {
  delete ui;
}
