#pragma once

#include <vector>

#include <QGenericMatrix>
#include <QVariant>

#include "Tool.hpp"

using namespace std;

class Filter: public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit Filter(QObject *parent = nullptr);

    Q_INVOKABLE bool process(QImage* image);
    Q_INVOKABLE void setKernel(QVariantList array, int N, double R);

private:
    vector<vector<double>> _kernel;
    double _R;
    int _N = 3;

};