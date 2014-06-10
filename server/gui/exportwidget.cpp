#include "exportwidget.h"
#include "ui_exportwidget.h"
#include <QFileDialog>
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "macros.h"
#include "exporter.h"

ExportWidget::ExportWidget(User* user, QWidget* parent) : QWidget(parent), ui(new Ui::ExportWidget), _user(user) {
  ui->setupUi(this);
  ui->fromDTE->setDate(QDateTime::currentDateTime().addDays(-1).date());
  ui->toDTE->setDate(QDateTime::currentDateTime().addDays(1).date());
}

ExportWidget::~ExportWidget() {
  delete ui;
}

void ExportWidget::on_exportPB_clicked() {
  FUNCTION

  QDateTime fromDT = ui->fromDTE->dateTime();
  QDateTime toDT = ui->toDTE->dateTime();
  QString format = ui->formatCB->currentText();

  QString filter = QString("%1 (.*%2)").arg(format, format.toLower());
  QString filename = QFileDialog::getSaveFileName(this, "Save file", "", filter);

  QFile file(filename);
  file.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream out(&file);

  QDjangoQuerySet<KeyPress> kpqs = QDjangoQuerySet<KeyPress>().filter(QDjangoWhere("user_id", QDjangoWhere::Equals, _user->pk())
                                                                      && QDjangoWhere("start", QDjangoWhere::GreaterOrEquals, fromDT)
                                                                      && QDjangoWhere("start", QDjangoWhere::LessOrEquals, toDT));

  QList<KeyPress*> keyPresses;
  for(qint32 i = 0; i < kpqs.size(); ++i) {
    keyPresses.push_back(kpqs.at(i));
  }
  if(format == "CSV") {
    Exporter::exportToCSV(keyPresses, out);
  } else if(format == "JSON") {
    Exporter::exportToJson(keyPresses, out);
  }
}
