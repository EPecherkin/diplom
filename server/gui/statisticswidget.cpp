#include "statisticswidget.h"
#include "ui_statisticswidget.h"
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "macros.h"
#include "exportwidget.h"
#include "keypress.h"

StatisticsWidget::StatisticsWidget(User* user, QWidget* parent) : QWidget(parent), ui(new Ui::StatisticsWidget), _user(user) {
  ui->setupUi(this);
  ui->fromDTE->setDate(QDateTime::currentDateTime().addDays(-1).date());
  ui->toDTE->setDate(QDateTime::currentDateTime().addDays(1).date());

  connect(ui->viewCB, SIGNAL(currentTextChanged(QString)), this, SLOT(renderData()));
  connect(ui->groupByCB, SIGNAL(currentTextChanged(QString)), this, SLOT(renderData()));
  connect(ui->fromDTE, SIGNAL(editingFinished()), this, SLOT(renderData()));
  connect(ui->toDTE, SIGNAL(editingFinished()), this, SLOT(renderData()));

  renderData();
}

StatisticsWidget::~StatisticsWidget() {
  delete ui;
}

void StatisticsWidget::renderData() {
  FUNCTION

  QString view = ui->viewCB->currentText();
  QString groupBy = ui->groupByCB->currentText();
  QDateTime fromDT = ui->fromDTE->dateTime();
  QDateTime toDT = ui->toDTE->dateTime();

  QDjangoQuerySet<KeyPress> kpqs = QDjangoQuerySet<KeyPress>().filter(QDjangoWhere("start", QDjangoWhere::GreaterOrEquals, fromDT)
                                                                      && QDjangoWhere("start", QDjangoWhere::LessOrEquals, toDT));
  if(view == "All") {
    ui->groupByCB->setVisible(false);
    ui->statisticsTW->setColumnCount(5);
    QStringList headers;
    headers << "Computer" << "Application" << "Start" << "Duration" << "Keys";
    ui->statisticsTW->setHorizontalHeaderLabels(headers);
    ui->statisticsTW->setRowCount(kpqs.size());
    for(qint32 i = 0; i < kpqs.size(); ++i) {
      KeyPress* keyPress = kpqs.at(i);
      Computer* computer = QDjangoQuerySet<Computer>().get(QDjangoWhere("id", QDjangoWhere::Equals, keyPress->computer_id()));
      QTableWidgetItem* item0 = new QTableWidgetItem(computer->ip());
      QTableWidgetItem* item1 = new QTableWidgetItem(keyPress->application());
      QTableWidgetItem* item2 = new QTableWidgetItem(keyPress->start().toString());
      QTableWidgetItem* item3 = new QTableWidgetItem(QString::number(keyPress->duration()));
      QTableWidgetItem* item4 = new QTableWidgetItem(keyPress->keys().join(" "));

      ui->statisticsTW->setItem(i, 0, item0);
      ui->statisticsTW->setItem(i, 1, item1);
      ui->statisticsTW->setItem(i, 2, item2);
      ui->statisticsTW->setItem(i, 3, item3);
      ui->statisticsTW->setItem(i, 4, item4);
    }
  } else {
    ui->groupByCB->setVisible(true);
    ui->statisticsTW->setColumnCount(2);
    QStringList headers;
    headers << groupBy << "Total duration";
    ui->statisticsTW->setHorizontalHeaderLabels(headers);
    QMap<QString, qint32> groups;
    for(qint32 i = 0; i < kpqs.size(); ++i) {
      KeyPress* keyPress = kpqs.at(i);
      if(groupBy == "Computer") {
        Computer* computer = QDjangoQuerySet<Computer>().get(QDjangoWhere("id", QDjangoWhere::Equals, keyPress->computer_id()));
        groups[computer->ip()] += keyPress->duration();
      } else if(groupBy == "Application") {
        groups[keyPress->application()] += keyPress->duration();
      }
    }

    QList<QString> keys = groups.keys();
    ui->statisticsTW->setRowCount(keys.size());
    for(qint32 i = 0; i < keys.size(); ++i) {
      QString key = keys.at(i);
      QTableWidgetItem* item0 = new QTableWidgetItem(key);
      QTableWidgetItem* item1 = new QTableWidgetItem(QString::number(groups.value(key)));

      ui->statisticsTW->setItem(i, 0, item0);
      ui->statisticsTW->setItem(i, 1, item1);
    }
  }
}
