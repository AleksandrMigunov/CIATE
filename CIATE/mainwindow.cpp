/* Copyright (C) 2022 Aleksandr Migunov
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QPushButton>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QInputDialog>
#include <QColor>
#include <QStringList>
#include <QDir>
#include <QSound>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    UpperCase = false;
    LowerCase = true;
    Capitalize = false;

    NewOpened = "";
    FileOpened = "";
    Encoding = "";

    Audio_On = false;
    Info_On = true;
    Text_On = true;
    Clear_On = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

///////////////////////////////
// Chechen & Ingush Keyboard //
///////////////////////////////

void MainWindow::on_pushButton_upper_clicked()
{
    UpperCase = true;
    LowerCase = false;
    Capitalize = false;
}

void MainWindow::on_pushButton_lower_clicked()
{
    LowerCase = true;
    UpperCase = false;
    Capitalize = false;
}

void MainWindow::on_pushButton_capitalize_clicked()
{
    Capitalize = true;
    UpperCase = true;
    LowerCase = false;
}

void MainWindow::on_checkBox_Audio_stateChanged(int arg1)
{
    if (arg1) {
        Audio_On = true;
    } else {
        Audio_On = false;
    }

}

void MainWindow::on_pushButton_a_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString a = "??";
            ui->textEdit->insertPlainText(a);
        }
        else {
            QString A = "??";
            ui->textEdit->insertPlainText(A);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/01a.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info1 = "?? ??: open front unrounded vowel / low front unrounded vowel; pronounced as a in father or as o in hot or as u in bus";
        ui->textEdit_2->insertPlainText(info1);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_ae_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString ae = "????";
            ui->textEdit->insertPlainText(ae);
        }
        else if (Capitalize == true) {
            QString Ae = "????";
            ui->textEdit->insertPlainText(Ae);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString AE = "????";
            ui->textEdit->insertPlainText(AE);
        }
    }

    if (Audio_On) {
        QSound::play("audios/02ae.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info2 = "???? ????: near-open front unrounded vowel / near-low front unrounded vowel; pronounced as a in hat";
        ui->textEdit_2->insertPlainText(info2);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_b_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString b = "??";
            ui->textEdit->insertPlainText(b);
        }
        else {
            QString B = "??";
            ui->textEdit->insertPlainText(B);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/03b.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info3 = "?? ??: voiced bilabial plosive / stop; pronounced as b in bet";
        ui->textEdit_2->insertPlainText(info3);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_v_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString v = "??";
            ui->textEdit->insertPlainText(v);
        }
        else {
            QString V = "??";
            ui->textEdit->insertPlainText(V);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/04v.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info4 = "?? ??: voiced labiodental fricative; pronounced as v in verse; "
                        "after a vowel and sometimes in other positions: voiced labial-velar approximant, pronounced as w in wet";
        ui->textEdit_2->insertPlainText(info4);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_g_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString g = "??";
            ui->textEdit->insertPlainText(g);
        }
        else {
            QString G = "??";
            ui->textEdit->insertPlainText(G);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/05g.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info5 = "?? ??: voiced velar plosive / stop; pronounced as g in got";
        ui->textEdit_2->insertPlainText(info5);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_g1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString g1 = "????";
            ui->textEdit->insertPlainText(g1);
        }
        else {
            QString G1 = "????";
            ui->textEdit->insertPlainText(G1);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/06gh.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info6 = "???? ????: voiced uvular fricative; has no English equivalent, pronounced similarly to French or German uvular r; sounds like fricative g";
        ui->textEdit_2->insertPlainText(info6);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_d_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString d = "??";
            ui->textEdit->insertPlainText(d);
        }
        else {
            QString D = "??";
            ui->textEdit->insertPlainText(D);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/07d.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info7 = "?? ??: voiced dental plosive / stop; pronounced like d in dog";
        ui->textEdit_2->insertPlainText(info7);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_je_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString je = "??";
            ui->textEdit->insertPlainText(je);
        }
        else {
            QString JE = "??";
            ui->textEdit->insertPlainText(JE);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/08je.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info8 = "?? ??: in the beginning of a word or after a vowel: a combination of voiced palatal approximant and "
                        "close-mid front unrounded vowel / high-mid front unrounded vowel; pronounced as ye in yes; after a consonant: "
                        "close-mid front unrounded vowel / high-mid front unrounded vowel, pronounced as e in bet";
        ui->textEdit_2->insertPlainText(info8);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_jo_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString jo = "??";
            ui->textEdit->insertPlainText(jo);
        }
        else {
            QString JO = "??";
            ui->textEdit->insertPlainText(JO);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/09jo.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info9 = "?? ??: in the beginning of a word or after a vowel: a combination of voiced palatal approximant and "
                        "close-mid back rounded vowel / high-mid back rounded vowel; pronounced as yaw in yawn; after a consonant: "
                        "close-mid back rounded vowel / high-mid back rounded vowel; pronounced as a in talk";
        ui->textEdit_2->insertPlainText(info9);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_zh_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString zh = "??";
            ui->textEdit->insertPlainText(zh);
        }
        else {
            QString ZH = "??";
            ui->textEdit->insertPlainText(ZH);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/10zh.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info10 = "?? ??: voiced postalveolar fricative (sibilant), pronounced as s in measure; "
                         "in some words in the end or in the beginning: voiced post-alveolar affricate (sibilant), pronounced as j in just";
        ui->textEdit_2->insertPlainText(info10);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_z_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString z = "??";
            ui->textEdit->insertPlainText(z);
        }
        else {
            QString Z = "??";
            ui->textEdit->insertPlainText(Z);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/11z.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info11 = "?? ??: voiced alveolar fricative (sibilant); prounounced as z in zoo; "
                         "in some words in the end or in the beginning: voiced alveolar affricate (sibilant); pronounced as d and z together (like ds in stands)";
        ui->textEdit_2->insertPlainText(info11);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_i_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString i = "??";
            ui->textEdit->insertPlainText(i);
        }
        else {
            QString I = "??";
            ui->textEdit->insertPlainText(I);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/12i.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info12 = "?? ??: close front unrounded vowel / high front unrounded vowel; pronounced as ee in see or as i in sit";
        ui->textEdit_2->insertPlainText(info12);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_j_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString j = "??";
            ui->textEdit->insertPlainText(j);
        }
        else {
            QString J = "??";
            ui->textEdit->insertPlainText(J);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/13j.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info13 = "?? ??: voiced palatal approximant; pronounced as y in yes";
        ui->textEdit_2->insertPlainText(info13);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_k_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString k = "??";
            ui->textEdit->insertPlainText(k);
        }
        else {
            QString K = "??";
            ui->textEdit->insertPlainText(K);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/14k.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info14 = "?? ??: voiceless velar plosive / stop; pronounced as c in cat";
        ui->textEdit_2->insertPlainText(info14);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_q_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString q = "????";
            ui->textEdit->insertPlainText(q);
        }
        else if (Capitalize == true) {
            QString Q = "????";
            ui->textEdit->insertPlainText(Q);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString Q = "????";
            ui->textEdit->insertPlainText(Q);
        }
    }

    if (Audio_On) {
        QSound::play("audios/15q.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info15 = "???? ????: voiceless uvular plosive / stop; has no English equivalent, sounds like a \"back\" k (q), "
                         "pronounced like Hebrew qof (though not in modern Hebrew pronunciation)";
        ui->textEdit_2->insertPlainText(info15);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_q1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString q1 = "????";
            ui->textEdit->insertPlainText(q1);
        }
        else if (Capitalize == true) {
            QString Q1 = "????";
            ui->textEdit->insertPlainText(Q1);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString Q1 = "????";
            ui->textEdit->insertPlainText(Q1);
        }
    }

    if (Audio_On) {
        QSound::play("audios/16qh.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info16 = "???? ????: voiceless ejective uvular plosive / stop; has no English equivalent, sounds like very sharp q (\"back\" k)";
        ui->textEdit_2->insertPlainText(info16);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_k1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString k1 = "????";
            ui->textEdit->insertPlainText(k1);
        }
        else {
            QString K1 = "????";
            ui->textEdit->insertPlainText(K1);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/17kh.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info17 = "???? ????: voiceless ejective velar plosive / stop; has no English equivalent, sounds like very sharp k";
        ui->textEdit_2->insertPlainText(info17);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_l_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString l = "??";
            ui->textEdit->insertPlainText(l);
        }
        else {
            QString L = "??";
            ui->textEdit->insertPlainText(L);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/18l.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info18 = "?? ??: voiced alveolar lateral approximant; pronounced as l in leg";
        ui->textEdit_2->insertPlainText(info18);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_m_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString m = "??";
            ui->textEdit->insertPlainText(m);
        }
        else {
            QString M = "??";
            ui->textEdit->insertPlainText(M);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/19m.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info19 = "?? ??: voiced bilabial nasal; pronounced as m in mark";
        ui->textEdit_2->insertPlainText(info19);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_n_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString n = "??";
            ui->textEdit->insertPlainText(n);
        }
        else {
            QString N = "??";
            ui->textEdit->insertPlainText(N);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/20n.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info20 = "?? ??: voiced alveolar nasal; pronounced as n in none";
        ui->textEdit_2->insertPlainText(info20);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_o_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString o = "??";
            ui->textEdit->insertPlainText(o);
        }
        else {
            QString O = "??";
            ui->textEdit->insertPlainText(O);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/21o.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info21 = "?? ??: close-mid back rounded vowel / high-mid back rounded vowel; pronounced as a in talk";
        ui->textEdit_2->insertPlainText(info21);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_oe_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString oe = "????";
            ui->textEdit->insertPlainText(oe);
        }
        else if (Capitalize == true) {
            QString Oe = "????";
            ui->textEdit->insertPlainText(Oe);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString OE = "????";
            ui->textEdit->insertPlainText(OE);
        }
    }

    if (Audio_On) {
        QSound::play("audios/22oe.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info22 = "???? ???? (only in Chechen alphabet): close-mid central rounded vowel / high-mid central rounded vowel; "
                         "has no English equivalent, sounds a little bit similar to ir in birth, pronounced like ?? in German";
        ui->textEdit_2->insertPlainText(info22);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_p_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString p = "??";
            ui->textEdit->insertPlainText(p);
        }
        else {
            QString P = "??";
            ui->textEdit->insertPlainText(P);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/23p.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info23 = "?? ??: voiceless bilabial plosive or stop; pronounced as p in pen";
        ui->textEdit_2->insertPlainText(info23);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_p1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString p1 = "????";
            ui->textEdit->insertPlainText(p1);
        }
        else {
            QString P1 = "????";
            ui->textEdit->insertPlainText(P1);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/24ph.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info24 = "???? ????: voiceless ejective bilabial plosive or stop; has no English equivalent, sounds like very sharp p";
        ui->textEdit_2->insertPlainText(info24);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_r_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString r = "??";
            ui->textEdit->insertPlainText(r);
        }
        else {
            QString R = "??";
            ui->textEdit->insertPlainText(R);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/25r.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info25 = "?? ??: voiced alveolar trill; pronounced somewhat similarly to English r in roar";
        ui->textEdit_2->insertPlainText(info25);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_s_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString s = "??";
            ui->textEdit->insertPlainText(s);
        }
        else {
            QString S = "??";
            ui->textEdit->insertPlainText(S);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/26s.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info26 = "?? ??: voiceless alveolar fricative (siblilant); pronounced as s in sauce";
        ui->textEdit_2->insertPlainText(info26);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_t_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString t = "??";
            ui->textEdit->insertPlainText(t);
        }
        else {
            QString T = "??";
            ui->textEdit->insertPlainText(T);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/27t.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info27 = "?? ??: voiceless dental plosive / stop; pronounced like t in ten";
        ui->textEdit_2->insertPlainText(info27);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_t1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString t1 = "????";
            ui->textEdit->insertPlainText(t1);
        }
        else {
            QString T1 = "????";
            ui->textEdit->insertPlainText(T1);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/28th.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info28 = "???? ????: voiceless ejective dental plosive / stop; has no English equivalent, sounds like very sharp t";
        ui->textEdit_2->insertPlainText(info28);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_u_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString u = "??";
            ui->textEdit->insertPlainText(u);
        }
        else {
            QString U = "??";
            ui->textEdit->insertPlainText(U);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/29u.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info29 = "?? ??: close back rounded vowel / high back rounded vowel; pronounced as oo in book";
        ui->textEdit_2->insertPlainText(info29);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_ue_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString ue = "????";
            ui->textEdit->insertPlainText(ue);
        }
        else if (Capitalize == true) {
            QString Ue = "????";
            ui->textEdit->insertPlainText(Ue);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString UE = "????";
            ui->textEdit->insertPlainText(UE);
        }
    }

    if (Audio_On) {
        QSound::play("audios/30ue.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info30 = "???? ???? (only in Chechen alphabet): close front rounded vowel, or high front rounded vowel; "
                         "has no English equivalent, pronounced as ?? in German and sounds somewhat like soft oo";
        ui->textEdit_2->insertPlainText(info30);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_f_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString f = "??";
            ui->textEdit->insertPlainText(f);
        }
        else {
            QString F = "??";
            ui->textEdit->insertPlainText(F);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/31f.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info31 = "?? ??: voiceless labiodental fricative; pronounced as f in fall";
        ui->textEdit_2->insertPlainText(info31);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_x_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString x = "??";
            ui->textEdit->insertPlainText(x);
        }
        else {
            QString X = "??";
            ui->textEdit->insertPlainText(X);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/32kh.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info32 = "?? ??: voiceless uvular fricative; has no English equivalent, pronounced like ch in Scottish and German (in some words); sounds like fricative k";
        ui->textEdit_2->insertPlainText(info32);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_x1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString x1 = "????";
            ui->textEdit->insertPlainText(x1);
        }
        else if (Capitalize == true) {
            QString X1 = "????";
            ui->textEdit->insertPlainText(X1);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString X1 = "????";
            ui->textEdit->insertPlainText(X1);
        }
    }

    if (Audio_On) {
        QSound::play("audios/33qh.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info33 = "???? ????: voiceless pharyngeal fricative; "
                         "has no English equivalent, pronounced like het in Hebrew (but not in modern pronunciation); sounds somewhat like previous sound but softened";
        ui->textEdit_2->insertPlainText(info33);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_h_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString h = "????";
            ui->textEdit->insertPlainText(h);
        }
        else {
            QString H = "????";
            ui->textEdit->insertPlainText(H);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/34h.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info34 = "???? ????: voiceless glottal fricative; pronounced like h in how";
        ui->textEdit_2->insertPlainText(info34);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_c_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString c = "??";
            ui->textEdit->insertPlainText(c);
        }
        else {
            QString C = "??";
            ui->textEdit->insertPlainText(C);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/35ts.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info35 = "?? ??: voiceless alveolar affricate (sibilant); pronounced like t and s together (like ts in its)";
        ui->textEdit_2->insertPlainText(info35);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_c1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString c1 = "????";
            ui->textEdit->insertPlainText(c1);
        }
        else {
            QString C1 = "????";
            ui->textEdit->insertPlainText(C1);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/36tsh.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info36 = "???? ????: voiceless ejective alveolar affricate (sibilant); has no English equivalent, sounds like very sharp t and s together";
        ui->textEdit_2->insertPlainText(info36);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_ch_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString ch = "??";
            ui->textEdit->insertPlainText(ch);
        }
        else {
            QString CH = "??";
            ui->textEdit->insertPlainText(CH);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/37ch.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info37 = "?? ??: voiceless palato-alveolar sibilant affricate; pronounced like ch in chin";
        ui->textEdit_2->insertPlainText(info37);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_ch1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString ch1 = "????";
            ui->textEdit->insertPlainText(ch1);
        }
        else {
            QString CH1 = "????";
            ui->textEdit->insertPlainText(CH1);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/38chh.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info38 = "???? ????: voiceless ejective palato-alveolar sibilant affricate; pronounced like very sharp ch";
        ui->textEdit_2->insertPlainText(info38);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_sh_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString sh = "??";
            ui->textEdit->insertPlainText(sh);
        }
        else {
            QString SH = "??";
            ui->textEdit->insertPlainText(SH);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/39sh.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info39 = "?? ??: voiceless postalveolar fricative (sibilant); pronounced as sh in she";
        ui->textEdit_2->insertPlainText(info39);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_shch_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString shch = "??";
            ui->textEdit->insertPlainText(shch);
        }
        else {
            QString SHCH = "??";
            ui->textEdit->insertPlainText(SHCH);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/40shh.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info40 = "?? ??: voiceless alveolo-palatal sibilant fricative; has no English equivalent, sounds like very soft sh";
        ui->textEdit_2->insertPlainText(info40);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_hard_sign_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString hard_sign = "??";
            ui->textEdit->insertPlainText(hard_sign);
        }
        else {
            QString Hard_sign = "??";
            ui->textEdit->insertPlainText(Hard_sign);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/41hard_sign.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info41 = "?? ??: pronounced as glottal plosive / stop between vowels and in the end of a word, in other positions usually is not pronounced";
        ui->textEdit_2->insertPlainText(info41);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_y_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString y = "??";
            ui->textEdit->insertPlainText(y);
        }
        else {
            QString Y = "??";
            ui->textEdit->insertPlainText(Y);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/42y.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info42 = "?? ??: close central unrounded vowel / high central unrounded vowel; has no English equivalent, sounds somewhat similar to i in sit";
        ui->textEdit_2->insertPlainText(info42);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_soft_sign_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString soft_sign = "??";
            ui->textEdit->insertPlainText(soft_sign);
        }
        else {
            QString Soft_sign = "??";
            ui->textEdit->insertPlainText(Soft_sign);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/43soft_sign.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info43 = "?? ??: this letter is not pronounced";
        ui->textEdit_2->insertPlainText(info43);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_e_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString e = "??";
            ui->textEdit->insertPlainText(e);
        }
        else {
            QString E = "??";
            ui->textEdit->insertPlainText(E);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/44e.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info44 = "?? ??: close-mid front unrounded vowel / high-mid front unrounded vowel; pronounced as e in bet";
        ui->textEdit_2->insertPlainText(info44);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_ju_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString ju = "??";
            ui->textEdit->insertPlainText(ju);
        }
        else {
            QString JU = "??";
            ui->textEdit->insertPlainText(JU);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/45ju.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info45 = "?? ??: in the beginning of a word or after a vowel: a combination of voiced palatal approximant and "
                         "close back rounded vowel / high back rounded vowel, pronounced like you (the whole word); "
                         "after a consonant: close back rounded vowel / high back rounded vowel; pronounced like oo in book";
        ui->textEdit_2->insertPlainText(info45);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_jue_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString jue = "????";
            ui->textEdit->insertPlainText(jue);
        }
        else if (Capitalize == true) {
            QString Jue = "????";
            ui->textEdit->insertPlainText(Jue);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString JUE = "????";
            ui->textEdit->insertPlainText(JUE);
        }
    }

    if (Audio_On) {
        QSound::play("audios/46jue.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info46 = "???? ???? (only in Chechen alphabet): in the beginning of a word or after a vowel: a combination of voiced palatal approximant and "
                         "near-open front unrounded vowel / near-low front unrounded vowel; "
                         "this combination has no equivalent in English, is pronounced as j?? in German, sounds somewhat like soft you";
        ui->textEdit_2->insertPlainText(info46);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_ja_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString ja = "??";
            ui->textEdit->insertPlainText(ja);
        }
        else {
            QString JA = "??";
            ui->textEdit->insertPlainText(JA);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/47ja.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info47 = "?? ??: in the beginning of a word or after a vowel: a combination of voiced palatal approximant and "
                         "open front unrounded vowel / low front unrounded vowel; pronounced like ya in yacht; "
                         "after a consonant: open front unrounded vowel / low front unrounded vowel; pronounced like a in father";
        ui->textEdit_2->insertPlainText(info47);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_jae_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString jae = "????";
            ui->textEdit->insertPlainText(jae);
        }
        else if (Capitalize == true) {
            QString Jae = "????";
            ui->textEdit->insertPlainText(Jae);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString JAE = "????";
            ui->textEdit->insertPlainText(JAE);
        }
    }

    if (Audio_On) {
        QSound::play("audios/48jae.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info48 = "???? ????: in the beginning of a word or after a vowel: a combination of voiced palatal approximant and "
                         "open front unrounded vowel / low front unrounded; pronounced as ya in yap";
        ui->textEdit_2->insertPlainText(info48);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_stick_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString stick = "??";
            ui->textEdit->insertPlainText(stick);
        }
        else {
            QString Stick = "??";
            ui->textEdit->insertPlainText(Stick);
            if (Capitalize == true) {
                Capitalize = false;
                UpperCase = false;
                LowerCase = true;
            }
        }
    }

    if (Audio_On) {
        QSound::play("audios/49ain.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info49 = "?? ??: in the beginning of a word, pronounced as voicless pharyngeal plosive / stop; "
                         "after voiced consonants pronounced as voiced pharyngeal fricative; "
                         "both consonants have no English equivalents, but the second one is similar to Hebrew ayin (though not in modern pronunciation)";
        ui->textEdit_2->insertPlainText(info49);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_space_clicked()
{
    ui->textEdit->insertPlainText(" ");
}

/////////////////////////////////
// Additional Ingush letters ////
/////////////////////////////////
void MainWindow::on_pushButton_b1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString b1 = "????";
            ui->textEdit->insertPlainText(b1);
        }
        else if (Capitalize == true) {
            QString B1 = "????";
            ui->textEdit->insertPlainText(B1);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString B1 = "????";
            ui->textEdit->insertPlainText(B1);
        }
    }

    if (Audio_On) {
        QSound::play("audios/50b1.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info50 = "???? ???? (not in alphabet): voiced bilabial plosive / stop (pronounced as English b) and "
                         "voiced pharyngeal fricative (pronounced as Hebrew ayin)";
        ui->textEdit_2->insertPlainText(info50);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_v1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString v1 = "????";
            ui->textEdit->insertPlainText(v1);
        }
        else if (Capitalize == true) {
            QString V1 = "????";
            ui->textEdit->insertPlainText(V1);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString V1 = "????";
            ui->textEdit->insertPlainText(V1);
        }
    }

    if (Audio_On) {
        QSound::play("audios/51v1.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info51 = "???? ???? (not in alphabet): voiced labiodental fricative (pronounced as English v) and "
                         "voiced pharyngeal fricative (pronounced as Hebrew ayin)";
        ui->textEdit_2->insertPlainText(info51);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}


void MainWindow::on_pushButton_d1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString d1 = "????";
            ui->textEdit->insertPlainText(d1);
        }
        else if (Capitalize == true) {
            QString D1 = "????";
            ui->textEdit->insertPlainText(D1);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString D1 = "????";
            ui->textEdit->insertPlainText(D1);
        }
    }

    if (Audio_On) {
        QSound::play("audios/52d1.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info52 = "???? ???? (not in alphabet): voiced dental plosive / stop (pronounced as English d) and "
                         "voiced pharyngeal fricative (pronounced as Hebrew ayin)";
        ui->textEdit_2->insertPlainText(info52);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_zh1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString zh1 = "????";
            ui->textEdit->insertPlainText(zh1);
        }
        else if (Capitalize == true) {
            QString Zh1 = "????";
            ui->textEdit->insertPlainText(Zh1);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString ZH1 = "????";
            ui->textEdit->insertPlainText(ZH1);
        }
    }

    if (Audio_On) {
        QSound::play("audios/53zh1.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info53 = "???? ???? (not in alphabet): voiced postalveolar fricative (sibilant), pronounced as s in measure or "
                         "voiced post-alveolar affricate (sibilant), pronounced as j in just and "
                         "voiced pharyngeal fricative (pronounced as Hebrew ayin)";
        ui->textEdit_2->insertPlainText(info53);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_z1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString z1 = "????";
            ui->textEdit->insertPlainText(z1);
        }
        else if (Capitalize == true) {
            QString Z1 = "????";
            ui->textEdit->insertPlainText(Z1);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString Z1 = "????";
            ui->textEdit->insertPlainText(Z1);
        }
    }

    if (Audio_On) {
        QSound::play("audios/54z1.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info54 = "???? ???? (not in alphabet): voiced alveolar fricative (sibilant) prounounced as z or voiced alveolar affricate (sibilant) pronounced as d and z together and "
                         "voiced pharyngeal fricative (pronounced as Hebrew ayin)";
        ui->textEdit_2->insertPlainText(info54);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_j1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString j1 = "????";
            ui->textEdit->insertPlainText(j1);
        }
        else if (Capitalize == true) {
            QString J1 = "????";
            ui->textEdit->insertPlainText(J1);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString J1 = "????";
            ui->textEdit->insertPlainText(J1);
        }
    }

    if (Audio_On) {
        QSound::play("audios/55j1.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info55 = "???? ???? (not in alphabet): voiced palatal approximant (pronounced as y) and "
                         "voiced pharyngeal fricative (pronounced as Hebrew ayin)";
        ui->textEdit_2->insertPlainText(info55);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_m1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString m1 = "????";
            ui->textEdit->insertPlainText(m1);
        }
        else if (Capitalize == true) {
            QString M1 = "????";
            ui->textEdit->insertPlainText(M1);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString M1 = "????";
            ui->textEdit->insertPlainText(M1);
        }
    }

    if (Audio_On) {
        QSound::play("audios/56m1.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info56 = "???? ???? (not in alphabet): voiced bilabial nasal (pronounced as m) and "
                         "voiced pharyngeal fricative (pronounced as Hebrew ayin)";
        ui->textEdit_2->insertPlainText(info56);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}

void MainWindow::on_pushButton_n1_clicked()
{
    if (Text_On) {
        if (UpperCase == false) {
            QString n1 = "????";
            ui->textEdit->insertPlainText(n1);
        }
        else if (Capitalize == true) {
            QString N1 = "????";
            ui->textEdit->insertPlainText(N1);
            Capitalize = false;
            UpperCase = false;
            LowerCase = true;
        }
        else {
            QString N1 = "????";
            ui->textEdit->insertPlainText(N1);
        }
    }

    if (Audio_On) {
        QSound::play("audios/57n1.wav");
    }

    if (Info_On) {
        if (Clear_On) {
            ui->textEdit_2->clear();
        }

        QString info57 = "???? ???? (not in alphabet): voiced alveolar nasal (pronounced as n) and "
                         "voiced pharyngeal fricative (pronounced as Hebrew ayin)";
        ui->textEdit_2->insertPlainText(info57);
        ui->textEdit_2->insertPlainText("\n\n");
    }
}


/////////////////////////
// Menu "File" options //
/////////////////////////

// New file / clearing the text window
void MainWindow::on_actionNew_triggered()
{
    ui->textEdit->clear();
}

// Opening a file in UTF-8 encoding
void MainWindow::on_actionOpen_triggered()
{
    NewOpened = "";
    QString file = QFileDialog::getOpenFileName(this, "Open file", "", "Text Files(*.txt)");
    if (!file.isEmpty())
    {
        QFile File(file);
        if(File.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&File);
            in.setCodec("UTF-8");
            Encoding = "UTF-8";

            QString text = in.readAll();
            File.close();

            ui->textEdit->setAcceptRichText(false);
            ui->textEdit->setText(text);
        }
        else {
            QMessageBox::information(this, "Error", "Unable to open file.", QMessageBox::Ok);
        }
    }
    FileOpened = file;
}

// Choosing another encoding (if needed)
void MainWindow::on_actionEncoding_triggered()
{
    QStringList items;
    items << "UTF-8" << "Unicode (UTF-16)" << "UTF-16BE" << "UTF-16LE" <<
             "Windows-1251 (Cyrillic)" << "KOI8-R (Cyrillic)" <<
             "CP866 / IBM866 (Cyrillic)" << "ISO 8859-5 (Cyrillic)";

    bool ok;
    QString item = QInputDialog::getItem(this, "Changing encoding", "Choose encoding:", items, 0, false, &ok);

    QString EncodingDocument;
    if (ok && !item.isEmpty()) {

        if (item == "UTF-8") EncodingDocument = "UTF-8";
        else if (item == "Unicode (UTF-16)") EncodingDocument = "Unicode";
        else if (item == "UFT-16BE") EncodingDocument = "UTF-16BE";
        else if (item == "UTF-16LE") EncodingDocument = "UTF-16LE";
        else if (item == tr("Windows-1251 (Cyrillic)")) EncodingDocument = "Windows-1251";
        else if (item == tr("KOI8-R (Cyrillic)")) EncodingDocument = "KOI8-R";
        else if (item == tr("CP866 / IBM866 (Cyrillic)")) EncodingDocument = "IBM866";
        else if (item == tr("ISO 8859-5 (Cyrillic)")) EncodingDocument = "ISO 8859-5";
        else return;
    }

    QString file;
    if (!FileOpened.isEmpty())
    {
        file = FileOpened;
    }
    else if (!NewOpened.isEmpty())
    {
        file = "temp.txt";

        if(!file.isEmpty())
        {
            QDir direct;
            QString dir = direct.filePath(file);
            QString FileName = dir;
            QFile File(FileName);

            if(File.open(QFile::WriteOnly | QFile::Text))
            {
                QTextStream out(&File);
                out.setCodec("UTF-8");

                out << ui->textEdit->toPlainText();

                File.flush();
                File.close();
            }
        }
    }
    else
    {
        file = QFileDialog::getOpenFileName(this, "Open file", "", "All Files(*.*)");
    }
    if (!file.isEmpty())
    {
        QFile File(file);
        if(File.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&File);
            //in.setCodec("UTF-8");

            QString EncodingList = EncodingDocument;
            if (EncodingList == "UTF-8") in.setCodec("UTF-8");
            else if (EncodingList == "Unicode") in.setCodec("UTF-16");
            else if (EncodingList == "UTF-16BE") in.setCodec("UTF-16BE");
            else if (EncodingList == "UTF-16LE") in.setCodec("UTF-16LE");
            else if (EncodingList == "Windows-1251") in.setCodec("Windows-1251");
            else if (EncodingList == "KOI8-R") in.setCodec("KOI8-R");
            else if (EncodingList == "IBM866") in.setCodec("IBM866");
            else if (EncodingList == "ISO 8859-5") in.setCodec("ISO 8859-5");
            else in.setCodec("UTF-8");

            Encoding = EncodingList;

            QString text = in.readAll();
            File.close();

            ui->textEdit->setAcceptRichText(false);
            ui->textEdit->setText(text);
        }
        else {
            QMessageBox::information(this, "Error", "Unable to open file.", QMessageBox::Ok);
        }
    }
}

// Saving a file in UTF-8 encoding
void MainWindow::on_actionSave_as_UTF_8_triggered()
{
    ui->textEdit->setReadOnly(false);
    ui->textEdit->setAcceptRichText(false);

    QString file = "";

    file = QFileDialog::getSaveFileName(this, "Save file", "", "Text Files (*.txt)");

    if(!file.isEmpty())
    {
        QDir direct;
        QString dir = direct.filePath(file);
        QString FileName = dir;
        QFile File(FileName);

        if(File.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream out(&File);

            out.setCodec("UTF-8");
            out << ui->textEdit->toPlainText();

            File.flush();
            File.close();

            //QFileInfo fi(FileName);

            QMessageBox::information(this, "File was saved", "File was saved as " + FileName);
        }
    }
}

// Saving a file in a chosen encoding
void MainWindow::on_actionSave_as_triggered()
{
    ui->textEdit->setReadOnly(false);
    ui->textEdit->setAcceptRichText(false);

    QString file = "";

    file = QFileDialog::getSaveFileName(this, "Save file", "", "Text Files (*.txt)");

    if(!file.isEmpty())
    {
        QDir direct;
        QString dir = direct.filePath(file);
        QString FileName = dir;
        QFile File(FileName);

        if(File.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream out(&File);

            QStringList items;
            items << "UTF-8" << "Unicode (UTF-16)" << "UTF-16BE" << "UTF-16LE" <<
                     "Windows-1251 (Cyrillic)" << "KOI8-R (Cyrillic)" <<
                     "CP866 / IBM866 (Cyrillic)" << "ISO 8859-5 (Cyrillic)";

            bool ok;
            QString item = QInputDialog::getItem(this, "Changing encoding", "Choose encoding:", items, 0, false, &ok);

            QString EncodingDocument;
            if (ok && !item.isEmpty()) {

                if (item == "UTF-8") EncodingDocument = "UTF-8";
                else if (item == "Unicode (UTF-16)") EncodingDocument = "Unicode";
                else if (item == "UTF-16BE") EncodingDocument = "UTF-16BE";
                else if (item == "UTF-16LE") EncodingDocument = "UTF-16LE";
                else if (item == tr("Windows-1251 (Cyrillic)")) EncodingDocument = "Windows-1251";
                else if (item == tr("KOI8-R (Cyrillic)")) EncodingDocument = "KOI8-R";
                else if (item == tr("CP866 / IBM866 (Cyrillic)")) EncodingDocument = "IBM866";
                else if (item == tr("ISO 8859-5 (Cyrillic)")) EncodingDocument = "ISO 8859-5";
                else return;
            }

            QString EncodingList = EncodingDocument;
            if (EncodingList == "UTF-8") out.setCodec("UTF-8");
            else if (EncodingList == "Unicode") out.setCodec("UTF-16");
            else if (EncodingList == "UTF-16BE") out.setCodec("UTF-16BE");
            else if (EncodingList == "UTF-16LE") out.setCodec("UTF-16LE");
            else if (EncodingList == "Windows-1251") out.setCodec("Windows-1251");
            else if (EncodingList == "KOI8-R") out.setCodec("KOI8-R");
            else if (EncodingList == "IBM866") out.setCodec("IBM866");
            else if (EncodingList == "ISO 8859-5") out.setCodec("ISO 8859-5");
            else out.setCodec("UTF-8");

            out << ui->textEdit->toPlainText();

            File.flush();
            File.close();

            //QFileInfo fi(FileName);

            QMessageBox::information(this, "File was saved", "File was saved as " + FileName);
        }
    }
}

// Closing a file (actually, just clearing the text window because the file was already closed)
void MainWindow::on_actionClose_triggered()
{
    ui->textEdit->clear();
}

// Clearing the information window
void MainWindow::on_actionClear_info_triggered()
{
    ui->textEdit_2->clear();
}

// Closing the program
void MainWindow::on_actionExit_triggered()
{
    close();
}

/////////////////////////
// Menu "Edit" options //
/////////////////////////

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionSelect_All_triggered()
{
    ui->textEdit->selectAll();
}

void MainWindow::on_actionFind_triggered()
{
    QString find_text = QInputDialog::getText(this, "SearchText", "Find: ");
    if (ui->textEdit->isReadOnly() == false) {
        ui->textEdit->moveCursor(QTextCursor::Start);
        QColor color = QColor(Qt::yellow);
        while (ui->textEdit->find(find_text)) {
            ui->textEdit->setTextBackgroundColor(color);
            ui->textEdit->textCursor();
        }
    }
}

/////////////////////////
// Menu "View" options //
/////////////////////////

void MainWindow::on_actionZoom_In_triggered()
{
    ui->textEdit->zoomIn();
}

void MainWindow::on_actionZoom_Out_triggered()
{
    ui->textEdit->zoomOut();
}


/////////////////////////
// Menu "Mode" options //
/////////////////////////

void MainWindow::on_actionText_and_Information_triggered()
{
    Info_On = true;
    Text_On = true;
}

void MainWindow::on_actionOnly_Text_triggered()
{
    Info_On = false;
    Text_On = true;
}

void MainWindow::on_actionOnly_information_triggered()
{
    Info_On = true;
    Text_On = false;
}

void MainWindow::on_actionClear_information_automatically_triggered()
{
    Clear_On = true;
}

void MainWindow::on_actionDo_not_clear_information_triggered()
{
    Clear_On = false;
}

///////////////////////////
// Menu "Audio" options ///
///////////////////////////

void MainWindow::on_actionIngush_alphabet_triggered()
{
    QSound::play("audios/alphabet_ingush.wav");
}

void MainWindow::on_actionAlphabet_1_triggered()
{
    QSound::play("audios/alphabet_1.wav");
}

void MainWindow::on_actionAlphabet_2_triggered()
{
    QSound::play("audios/alphabet_2.wav");
}

void MainWindow::on_actionAlphabet_3_triggered()
{
    QSound::play("audios/alphabet_3.wav");
}

void MainWindow::on_actionAlphabet_4_triggered()
{
    QSound::play("audios/alphabet_4.wav");
}



/////////////////////////
// Menu "Help" options //
/////////////////////////

void MainWindow::on_actionAbout_triggered()
{
    QString about_text;
    about_text = "This is a program for learning Chechen and Ingush alphabets ";
    about_text = about_text + "and for editing texts on these languages." + "\n\n";

    about_text = about_text + "Copyright (C) 2022 Aleksandr Migunov" + "\n\n";

    about_text = about_text + "This program is free software; you can redistribute it and/or modify ";
    about_text = about_text + "it under the terms of the GNU General Public License as published by ";
    about_text = about_text + "the Free Software Foundation; either version 3 of the License, or ";
    about_text = about_text + "(at your option) any later version. \n\n";

    about_text = about_text + "This program is distributed in the hope that it will be useful, ";
    about_text = about_text + "but WITHOUT ANY WARRANTY; without even the implied warranty of ";
    about_text = about_text + "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the ";
    about_text = about_text + "GNU General Public License for more details. \n\n";

    about_text = about_text + "You should have received a copy of the GNU General Public License ";
    about_text = about_text + "along with this program. If not, see <https://www.gnu.org/licenses/>.";

    QMessageBox::about(this, "About Program", about_text);
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(0);
}


