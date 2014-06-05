#ifndef EXPORTWIDGET_H
#define EXPORTWIDGET_H

#include <QWidget>

namespace Ui {
class ExportWidget;
}

class ExportWidget : public QWidget {
  Q_OBJECT

public:
  explicit ExportWidget(QWidget* parent = 0);
  ~ExportWidget();

private slots:
  void on_exportPB_clicked();

private:
  Ui::ExportWidget* ui;

};

#endif // EXPORTWIDGET_H
