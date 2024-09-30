#include "Filter.hpp"

#include <QDebug>
#include <algorithm>


Filter::Filter(QObject *parent): QObject(parent) {

}

void Filter::setKernel(QVariantList array, int N, double R=1)
{
    _N = N;
    _R = R;
    _kernel = vector<vector<double>>(N, vector<double>(N));
    for(int i = 0; i < N*N; i++) {
        _kernel[i/N][i%N] = array[i].toDouble();
        qDebug() << "kernel (" << i/N << ',' << i%N << ") " << _kernel[i/N][i%N];
    }
}


bool Filter::process(QImage* image)
{
    if(image->isNull()) {
        qDebug() << "Filter: no image to filter, exit.";
        return false;
    }

    qDebug() << "Filter: performing convolutional filtering...";
    int width = image->width(), height = image->height();

    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            if(x >= _N/2 && y >= _N/2 && x < width - _N/2 && y < height - _N/2) {
                int r=0,g=0,b=0;
                for(int i = -_N/2; i <= _N/2; i++) {
                    for(int j = -_N/2; j <= _N/2; j++){
                        QRgb px = image->pixel(x+i, y+j);
                        r += qRed(px)*_kernel[i+_N/2][j+_N/2];
                        g += qGreen(px)*_kernel[i+_N/2][j+_N/2];
                        b += qBlue(px)*_kernel[i+_N/2][j+_N/2];
                    }
                }
                r = std::min(255, std::max((int)(r/_R), 0));//(256+(int)std::max(r/_R, -256.0))%256;//r /= _R;//
                g = std::min(255, std::max((int)(g/_R), 0));//(256+(int)std::max(g/_R, -256.0))%256;//g /= _R;//
                b = std::min(255, std::max((int)(b/_R), 0));//(256+(int)std::max(b/_R, -256.0))%256;//b /= _R;//
                image->setPixelColor(x,y,qRgb(r,g,b));
            }
        }
    }

    return true;
    
}