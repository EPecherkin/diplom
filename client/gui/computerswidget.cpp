#include "computerswidget.h"
#include "ui_computerswidget.h"

ComputersWidget::ComputersWidget(User* user, QWidget* parent) : QWidget(parent), ui(new Ui::ComputersWidget), _user(user) {
  ui->setupUi(this);
}

ComputersWidget::~ComputersWidget() {
  delete ui;
}
