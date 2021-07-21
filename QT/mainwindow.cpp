#include "mainwindow.h"
#include <QDebug>
#include "ui_mainwindow.h"
#include <QDialog>
#include <QFileDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <random>
#include <QImage>
#include <QTextStream>
#include <QMovie>
#include <QPalette>
#include <QLabel>
#include <QPixmap>
#include <QRadioButton>

QPair <int, int> MG[15][16] = {{qMakePair(0,0), qMakePair(0,0), qMakePair(0, 0), qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,1),  qMakePair(1,1),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,1),  qMakePair(1,1),  qMakePair(1,0)},
                               {qMakePair(0,0), qMakePair(0,0), qMakePair(0, 0), qMakePair(1,0),  qMakePair(1,4),  qMakePair(1,1),  qMakePair(1,1),  qMakePair(1,5),  qMakePair(1,1),  qMakePair(1,1),  qMakePair(1,5),  qMakePair(1,1),  qMakePair(1,1),  qMakePair(1,0)},
                               {qMakePair(1,0), qMakePair(1,0), qMakePair(1,0),  qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                               {qMakePair(1,0), qMakePair(1,2), qMakePair(1,1),  qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                               {qMakePair(1,1), qMakePair(1,1), qMakePair(1,4),  qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0)},
                               {qMakePair(1,1), qMakePair(1,1), qMakePair(1,1),  qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                               {qMakePair(1,1), qMakePair(1,1), qMakePair(1,1),  qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                               {qMakePair(1,1), qMakePair(1,1), qMakePair(1,1),  qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                               {qMakePair(1,0), qMakePair(1,3), qMakePair(1,2),  qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0)},
                               {qMakePair(1,0), qMakePair(1,0), qMakePair(1,1),  qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                               {qMakePair(1,0), qMakePair(1,0), qMakePair(1,0),  qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)}
                              };


QPair <int,int> EG[13][13]={{qMakePair(0,0), qMakePair(0,0), qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,4),  qMakePair(1,2),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0)},
                            {qMakePair(0,0), qMakePair(0,0), qMakePair(1,2),  qMakePair(1,4),  qMakePair(1,8),  qMakePair(1,3),  qMakePair(1,2),  qMakePair(1,3),  qMakePair(1,3),  qMakePair(1,3)},
                            {qMakePair(1,1), qMakePair(1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                            {qMakePair(1,0), qMakePair(1,3), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                            {qMakePair(1,0), qMakePair(1,5), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                            {qMakePair(1,0), qMakePair(1,5), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                            {qMakePair(1,1), qMakePair(1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1)},
                            {qMakePair(1,1), qMakePair(1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1)},
                            {qMakePair(1,2), qMakePair(1,2), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1)},
                            {qMakePair(1,3), qMakePair(1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0)},
                            {qMakePair(1,0), qMakePair(1,5), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0)}
                           };


QPair <int,int> HG[20][20]={{qMakePair(0,0), qMakePair(0,0), qMakePair(0,0), qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,3),  qMakePair(1,5),  qMakePair(1,6),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0)},
                            {qMakePair(0,0), qMakePair(0,0), qMakePair(0,0), qMakePair(1,2),  qMakePair(1,0),  qMakePair(1,7),  qMakePair(1,7),  qMakePair(1,5),  qMakePair(1,3),  qMakePair(1,1),  qMakePair(1,6),  qMakePair(1,6),  qMakePair(1,5),  qMakePair(1,3),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,2)},
                            {qMakePair(0,0), qMakePair(0,0), qMakePair(0,0), qMakePair(1,2),  qMakePair(1,7),  qMakePair(1,2),  qMakePair(1,2),  qMakePair(1,1),  qMakePair(1,2),  qMakePair(1,2),  qMakePair(1,4),  qMakePair(1,1),  qMakePair(1,3),  qMakePair(1,5),  qMakePair(1,7),  qMakePair(1,7),  qMakePair(1,7),  qMakePair(1,2)},
                            {qMakePair(1,0), qMakePair(1,2), qMakePair(1,2), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                            {qMakePair(1,0), qMakePair(1,0), qMakePair(1,7), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                            {qMakePair(1,0), qMakePair(1,0), qMakePair(1,7), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                            {qMakePair(1,0), qMakePair(1,0), qMakePair(1,7), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                            {qMakePair(1,3), qMakePair(1,5), qMakePair(1,3), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0)},
                            {qMakePair(1,5), qMakePair(1,3), qMakePair(1,5), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1)},
                            {qMakePair(1,6), qMakePair(1,1), qMakePair(1,6), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1)},
                            {qMakePair(1,0), qMakePair(1,6), qMakePair(1,6), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0)},
                            {qMakePair(1,6), qMakePair(1,1), qMakePair(1,6), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1)},
                            {qMakePair(1,5), qMakePair(1,1), qMakePair(1,5), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1)},
                            {qMakePair(1,3), qMakePair(1,1), qMakePair(1,3), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0)},
                            {qMakePair(1,0), qMakePair(1,0), qMakePair(1,2), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                            {qMakePair(1,0), qMakePair(1,0), qMakePair(1,2), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                            {qMakePair(1,0), qMakePair(1,0), qMakePair(1,4), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                            {qMakePair(1,0), qMakePair(1,0), qMakePair(1,2), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)}
                           };

QPair <int,int> MMG[25][25]={{qMakePair(0,0), qMakePair(0,0), qMakePair(1,0), qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,2),  qMakePair(1,4),  qMakePair(1,5),  qMakePair(1,2),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,1),  qMakePair(1,1),  qMakePair(1,1),  qMakePair(1,0),   qMakePair(1,0),  qMakePair(1,0)},
                             {qMakePair(0,0), qMakePair(0,0), qMakePair(1,2), qMakePair(1,3),  qMakePair(1,5),  qMakePair(1,6),  qMakePair(1,4),  qMakePair(1,4),  qMakePair(1,4),  qMakePair(1,7),  qMakePair(1,8),  qMakePair(1,6),  qMakePair(1,3),  qMakePair(1,2),  qMakePair(1,3),  qMakePair(1,3),  qMakePair(1,4),   qMakePair(1,4),  qMakePair(1,3)},
                             {qMakePair(1,1), qMakePair(1,2), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1)},
                             {qMakePair(1,1), qMakePair(1,3), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1)},
                             {qMakePair(1,1), qMakePair(1,4), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1)},
                             {qMakePair(1,0), qMakePair(1,4), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0)},
                             {qMakePair(1,0), qMakePair(1,3), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0)},
                             {qMakePair(1,0), qMakePair(1,2), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                             {qMakePair(1,0), qMakePair(1,2), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                             {qMakePair(1,0), qMakePair(1,2), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                             {qMakePair(1,0), qMakePair(1,6), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                             {qMakePair(1,0), qMakePair(1,8), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                             {qMakePair(1,7), qMakePair(1,2), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                             {qMakePair(1,4), qMakePair(1,5), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                             {qMakePair(1,4), qMakePair(1,4), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                             {qMakePair(1,4), qMakePair(1,2), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                             {qMakePair(1,0), qMakePair(1,6), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                             {qMakePair(1,0), qMakePair(1,5), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                             {qMakePair(1,0), qMakePair(1,3), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                             {qMakePair(1,0), qMakePair(1,2), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0)},
                            };

QPair <int,int> HGG[30][35]={{qMakePair(0,0), qMakePair(0,0), qMakePair(0,0),   qMakePair(0,0),   qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,3),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,2) , qMakePair(1,0), qMakePair(1,0), qMakePair(1,0), qMakePair(1,0), qMakePair(1,0), qMakePair(1,0)},
                              {qMakePair(0,0), qMakePair(0,0), qMakePair(0,0),   qMakePair(0,0),   qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,0),  qMakePair(1,4),  qMakePair(1,2),  qMakePair(1,1),  qMakePair(1,0),  qMakePair(1,3),  qMakePair(1,2),  qMakePair(1,10), qMakePair(1,1), qMakePair(1,1), qMakePair(1,1), qMakePair(1,0), qMakePair(1,0), qMakePair(1,0)},
                              {qMakePair(0,0), qMakePair(0,0), qMakePair(0,0),   qMakePair(0,0),   qMakePair(1,0),  qMakePair(1,5),  qMakePair(1,7),  qMakePair(1,8),  qMakePair(1,10), qMakePair(1,11), qMakePair(1,12), qMakePair(1,1),  qMakePair(1,2),  qMakePair(1,1),  qMakePair(1,22), qMakePair(1,14), qMakePair(1,12), qMakePair(1,2) , qMakePair(1,9), qMakePair(1,8), qMakePair(1,6), qMakePair(1,4), qMakePair(1,3), qMakePair(1,0)},
                              {qMakePair(0,0), qMakePair(0,0), qMakePair(0,0),   qMakePair(0,0),   qMakePair(1,1),  qMakePair(1,1),  qMakePair(1,2),  qMakePair(1,3),  qMakePair(1,4),  qMakePair(1,4),  qMakePair(1,4),  qMakePair(1,2),  qMakePair(1,4),  qMakePair(1,4),  qMakePair(1,2),  qMakePair(1,4),  qMakePair(1,4),  qMakePair(1,2) , qMakePair(1,6), qMakePair(1,5), qMakePair(1,5), qMakePair(1,4), qMakePair(1,2), qMakePair(1,1)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,0),   qMakePair(1,2),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0) ,qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,0),   qMakePair(1,4),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,0),   qMakePair(1,7),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,0),   qMakePair(1,1),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0) ,qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,0),   qMakePair(1,3),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0) ,qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,1),   qMakePair(1,2),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0) ,qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,2),   qMakePair(1,3),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0) ,qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,2),   qMakePair(1,3),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0) ,qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,3),   qMakePair(1,4),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,3),   qMakePair(1,5),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,4),   qMakePair(1,6),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,5),   qMakePair(1,6),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,6),   qMakePair(1,7),   qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,6),   qMakePair(1,7),   qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,6),   qMakePair(1,8),   qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,6),   qMakePair(1,9),   qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,7),   qMakePair(1,9),   qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,6),   qMakePair(1,10),  qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,5),   qMakePair(1,1),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0) ,qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,4),   qMakePair(1,4),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,6), qMakePair(1,1),   qMakePair(1,6),   qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,0),   qMakePair(1,17),  qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,0)},
                              {qMakePair(1,4), qMakePair(1,2), qMakePair(1,2),   qMakePair(1,4),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,0) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,0),   qMakePair(1,13),  qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,1),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)},
                              {qMakePair(1,0), qMakePair(1,0), qMakePair(1,0),   qMakePair(1,9),   qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,0), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1), qMakePair(-1,1) ,qMakePair(-1,1),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0),qMakePair(-1,0)}
                            };


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    test = new QPushButton(this);
    this->setWindowTitle("Nonograms");
    this->setWindowIcon(QIcon(":/new/p/nn.png"));

    setCursor(QCursor(Qt::PointingHandCursor));

    board = new QRect*[100];
    for(int i = 0; i < 100; i++)
    {
        board[i] = new QRect[100];
    }

    for(int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
        {
            flag[i][j] = false; // skzbnakan vichak
        }

    start_x = 50; start_y = 100;//taracqi verevi dzaxi coordinates
    selectLevel(1);
    mode = 1;
    help = false;

    srand(time(NULL));

    connect(test, SIGNAL(released()), this, SLOT(check()));
    test->setText("Test");
    test->setStyleSheet("background-color:darkgray");
}

void MainWindow::paintEvent(QPaintEvent *)//
{
    QPainter painter(this);
    QBrush gray (Qt::gray);
    QBrush lgray(Qt::lightGray);
    QBrush black(Qt::gray);
    QBrush white(Qt::white);
    painter.drawImage(0,0,QImage(":/new/p/bigstock-Gray-Background-3368923.jpg"));

    for(int i = 0; i < size_y; i++)
    {
        for(int j = 0; j < size_x; j++)
        {
            if(level[i][j].first == 0)
            {
                painter.setBrush(gray);
                painter.drawRect(board[i][j]);
            }
            if(level[i][j].first == 1)
            {
                painter.setBrush(lgray);
                painter.drawRect(board[i][j]);
                painter.setPen(Qt::black);
                if(level[i][j].second)
                    painter.drawText(board[i][j], Qt::AlignCenter, QString::number(level[i][j].second));
            }
            if(level[i][j].first == -1)
            {
                if(flag[i][j])
                {
                    painter.setBrush(black);
                }
                else
                    painter.setBrush(white);
                painter.drawRect(board[i][j]);
            }
        }
    }
}

void MainWindow::selectLevel(int l)//
{
    if(l == 1)
    {
        test->setGeometry(100,50,100,25);
        size_x = 10;
        size_y = 11;
        for(int i = 0; i < size_y; i++)
            for(int j = 0; j < size_x; j++)
            {
                level[i][j] = EG[i][j];
            }
        this->setFixedSize(300, 350);
    }
    if(l == 2)
    {
        test->setGeometry(142,50,100,25);
        size_x = 14;
        size_y = 11;
        for(int i = 0; i < size_y; i++)
            for(int j = 0; j < size_x; j++)
            {
                level[i][j] = MG[i][j];
            }
        this->setFixedSize(384, 350);
    }
    if(l == 3)
    {
        test->setGeometry(180,50,100,25);
        size_x = 18;
        size_y = 18;
        for(int i = 0; i < size_y; i++)
            for(int j = 0; j < size_x; j++)
            {
                level[i][j] = HG[i][j];
            }
        this->setFixedSize(460, 500);
    }
    if(l == 4)
    {
        test->setGeometry(185,50,100,25);
        size_x = 19;
        size_y = 20;
        for(int i = 0; i < size_y; i++)
            for(int j = 0; j < size_x; j++)
            {
                level[i][j] = MMG[i][j];
            }
        this->setFixedSize(480, 550);
    }
    if(l == 5)
    {
        test->setGeometry(230,50,100,25);
        size_x = 24;
        size_y = 29;
        for(int i = 0; i < size_y; i++)
            for(int j = 0; j < size_x; j++)
            {
                level[i][j] = HGG[i][j];
            }
        this->setGeometry(350,33,560,690);
        this->setFixedSize(560, 690);
    }

    for(int i = 0; i < size_y; i++)
    {
        for(int j = 0; j < size_x; j++)
        {
            board[i][j].setRect(start_x + j * 20, start_y + i * 20, 20, 20);
            flag[i][j] = false;
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)//
{
    for(int i = 0; i < size_y; i++)
    {
        for(int j = 0; j < size_x; j++)
        {
            if(board[i][j].contains(event->pos()))
            {
                if(level[i][j].first == -1)
                {
                    if(event->button() == Qt::LeftButton)
                    {
                        flag[i][j] = !flag[i][j];
                        repaint();
                    }
                }
            }
       }
    }
}

void MainWindow::keyPressEvent(QKeyEvent * event)//
{
    if(help && event->key() == Qt::Key_H)
    {
        int i, j;
        do
        {
            i = rand()%size_y;
            j = rand()%size_x;
        }
        while(!level[i][j].second);
        flag[i][j] = true;
        repaint();
    }
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    QMessageBox::StandardButton but = QMessageBox::question( this,tr("N"),
                                                                    tr("Do you want to save this game?\n"),
                                                                    QMessageBox::No |
                                                                    QMessageBox::Save,
                                                                    QMessageBox::Save);

        if (but != QMessageBox::Save)
        {
            event->accept();
        }
        else
        {
            on_actionSave_triggered();
        }

}

void MainWindow::NewGame()
{
    for(int i = 0; i< size_y ;i++)
    {
        for(int j = 0; j < size_x; j++)
        {
            flag[i][j] = 0;
        }
    }
    repaint();
}

void MainWindow::EndGame()//
{
    QString msg="YOU WIN!!! <br> Do you want to start new game?";
    QMessageBox *msgbox =new QMessageBox;
    msgbox->setGeometry(600,350,150,100);
    msgbox->setText(msg);
    msgbox->setWindowTitle("Nonograms");
    msgbox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgbox->setIcon(QMessageBox::Information);
    msgbox->setWindowIcon(QIcon(":/new/p/nn.png"));
    int x = msgbox->exec();
    delete msgbox;
    if(x==QMessageBox::Yes)
        NewGame();
    else
        this->close();
}

QString MainWindow::dump()
{
    QString master="";

    for(int i = 0; i< size_y ;i++)
    {
        for(int j = 0; j < size_x; j++)
        {
            if(flag[i][j]==true)
            {
                master.append('0');
            }
            else
            {
                master.append('1');
            }
        }
        master.append("\n");
    }
    return master;
}

void MainWindow::setdump(const QString &data)
{
    int current =0;
    if(data.size()==110){
        selectLevel(1);
        mode = 1;


    for(int i = 0; i< size_y ;i++)
    {
        for(int j = 0; j < size_x; j++)
        {
            if(data[current]=='0')
            {
                flag[i][j]=1;
            }
            else{
                flag[i][j]=0;
            }
            current++;
        }
    }
    update();
    }
    if(data.size()==154){
        selectLevel(2);
        mode = 2;


    for(int i = 0; i< size_y ;i++)
    {
        for(int j = 0; j < size_x; j++)
        {
            if(data[current]=='0')
            {
                flag[i][j]=1;
            }
            else{
                flag[i][j]=0;
            }
            current++;
        }
    }
    update();
    }
    if(data.size()==324){
        selectLevel(3);
        mode = 3;


    for(int i = 0; i< size_y ;i++)
    {
        for(int j = 0; j < size_x; j++)
        {
            if(data[current]=='0')
            {
                flag[i][j]=1;
            }
            else{
                flag[i][j]=0;
            }
            current++;
        }
    }
    update();
    }
    if(data.size()==380){
        selectLevel(4);
        mode = 4;


    for(int i = 0; i< size_y ;i++)
    {
        for(int j = 0; j < size_x; j++)
        {
            if(data[current]=='0')
            {
                flag[i][j]=1;
            }
            else{
                flag[i][j]=0;
            }
            current++;
        }
    }
    update();
    }
    if(data.size()==696){
        selectLevel(5);
        mode = 5;


    for(int i = 0; i< size_y ;i++)
    {
        for(int j = 0; j < size_x; j++)
        {
            if(data[current]=='0')
            {
                flag[i][j]=1;
            }
            else{
                flag[i][j]=0;
            }
            current++;
        }
    }
    update();
    }


}

void MainWindow::check()//
{
    bool win = true;

    for(int i = 0; i < size_y; i++)
    {
        for(int j = 0; j < size_x; j++)
        {
            if(level[i][j].first == -1)
            {
                if(flag[i][j] != level[i][j].second)
                    win = false;
                if(flag[i][j] && flag[i][j] != level[i][j].second)
                {
                    QMessageBox * box = new QMessageBox;
                    box->setIcon(QMessageBox::Critical);
                    box->setGeometry(600,350,100,50);
                    box->setWindowIcon(QIcon(":/new/p/nn.png"));
                    box->setText("You have errors <br>");
                    box->setWindowTitle("Nonograms");
                    box->setStandardButtons(QMessageBox::Ok);
                    box->exec();
                    delete box;
                    return;
                }
            }
        }
    }
    if(win)
        EndGame();
}

void MainWindow::on_actionNew_triggered()
{
    NewGame();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionAbout_triggered()//
{
    QDialog *di=new QDialog(this);
    di->setWindowIcon(QIcon(":/new/p/nn.png"));
    di->setWindowTitle("About");

    QString string;
    QString string1;
    string1+="GAME NONOGRAM <br>";
    string+="<br> Copyright Mery Hovsepyan <br>";
    string+="<br> All rights  reserved <br>";
    string+="<br> It is based on Qt 4.5.1 <br>";
    string+="<br> Revison 2tft4844 <br>";
    string+="<br> © 2018  <br>";
    string+="<br> DONE WITH LOVE ";

    QLabel *lab=new QLabel(string,di);
    QLabel *lab1=new QLabel(string1,di);
    lab1->setText(string1);
    lab1->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    lab1->setGeometry(220,10,250,25);
    QFont font2 = lab1->font();
    font2.setPixelSize(14);
    lab1->setFont(font2);
    lab->setText(string);
    lab->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    lab->setGeometry(220,25,250,200);
    di->setFixedSize(400,247);
    QFont font = lab->font();
    font.setPixelSize(12);
    lab->setFont(font);
    QLabel *lab2=new QLabel(di);

    QPixmap image(":/new/p/nn.png");
    lab2->setPixmap(image);
    lab2->show();
    lab2->setGeometry(10,0,200,200);
    close1 = new QPushButton(di);
    connect(close1, SIGNAL(released()), di, SLOT(close()));
    close1->setGeometry(290,210,100, 25);
    close1->setText("Close");
    close1->setStyleSheet("background-color:lightblue");
    di->exec();
}

void MainWindow::on_actionRules_triggered()//
{
    QDialog *dialog=new QDialog(this);
    dialog->setWindowIcon(QIcon(":/new/p/nn.png"));
    dialog->setWindowTitle("Rules");
    dialog->setFixedSize(600,295);
    QString string3;
    string3+="A Japanese crossword – is a puzzle, which has a picture encoded in numbers. <br> ";
    string3+="The aim of the puzzle is to restore this picture in full.<br>";
    string3+="<br>The purpose of this game is to discover a board made up of black squares and free spaces.<br>"
             " You can do this by looking at row/column definitions:<br> "
             "a sequence of numbers that describe groups of consecutive squares appearing on that row/column.<br>"
             " For example, 1 5 2 means one square, 5 squares and 2 squares, in this order,<br> "
             "separated by one or more spaces between them.";
    QLabel *lab3=new QLabel(string3,dialog);
    lab3->setText(string3);
    lab3->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    lab3->setGeometry(10,10,570,370);
    QLabel *lab5=new QLabel(dialog);
    QPixmap image1(":/new/p/t.PNG");
    lab5->setPixmap(image1);
    lab5->show();
    lab5->setGeometry(120,80,400,200);
    lab5->show();
    QString string4;
    string4+="You can click the squares once in order to mark them as occupied.<br>";
    string4+=" Clicking them again will mark them white.<br>";
    QLabel *lab4=new QLabel(string4,dialog);
    lab4->setText(string4);
    lab4->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    lab4->setGeometry(10,220,570,370);
    QFont font3 = lab3->font();
    font3.setPixelSize(13);
    lab3->setFont(font3);
    QFont font4 = lab4->font();
    font4.setPixelSize(13);
    lab4->setFont(font4);
    QPixmap bkgnd2(":/new/p/m.jpg");
    bkgnd2 = bkgnd2.scaled(dialog->size(), Qt::IgnoreAspectRatio);
    QPalette palette1;
    palette1.setBrush(QPalette::Background, bkgnd2);
    dialog->setPalette(palette1);

    close2 = new QPushButton(dialog);
    connect(close2, SIGNAL(released()), dialog, SLOT(close()));
    close2->setGeometry(487,260,100, 25);
    close2->setText("Close");
    close2->setStyleSheet("background-color:lightblue");
    dialog->show();
}

QDialog *dial;
QRadioButton * on ;
QRadioButton * off;
QRadioButton * easy ;
QRadioButton * medium;
QRadioButton * hard;
QRadioButton * med;
QRadioButton * hard2;


void MainWindow::saveOptions()
{
    if(mode != 1 && easy->isChecked())
    {
        selectLevel(1);
        mode = 1;
    }
    if(mode !=2 && medium->isChecked())
    {
        selectLevel(2);
        mode = 2;
    }
    if(mode !=3 && hard->isChecked())
    {
        selectLevel(3);
        mode = 3;
    }
    if(mode !=4 && med->isChecked())
    {
        selectLevel(4);
        mode = 4;
    }
    if(mode !=5 && hard2->isChecked())
    {
        selectLevel(5);
        mode = 5;
    }
    if(on->isChecked())
    {
        help = true;
    }
    else
        help = false;
    dial->close();
}

void MainWindow::on_actionOptions_triggered()
{
    dial=new QDialog;
    dial->setWindowIcon(QIcon(":/new/p/nn.png"));
    dial->setStyleSheet("background-color:white;");
    dial->setWindowTitle("Options");
    QPixmap bkgnd3 (":/new/p/88.PNG");
    save = new QPushButton(dial);
    connect(save, SIGNAL(released()), this, SLOT(saveOptions()));
    save->setText("Save");
    save->setStyleSheet("background-color:lightgray;");
    close3 = new QPushButton(dial);
    connect(close3, SIGNAL(released()), dial, SLOT(close()));
    close3->setText("Close");
    close3->setStyleSheet("background-color:lightgray;");
    QGridLayout *grid = new QGridLayout(dial);
    QGroupBox *level1 = new QGroupBox("Level");
    QFont font6 = level1->font();
    grid->addWidget(level1, 0, 0);
    easy = new QRadioButton("8x9");
    medium = new QRadioButton("11x9");
    hard = new QRadioButton("18x18");
    med= new QRadioButton("19x20");
    hard2= new QRadioButton("26x22");

    if(mode == 1)
        easy->setChecked(true);
    else
        if(mode == 2)
            medium->setChecked(true);
        else
            if(mode == 3)
                hard->setChecked(true);
            else
                if(mode==4)
                    med->setChecked(true);
                else
                    if(mode==5)
                        hard2->setChecked(true);


    QVBoxLayout * vb=new QVBoxLayout(dial);
    vb->addWidget(easy);
    vb->addWidget(medium);
    vb->addWidget(hard);
    vb->addWidget(med);
    vb->addWidget(hard2);
    level1->setLayout(vb);
    level1->setFixedSize(100,140);
    grid->addWidget(level1,0,0);
    QGroupBox *help1 = new QGroupBox("Help");
    grid->addWidget(help1, 0, 0);
    on = new QRadioButton("On");
    off = new QRadioButton("Off");
    if(help)
    {
        on->setChecked(true);
    }
    else
        off->setChecked(true);
    QVBoxLayout * vb2=new QVBoxLayout(dial);
    vb2->addWidget(on);
    vb2->addWidget(off);
    help1->setLayout(vb2);
    help1->setFixedSize(100,120);
    grid->addWidget(help1,0,1);
    QHBoxLayout * vvb=new QHBoxLayout(dial);
    vvb->addWidget(save);
    vvb->addWidget(close3);
    grid->addLayout(vvb, 1, 0);
    QLabel *image=new QLabel(dial);
    image->setPixmap(bkgnd3);
    grid->addWidget(image,1,1);
    dial->exec();

}

void MainWindow::on_actionSave_triggered()
{
    QString filename=QFileDialog::getSaveFileName(this,tr("Save current game"),
                                                  QDir::homePath(),
                                                  tr("Mery's Game *.non Files (*.non)"));
    if(filename.isEmpty())
    {
        return;
    }

    QFile file(filename);
        if(!file.open(QIODevice::WriteOnly))
        {
        QMessageBox::information(this,tr("Unable to open file"),
                                 file.errorString());
            return;
        }
        file.write(dump().toUtf8());
        file.close();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Address Book"), "",
            tr("Address Book (*.non);;All Files (*)"));
    if (fileName.isEmpty())
         return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
    QMessageBox::information(this, tr("Unable to open file"),
    file.errorString());
    return;
    }
    QString line;
    QTextStream out(&file);
    while(!out.atEnd())
    {
        QString line1 = out.readLine();
        line.push_back(line1);
    }
    file.close();
    setdump(line);
    repaint();
}
MainWindow::~MainWindow()
{
    for(int i = 0; i < 100; i++)
    {
        delete[] board[i];
    }
    delete[] board;
    delete ui;
}
