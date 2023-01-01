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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    //MainWindow(QWidget *parent = 0); // for older Qt5
    ~MainWindow();
    bool UpperCase;
    bool LowerCase;
    bool Capitalize;
    QString FileOpened;
    QString NewOpened;
    QString Encoding;
    bool Audio_On;

private slots:
    void on_pushButton_upper_clicked();

    void on_pushButton_lower_clicked();

    void on_pushButton_capitalize_clicked();

    void on_pushButton_a_clicked();

    void on_pushButton_ae_clicked();

    void on_pushButton_b_clicked();

    void on_pushButton_v_clicked();

    void on_pushButton_g_clicked();

    void on_pushButton_g1_clicked();

    void on_pushButton_d_clicked();

    void on_pushButton_je_clicked();

    void on_pushButton_jo_clicked();

    void on_pushButton_zh_clicked();

    void on_pushButton_z_clicked();

    void on_pushButton_i_clicked();

    void on_pushButton_j_clicked();

    void on_pushButton_k_clicked();

    void on_pushButton_q_clicked();

    void on_pushButton_q1_clicked();

    void on_pushButton_k1_clicked();

    void on_pushButton_l_clicked();

    void on_pushButton_m_clicked();

    void on_pushButton_n_clicked();

    void on_pushButton_o_clicked();

    void on_pushButton_oe_clicked();

    void on_pushButton_p_clicked();

    void on_pushButton_p1_clicked();

    void on_pushButton_r_clicked();

    void on_pushButton_s_clicked();

    void on_pushButton_t_clicked();

    void on_pushButton_t1_clicked();

    void on_pushButton_u_clicked();

    void on_pushButton_ue_clicked();

    void on_pushButton_f_clicked();

    void on_pushButton_x_clicked();

    void on_pushButton_x1_clicked();

    void on_pushButton_h_clicked();

    void on_pushButton_c_clicked();

    void on_pushButton_c1_clicked();

    void on_pushButton_ch_clicked();

    void on_pushButton_ch1_clicked();

    void on_pushButton_sh_clicked();

    void on_pushButton_shch_clicked();

    void on_pushButton_hard_sign_clicked();

    void on_pushButton_y_clicked();

    void on_pushButton_soft_sign_clicked();

    void on_pushButton_e_clicked();

    void on_pushButton_ju_clicked();

    void on_pushButton_jue_clicked();

    void on_pushButton_ja_clicked();

    void on_pushButton_jae_clicked();

    void on_pushButton_stick_clicked();

    void on_pushButton_space_clicked();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionEncoding_triggered();

    void on_actionSave_as_UTF_8_triggered();

    void on_actionSave_as_triggered();

    void on_actionClose_triggered();

    void on_actionHide_triggered();

    void on_actionShow_triggered();

    void on_actionExit_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionSelect_All_triggered();

    void on_actionFind_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionAbout_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionAlphabet_1_triggered();

    void on_actionAlphabet_2_triggered();

    void on_actionAlphabet_3_triggered();

    void on_actionAlphabet_4_triggered();

    void on_checkBox_Audio_stateChanged(int arg1);

    void on_actionClear_info_triggered();

    void on_pushButton_b1_clicked();

    void on_pushButton_v1_clicked();

    void on_actionIngush_alphabet_triggered();

    void on_pushButton_d1_clicked();

    void on_pushButton_zh1_clicked();

    void on_pushButton_z1_clicked();

    void on_pushButton_j1_clicked();

    void on_pushButton_m1_clicked();

    void on_pushButton_n1_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
