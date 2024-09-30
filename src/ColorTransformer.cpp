#include "ColorTransformer.hpp"

#include <cmath>

bool ColorTransformer::transform(QImage* image, QString method, QVariantList jsList)
{
    if(image->isNull()) {
        qDebug() << "ColorTransformer: no image to transform, exit.";
        return false;
    }

    qDebug() << "ColorTransformer: performing color transformation. Method: " << method;

    QVariantMap params;

    QVariantList::iterator it = jsList.begin();
    while (it != jsList.end()) {
        qDebug() << it->toList()[0];
        params.insert(it->toList()[0].toString(), it->toList()[1].toDouble());     
        it++;
    }


    for(auto& k : params.keys())
        qDebug() << k << ' ' << params[k]; 

    if(method == "Grayscale")
        return gray_transform(image);
    if(method == "Invert") 
        return invert_transform(image);
    if(method == "Logarithmic") {
        double c = params["C"].toDouble();
        return log_transform(image, c);
    }
    if(method == "Power") {
        double gamma = params["Gamma"].toDouble();
        return pow_transform(image, gamma);
    }
    
    
    return false;
    

}

bool ColorTransformer::invert_transform(QImage* image)
{
    int width = image->width(), height = image->height();

    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            QRgb px = image->pixel(x, y);
            image->setPixelColor(x,y,qRgb(255 - qRed(px), 255 - qGreen(px), 255 - qBlue(px)));           
        }
    }

    return true;
}

bool ColorTransformer::log_transform(QImage* image, double c)
{
    int width = image->width(), height = image->height();

    //double c = 255 / std::log(256);
    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            QRgb px = image->pixel(x, y);
            int r = qRed(px), g = qGreen(px), b = qBlue(px);
            r = c*std::log(r+1), g = c*std::log(1+g), b = c*std::log(1+b);
            image->setPixelColor(x,y,qRgb(r,g,b));           
        }
    }

    return true;
}

bool ColorTransformer::pow_transform(QImage* image, double gamma)
{
    int width = image->width(), height = image->height();

    double c = 255 / std::pow(255, gamma);
    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            QRgb px = image->pixel(x, y);
            int r = qRed(px), g = qGreen(px), b = qBlue(px);
            r = c*std::pow(r+1e-8, gamma), g = c*std::pow(g+1e-8, gamma), b = c*std::pow(b+1e-8, gamma);
            image->setPixelColor(x,y,qRgb(r,g,b));           
        }
    }

    return true;
}

bool ColorTransformer::gray_transform(QImage* image)
{
    int width = image->width(), height = image->height();

    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            QRgb px = image->pixel(x, y);
            int r = qRed(px), g = qGreen(px), b = qBlue(px);
            int m = (r+b+g)/3;
            image->setPixelColor(x,y,qRgb(m,m,m));           
        }
    }

    return true;
}

QVariantMap ColorTransformer::getDistribution(QImage* image) 
{
    QVariantMap dist;

    if(image->isNull()) {
        qDebug() << "ColorTransformer: no image to analyze, exit.";
        return dist;
    }

    qDebug() << "ColorTransformer: performing color analysing.";

    dist["red"] = QVariant(QList<QVariant>(256, 0));
    dist["green"] = QVariant(QList<QVariant>(256, 0));
    dist["blue"] = QVariant(QList<QVariant>(256, 0));

    int width = image->width(), height = image->height();

    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            QRgb px = image->pixel(x, y);
            dist["red"].toList()[qRed(px)] = QVariant(dist["red"].toList()[qRed(px)].toDouble()+1);
            dist["green"].toList()[qGreen(px)] = QVariant(dist["green"].toList()[qGreen(px)].toDouble()+1);
            dist["blue"].toList()[qBlue(px)] = QVariant(dist["blue"].toList()[qBlue(px)].toDouble()+1);   
        }
    }

    return dist;

}