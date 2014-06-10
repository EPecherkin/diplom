#include "logswidget.h"
#include "ui_logswidget.h"
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "macros.h"
#include "log.h"

LogsWidget::LogsWidget(QWidget* parent) : QWidget(parent), ui(new Ui::LogsWidget) {
  ui->setupUi(this);

  renderData();
}

LogsWidget::~LogsWidget() {
  delete ui;
}

void LogsWidget::renderData() {
  FUNCTION
  QDjangoQuerySet<Log> lqs = QDjangoQuerySet<Log>().all();;

  ui->logsTW->setRowCount(lqs.size());

  for(qint32 i = 0; i < lqs.size(); ++i) {
    Log* log = lqs.at(i);

    QTableWidgetItem* item0 = new QTableWidgetItem(log->table());
    QTableWidgetItem* item1 = new QTableWidgetItem(log->action());
    QTableWidgetItem* item2 = new QTableWidgetItem(log->changes());

    ui->logsTW->setItem(i, 0, item0);
    ui->logsTW->setItem(i, 1, item1);
    ui->logsTW->setItem(i, 2, item2);
  }
}
