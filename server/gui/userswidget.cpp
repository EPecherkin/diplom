#include "userswidget.h"
#include "ui_userswidget.h"
#include "macros.h"
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "usereditdialog.h"

UsersWidget::UsersWidget(Group* group, QWidget* parent) : QWidget(parent), ui(new Ui::UsersWidget), _group(group) {
  ui->setupUi(this);

  renderData();
}

UsersWidget::~UsersWidget() {
  delete ui;
}

void UsersWidget::on_usersTW_doubleClicked(const QModelIndex& index) {
  FUNCTION
  UserEditDialog* ued = new UserEditDialog();
  ued->show();
}

void UsersWidget::on_addPB_clicked() {
  FUNCTION
  UserEditDialog* ued = new UserEditDialog;
  ued->show();
}

void UsersWidget::renderData() {
  FUNCTION
  QDjangoQuerySet<User> uqs;
  if(_group != 0) {
    uqs = QDjangoQuerySet<User>().filter(QDjangoWhere("group_id", QDjangoWhere::Equals, _group->pk()));
  } else {
    uqs = QDjangoQuerySet<User>().all();
  }

  ui->usersTW->setRowCount(uqs.size());

  for(qint32 i = 0; i < uqs.size(); ++i) {
    User* user = uqs.at(i);

  QTableWidgetItem* item0 = new QTableWidgetItem(user->login());
  QString fullName = QString().append(user->lastName()).append(" ").append(user->firstName()).append(" ").append(user->middleName());
  QTableWidgetItem* item1 = new QTableWidgetItem(fullName);
  QTableWidgetItem* item2 = new QTableWidgetItem(user->group()->name());

  ui->usersTW->setItem(i, 0, item0);
  ui->usersTW->setItem(i, 1, item1);
  ui->usersTW->setItem(i, 2, item2);
}
