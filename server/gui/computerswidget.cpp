#include "computerswidget.h"
#include "ui_computerswidget.h"
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "macros.h"
#include "computer.h"

ComputersWidget::ComputersWidget(User* user, QWidget* parent) : QWidget(parent), ui(new Ui::ComputersWidget), _user(user) {
  ui->setupUi(this);

  renderData();
}

ComputersWidget::~ComputersWidget() {
  delete ui;
}

void ComputersWidget::renderData() {
  FUNCTION
  QDjangoQuerySet<Computer> cqs = QDjangoQuerySet<Computer>().filter(QDjangoWhere("user_id", QDjangoWhere::Equals, _user->pk()));

  ui->computersTW->setRowCount(cqs.size());

  for(qint32 i = 0; i < cqs.size(); ++i) {
    Computer* computer = cqs.at(i);

    QTableWidgetItem* item0 = new QTableWidgetItem(computer->ip());
    QTableWidgetItem* item1 = new QTableWidgetItem(computer->lastActivity().toString());

    ui->computersTW->setItem(i, 0, item0);
    ui->computersTW->setItem(i, 1, item1);
  }
}
