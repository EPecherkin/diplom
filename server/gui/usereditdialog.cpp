#include "usereditdialog.h"
#include "ui_usereditdialog.h"
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "macros.h"
#include "computerswidget.h"
#include "statisticswidget.h"

UserEditDialog::UserEditDialog(User* user, QWidget* parent) : QDialog(parent), ui(new Ui::UserEditDialog), _user(user), _groups(QList<Group*>()) {
  ui->setupUi(this);

  renderData();
}

UserEditDialog::~UserEditDialog() {
  delete ui;
}

void UserEditDialog::on_computersPB_clicked() {
  FUNCTION
  ComputersWidget* cw = new ComputersWidget;
  cw->show();
}

void UserEditDialog::on_statisticsPB_clicked() {
  FUNCTION
  StatisticsWidget* sw = new StatisticsWidget;
  sw->show();
}

void UserEditDialog::done(int r) {
  if(r == Accepted) {
    _user->login(ui->loginLE->text());
    _user->firstName(ui->firstNameLE->text());
    _user->lastName(ui->lastNameLE->text());
    _user->middleName(ui->middleNameLE->text());

    QString password = ui->passwordLE->text();
    if(password.isEmpty())
      _user->password(password);

    _user->group(_groups.at(ui->groupCB->currentIndex()));

    _user->save();
  }

  QDialog::done(r);
}

void UserEditDialog::renderData() {
  ui->computersPB->setVisible(_user->pk().isValid());
  ui->statisticsPB->setVisible(_user->pk().isValid());

  ui->loginLE->setText(_user->login());
  ui->firstNameLE->setText(_user->firstName());
  ui->lastNameLE->setText(_user->lastName());
  ui->middleNameLE->setText(_user->middleName());

  QDjangoQuerySet<Group> gqs = QDjangoQuerySet<Group>().all();
  for(qint32 i = 0; i < gqs.size(); ++i) {
    Group* group = gqs.at(i);
    _groups.append(group);
    ui->groupCB->addItem(group->name());
    Group* userGroup = QDjangoQuerySet<Group>().get(QDjangoWhere("id", QDjangoWhere::Equals, _user->property("group_id")));
    if(userGroup->pk() == group->pk()) {
      ui->groupCB->setCurrentIndex(i);
    }
  }
}
