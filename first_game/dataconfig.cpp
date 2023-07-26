#include "dataconfig.h"

dataConfig::dataConfig(QObject *parent)
    : QObject{parent}
{
    int array1[4][4] = {{1, 1, 1, 1},
                        {1, 1, 0, 1},
                        {1, 0, 0, 0},
                        {1, 1, 0, 1}};
    QVector<QVector<int>>v1;
    for(int i=0;i<4;i++)
    {
        QVector<int>v11;
        for(int j=0;j<4;j++)
        {
            v11.push_back(array1[i][j]);
        }
        v1.push_back(v11);
    }
    mData.insert(1,v1);

    int array2[4][4] = {{1, 0, 1, 1},
                        {0, 0, 1, 1},
                        {1, 1, 0, 0},
                        {1, 1, 0, 1}};
    QVector<QVector<int>>v2;
    for(int i=0;i<4;i++)
    {
        QVector<int>v22;
        for(int j=0;j<4;j++)
        {
            v22.push_back(array2[i][j]);
        }
        v2.push_back(v22);
    }
    mData.insert(2,v2);

    int array3[4][4] = {{0, 1, 1, 1},
                        {1, 0, 1, 1},
                        {1, 1, 0, 0},
                        {1, 1, 0, 1}};
    QVector<QVector<int>>v3;
    for(int i=0;i<4;i++)
    {
        QVector<int>v33;
        for(int j=0;j<4;j++)
        {
            v33.push_back(array3[i][j]);
        }
        v3.push_back(v33);
    }
    mData.insert(3,v3);

    int array4[4][4] = {{0, 1, 1, 1},
                        {1, 0, 1, 1},
                        {1, 1, 0, 1},
                        {1, 1, 1, 0}};
    QVector<QVector<int>>v4;
    for(int i=0;i<4;i++)
    {
        QVector<int>v44;
        for(int j=0;j<4;j++)
        {
            v44.push_back(array4[i][j]);
        }
        v4.push_back(v44);
    }
    mData.insert(4,v4);

    int array5[4][4] = {{0, 1, 0, 1},
                        {1, 1, 0, 0},
                        {1, 1, 1, 1},
                        {1, 1, 1, 0}};
    QVector<QVector<int>>v5;
    for(int i=0;i<4;i++)
    {
        QVector<int>v55;
        for(int j=0;j<4;j++)
        {
            v55.push_back(array5[i][j]);
        }
        v5.push_back(v55);
    }
    mData.insert(5,v5);

    int array6[4][4] = {{0, 1, 1, 1},
                        {1, 1, 1, 1},
                        {1, 0, 1, 0},
                        {0, 1, 0, 1}};
    QVector<QVector<int>>v6;
    for(int i=0;i<4;i++)
    {
        QVector<int>v66;
        for(int j=0;j<4;j++)
        {
            v66.push_back(array6[i][j]);
        }
        v6.push_back(v66);
    }
    mData.insert(6,v6);

    int array7[4][4] = {{1, 0, 0, 1},
                        {0, 1, 1, 0},
                        {0, 1, 1, 0},
                        {1, 0, 0, 1}};
    QVector<QVector<int>>v7;
    for(int i=0;i<4;i++)
    {
        QVector<int>v77;
        for(int j=0;j<4;j++)
        {
            v77.push_back(array7[i][j]);
        }
        v7.push_back(v77);
    }
    mData.insert(7,v7);

    int array8[4][4] = {{1, 0, 1, 1},
                        {1, 1, 0, 0},
                        {0, 0, 1, 1},
                        {1, 1, 0, 1}};
    QVector<QVector<int>>v8;
    for(int i=0;i<4;i++)
    {
        QVector<int>v88;
        for(int j=0;j<4;j++)
        {
            v88.push_back(array8[i][j]);
        }
        v8.push_back(v88);
    }
    mData.insert(8,v8);

    int array9[4][4] = {{0, 1, 0, 1},
                        {1, 0, 0, 0},
                        {1, 0, 0, 0},
                        {0, 1, 0, 1}};
    QVector<QVector<int>>v9;
    for(int i=0;i<4;i++)
    {
        QVector<int>v99;
        for(int j=0;j<4;j++)
        {
            v99.push_back(array9[i][j]);
        }
        v9.push_back(v99);
    }
    mData.insert(9,v9);

    int array10[4][4] = {{0, 1, 1, 0},
                         {1, 1, 1, 1},
                         {1, 1, 1, 1},
                         {0, 1, 1, 0}};
    QVector<QVector<int>>v10;
    for(int i=0;i<4;i++)
    {
        QVector<int>v100;
        for(int j=0;j<4;j++)
        {
            v100.push_back(array10[i][j]);
        }
        v10.push_back(v100);
    }
    mData.insert(10,v10);

    int array11[4][4] = {{0, 1, 1, 0},
                        {0, 0, 0, 0},
                        {1, 1, 1, 1},
                        {0, 0, 0, 0}};
    QVector<QVector<int>>v11;
    for(int i=0;i<4;i++)
    {
        QVector<int>v111;
        for(int j=0;j<4;j++)
        {
            v111.push_back(array11[i][j]);
        }
        v11.push_back(v111);
    }
    mData.insert(11,v11);

    int array12[4][4] = {{1, 1, 1, 1},
                        {1, 1, 0, 1},
                        {1, 0, 0, 0},
                        {1, 1, 0, 1}};
    QVector<QVector<int>>v12;
    for(int i=0;i<4;i++)
    {
        QVector<int>v122;
        for(int j=0;j<4;j++)
        {
            v122.push_back(array12[i][j]);
        }
        v12.push_back(v122);
    }
    mData.insert(12,v12);

    int array13[4][4] = {{1, 0, 1, 1},
                        {0, 1, 0, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1}};
    QVector<QVector<int>>v13;
    for(int i=0;i<4;i++)
    {
        QVector<int>v133;
        for(int j=0;j<4;j++)
        {
            v133.push_back(array13[i][j]);
        }
        v13.push_back(v133);
    }
    mData.insert(13,v13);

    int array14[4][4] = {{0, 1, 0, 1},
                        {1, 0, 0, 0},
                        {1, 0, 0, 0},
                        {0, 1, 0, 1}};
    QVector<QVector<int>>v14;
    for(int i=0;i<4;i++)
    {
        QVector<int>v144;
        for(int j=0;j<4;j++)
        {
            v144.push_back(array14[i][j]);
        }
        v14.push_back(v144);
    }
    mData.insert(14,v14);

    int array15[4][4] = {{1, 0, 1, 1},
                        {0, 1, 0, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1}};
    QVector<QVector<int>>v15;
    for(int i=0;i<4;i++)
    {
        QVector<int>v155;
        for(int j=0;j<4;j++)
        {
            v155.push_back(array15[i][j]);
        }
        v15.push_back(v155);
    }
    mData.insert(15,v15);

    int array16[4][4] = {{0, 1, 1, 1},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0},
                        {1, 1, 1, 0}};
    QVector<QVector<int>>v16;
    for(int i=0;i<4;i++)
    {
        QVector<int>v166;
        for(int j=0;j<4;j++)
        {
            v166.push_back(array16[i][j]);
        }
        v16.push_back(v166);
    }
    mData.insert(16,v16);
    int array17[4][4] = {{0, 0, 0, 1},
                        {0, 0, 1, 0},
                        {0, 1, 0, 0},
                        {1, 0, 0, 0}};
    QVector<QVector<int>>v17;
    for(int i=0;i<4;i++)
    {
        QVector<int>v177;
        for(int j=0;j<4;j++)
        {
            v177.push_back(array17[i][j]);
        }
        v17.push_back(v177);
    }
    mData.insert(17,v17);

    int array18[4][4] = {{0, 0, 0, 1},
                         {0, 0, 0, 0},
                         {0, 0, 1, 1},
                         {1, 0, 1, 0}};
    QVector<QVector<int>>v18;
    for(int i=0;i<4;i++)
    {
        QVector<int>v188;
        for(int j=0;j<4;j++)
        {
            v188.push_back(array18[i][j]);
        }
        v18.push_back(v188);
    }
    mData.insert(18,v18);

    int array19[4][4] = {{0, 0, 0, 1},
                         {0, 1, 0, 0},
                         {0, 1, 0, 0},
                         {0, 0, 0, 1}};
    QVector<QVector<int>>v19;
    for(int i=0;i<4;i++)
    {
        QVector<int>v199;
        for(int j=0;j<4;j++)
        {
            v199.push_back(array19[i][j]);
        }
        v19.push_back(v199);
    }
    mData.insert(19,v19);

    int array20[4][4] = {{0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 0, 0, 0}};
    QVector<QVector<int>>v20;
    for(int i=0;i<4;i++)
    {
        QVector<int>v200;
        for(int j=0;j<4;j++)
        {
            v200.push_back(array20[i][j]);
        }
        v20.push_back(v200);
    }
    mData.insert(20,v20);
}
