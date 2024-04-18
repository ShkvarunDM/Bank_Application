#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>
#include <QRegularExpression>

Registration::Registration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Registration)
{
    ui->setupUi(this);

    query = new QSqlQuery();
    query->prepare("INSERT INTO client (lastname, firstname,datebirth,series,number,card,email,phone,password1)"
                   "VALUES (:lastname, :firstname, :datebirth,:series,:number,:card,:email,:phone,:password1);");
    clk = 1;
    connect(ui->pushButton_4,SIGNAL(clicked()),this, SLOT (decrease()));
    connect(this,SIGNAL(clkChanged(int)),this, SLOT (state()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this, SLOT (read_info()));
}

Registration::~Registration()
{
    delete ui;
}

void Registration::increase(){
    clk++;
    emit clkChanged(clk);
}

void Registration::decrease(){
    clk--;
    emit clkChanged(clk);
}


void Registration::state()
{
    if (clk==1) state_1();
    if (clk==2) state_2();
    if (clk==3) state_3();
}

void Registration::clear_data(){
    ui->lineEdit_3->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_13->clear();
}

void Registration::read_info(){
    if (clk==3){
        read_info_1(":email",":phone",":password1");
        query->exec();
        this->close();
        emit first_window();
    }

    if (clk==2) {
        QRegularExpression r_card("^[0-9]{4}\\s[0-9]{4}\\s[0-9]{4}\\s[0-9]{4}$");
        QRegularExpressionMatch match = r_card.match(ui->lineEdit_13->text());
        if (!match.hasMatch()) {
            QMessageBox::warning(this,"Error", "Incorrect number card");
        }
        else{
            read_info_1(":series",":number",":card");
        }
    }

    if (clk==1) {
        QRegularExpression re("^(\\d\\d)-(\\d\\d)-(\\d\\d\\d\\d)$");
        QRegularExpressionMatch match = re.match(ui->lineEdit_13->text());
        if (!match.hasMatch()) {
            QMessageBox::warning(this,"Error", "Incorrect data");
        }
        else{
            read_info_1(":lastname",":firstname",":datebirth");
        }
    }
}

void Registration::read_info_1(QString n1,QString n2,QString n3 ){

    if (ui->lineEdit_3->text()!= "" && ui->lineEdit_9->text()!= "" && ui->lineEdit_13->text()!= "" ){
        query->bindValue(n1,ui->lineEdit_3->text());
        query->bindValue(n2,ui->lineEdit_9->text());
        query->bindValue(n3,ui->lineEdit_13->text());

        increase();
        clear_data();
    }
    else{
        QMessageBox::warning(this,"Error", "Not all fields are filled in");
    }
}

void Registration::state_1(){

    ui->pushButton_4->setEnabled(false);
    ui->lineEdit_5->setStyleSheet("background-color: rgb(77, 77, 77);border-radius:25px;color: rgb(0, 0, 0);border: none;");
    ui->lineEdit_4->setStyleSheet("background-color:#6b6b6b;border:none;");

    ui->lineEdit_14->setText("PERSONAL DETAILS");
    ui->lineEdit_3->setPlaceholderText("First Name..");
    ui->lineEdit_9->setPlaceholderText("Last Name..");
    ui->lineEdit_13->setPlaceholderText("Birth date..");
}
void Registration::state_2(){

    ui->pushButton_4->setEnabled(true);
    ui->pushButton_3->setText("Next");

    ui->lineEdit_4->setStyleSheet("background-color:#ee0979;border:none;");
    ui->lineEdit_5->setStyleSheet("background-color:#ee0979;border-radius:25px;color: white;border: 1px solid white;");
    ui->lineEdit_7->setStyleSheet("background-color: rgb(77, 77, 77);border-radius:25px;color: rgb(0, 0, 0);border: none;");
    ui->lineEdit_6->setStyleSheet("background-color:#6b6b6b;border:none;");

    ui->lineEdit_14->setText("DOCUMENTS");
    ui->lineEdit_3->setPlaceholderText("Series..");
    ui->lineEdit_9->setPlaceholderText("Number..");
    ui->lineEdit_13->setPlaceholderText("0000 0000 0000 0000");
}
void Registration::state_3(){

    ui->lineEdit_6->setStyleSheet("background-color:#ee0979;border:none;");
    ui->lineEdit_7->setStyleSheet("background-color:#ee0979;border-radius:25px;color: white;border: 1px solid white;");

    ui->lineEdit_14->setText("ACCOUNT SETUP");
    ui->lineEdit_3->setPlaceholderText("Email..");
    ui->lineEdit_9->setPlaceholderText("Phone..");
    ui->lineEdit_13->setPlaceholderText("Password..");
    ui->pushButton_3->setText("Save");

}






