#include "groupswidget.h"
#include "ui_groupswidget.h"
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "user.h"
#include "groupeditdialog.h"
#include "macros.h"

GroupsWidget::GroupsWidget(QWidget* parent) : QWidget(parent), ui(new Ui::GroupsWidget), _groups(QList<Group*>()) {
  ui->setupUi(this);

  renderData();
}

GroupsWidget::~GroupsWidget() {
  delete ui;
}

void GroupsWidget::on_groupsTW_doubleClicked(const QModelIndex& index) {
  FUNCTION
  Group* group = _groups.at(index.row());
  Normal* normal = QDjangoQuerySet<Normal>().get(QDjangoWhere("group_id", QDjangoWhere::Equals, 1));
  GroupEditDialog* ged = new GroupEditDialog(group, normal);
  int result = ged->exec();
  if(result == QDialog::Accepted)
    group->save();
  renderData();
}

void GroupsWidget::on_addPB_clicked() {
  FUNCTION
  Group* group = new Group;
  Normal* normal = new Normal;
  normal->group(group);

  GroupEditDialog* ged = new GroupEditDialog(group, normal);
  ged->exec();
  renderData();
}

void GroupsWidget::renderData() {
  QDjangoQuerySet<Group> gqs = QDjangoQuerySet<Group>().all();
  ui->groupsTW->setRowCount(gqs.size());
  for(qint32 i = 0; i < gqs.size(); ++i) {
    Group* group = gqs.at(i);
    _groups.append(group);

    QTableWidgetItem* item0 = new QTableWidgetItem(group->name());
    qint32 userCount = QDjangoQuerySet<User>().filter(QDjangoWhere("group_id", QDjangoWhere::Equals, group->pk())).size();
    QTableWidgetItem* item1 = new QTableWidgetItem(QString::number(userCount));

    ui->groupsTW->setItem(i, 0, item0);
    ui->groupsTW->setItem(i, 1, item1);
  }
}
