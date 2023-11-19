#include <QApplication>
#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QImage>
#include <QDebug>

//низкочастотный фильтр: однородный усредняющий
QImage applyMeanFilter(const QImage &inputImage) {
    int kernelSize = 5;
    QImage outputImage = inputImage;

    for (int y = kernelSize / 2; y < inputImage.height() - kernelSize / 2; ++y) {
        for (int x = kernelSize / 2; x < inputImage.width() - kernelSize / 2; ++x) {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;

            for (int i = -kernelSize / 2; i <= kernelSize / 2; ++i) {
                for (int j = -kernelSize / 2; j <= kernelSize / 2; ++j) {
                    // Проверка координат на выход за границы изображения
                    if (x + j >= 0 && x + j < inputImage.width() && y + i >= 0 && y + i < inputImage.height()) {
                        QRgb pixel = inputImage.pixel(x + j, y + i);
                        sumRed += qRed(pixel);
                        sumGreen += qGreen(pixel);
                        sumBlue += qBlue(pixel);
                    }
                }
            }

            int avgRed = sumRed / (kernelSize * kernelSize);
            int avgGreen = sumGreen / (kernelSize * kernelSize);
            int avgBlue = sumBlue / (kernelSize * kernelSize);

            outputImage.setPixel(x, y, qRgb(avgRed, avgGreen, avgBlue));
        }
    }


    return outputImage;
}

//низкочастотный фильтр: Гаусса
QImage applyGaussianFilter(const QImage &inputImage) {
    int kernelSize = 5;
    QImage outputImage = inputImage;

    // Gaussian kernel
    double kernel[5][5] = {
        {1, 4, 6, 4, 1},
        {4, 16, 24, 16, 4},
        {6, 24, 36, 24, 6},
        {4, 16, 24, 16, 4},
        {1, 4, 6, 4, 1}
    };

    int kernelSum = 256; // Sum of all values in the kernel

    for (int y = kernelSize / 2; y < inputImage.height() - kernelSize / 2; ++y) {
        for (int x = kernelSize / 2; x < inputImage.width() - kernelSize / 2; ++x) {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;

            for (int i = -kernelSize / 2; i <= kernelSize / 2; ++i) {
                for (int j = -kernelSize / 2; j <= kernelSize / 2; ++j) {
                    // Проверка координат на выход за границы изображения
                    if (x + j >= 0 && x + j < inputImage.width() && y + i >= 0 && y + i < inputImage.height()) {
                        QRgb pixel = inputImage.pixel(x + j, y + i);
                        sumRed += qRed(pixel);
                        sumGreen += qGreen(pixel);
                        sumBlue += qBlue(pixel);
                    }
                }
            }

            int avgRed = sumRed / (kernelSize * kernelSize);
            int avgGreen = sumGreen / (kernelSize * kernelSize);
            int avgBlue = sumBlue / (kernelSize * kernelSize);

            outputImage.setPixel(x, y, qRgb(avgRed, avgGreen, avgBlue));
        }
    }


    return outputImage;
}

//адаптивная пороговая обработка
QImage applyAdaptiveThreshold(const QImage &inputImage, int windowSize, int thresholdOffset) {
    QImage outputImage = inputImage;

    for (int y = windowSize / 2; y < inputImage.height() - windowSize / 2; ++y) {
        for (int x = windowSize / 2; x < inputImage.width() - windowSize / 2; ++x) {
            int sum = 0;

            // Вычисляем среднее значение пикселей в локальном окне
            for (int i = -windowSize / 2; i <= windowSize / 2; ++i) {
                for (int j = -windowSize / 2; j <= windowSize / 2; ++j) {
                    QRgb pixel = inputImage.pixel(x + j, y + i);
                    sum += qRed(pixel); // Мы берем только значение красного канала, но можно использовать любой канал
                }
            }

            int avg = sum / (windowSize * windowSize);
            int currentPixelValue = qRed(inputImage.pixel(x, y)); // Текущее значение пикселя

            // Применяем пороговую обработку
            int newPixelValue = (currentPixelValue > avg + thresholdOffset) ? 255 : 0;

            outputImage.setPixel(x, y, qRgb(newPixelValue, newPixelValue, newPixelValue));
        }
    }

    return outputImage;
}

//локальная пороговая обработка: метод Бернсена
QImage applyBernsen(const QImage &inputImage, int windowSize, int contrastThreshold) {
    QImage outputImage = inputImage;

    for (int y = windowSize / 2; y < inputImage.height() - windowSize / 2; ++y) {
        for (int x = windowSize / 2; x < inputImage.width() - windowSize / 2; ++x) {
            int minValue = 255, maxValue = 0;

            // Находим минимальное и максимальное значение в локальном окне
            for (int i = -windowSize / 2; i <= windowSize / 2; ++i) {
                for (int j = -windowSize / 2; j <= windowSize / 2; ++j) {
                    QRgb pixel = inputImage.pixel(x + j, y + i);
                    int grayValue = qGray(pixel);
                    minValue = qMin(minValue, grayValue);
                    maxValue = qMax(maxValue, grayValue);
                }
            }

            int center = (minValue + maxValue) / 2;
            int contrast = maxValue - minValue;

            // Применение порога методом Бернсена
            int threshold = (contrast >= contrastThreshold) ? center : qGray(inputImage.pixel(x, y));

            outputImage.setPixel(x, y, qRgb(threshold, threshold, threshold));
        }
    }

    return outputImage;
}

//локальная пороговая обработка: метод Ниблацка
QImage applyNiblack(const QImage &inputImage, int windowSize, double k) {
    QImage outputImage = inputImage;

    for (int y = windowSize / 2; y < inputImage.height() - windowSize / 2; ++y) {
        for (int x = windowSize / 2; x < inputImage.width() - windowSize / 2; ++x) {
            int sum = 0, sumSquared = 0;

            // Вычисляем сумму и сумму квадратов значений пикселей в локальном окне
            for (int i = -windowSize / 2; i <= windowSize / 2; ++i) {
                for (int j = -windowSize / 2; j <= windowSize / 2; ++j) {
                    QRgb pixel = inputImage.pixel(x + j, y + i);
                    int grayValue = qGray(pixel);
                    sum += grayValue;
                    sumSquared += grayValue * grayValue;
                }
            }

            double mean = static_cast<double>(sum) / (windowSize * windowSize);
            double variance = static_cast<double>(sumSquared) / (windowSize * windowSize) - mean * mean;

            // Применение порога методом Ницбланка
            int threshold = static_cast<int>(mean + k * qSqrt(variance));

            outputImage.setPixel(x, y, qRgb(threshold, threshold, threshold));
        }
    }

    return outputImage;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    QWidget centralWidget;
    QVBoxLayout layout(&centralWidget);
    QLabel labelOriginal;
    QLabel labelProcessed;
    QPushButton pushButton("Низкочастотные фильтры");
    QPushButton thresholdButton("Адаптивная пороговая обработка");
    QPushButton bernsenButton("Локальная пороговая обработка: метод Бернсена");
    QPushButton niblackButton("Локальная пороговая обработка: метод Ниблацка");

    layout.addWidget(&labelOriginal, 0, Qt::AlignCenter);
    layout.addWidget(&labelProcessed, 0, Qt::AlignCenter);
    layout.addWidget(&pushButton, 0, Qt::AlignCenter);
    layout.addWidget(&thresholdButton, 0, Qt::AlignCenter);
    layout.addWidget(&bernsenButton, 0, Qt::AlignCenter);
    layout.addWidget(&niblackButton, 0, Qt::AlignCenter);

    QObject::connect(&pushButton, &QPushButton::clicked, [&]() {
        QString fileName = QFileDialog::getOpenFileName(&mainWindow, "Open Image", "", "Images (*.png *.jpg *.bmp)");

        if (fileName.isEmpty())
            return;

        QImage originalImage(fileName);

        if (originalImage.isNull()) {
            qDebug() << "Error: Unable to load image.";
            return;
        }

        // Применение однородного усредняющего фильтра
        QImage meanFiltered = applyMeanFilter(originalImage);

        // Применение фильтра Гаусса
        QImage gaussianFiltered = applyGaussianFilter(originalImage);

        // Отображение оригинального изображения
        labelOriginal.setPixmap(QPixmap::fromImage(gaussianFiltered));

        // Отображение обработанных изображений
        labelProcessed.setPixmap(QPixmap::fromImage(meanFiltered));
    });

    QObject::connect(&thresholdButton, &QPushButton::clicked, [&]() {
        QString fileName = QFileDialog::getOpenFileName(&mainWindow, "Open Image", "", "Images (*.png *.jpg *.bmp)");

        if (fileName.isEmpty())
            return;

        QImage originalImage(fileName);

        if (originalImage.isNull()) {
            qDebug() << "Error: Unable to load image.";
            return;
        }

        int windowSize = 5; // Размер локального окна
        int thresholdOffset = 3; // Смещение порога
        QImage thresholdedImage = applyAdaptiveThreshold(originalImage, windowSize, thresholdOffset);
        // Отображение обработанного изображения
        labelProcessed.setPixmap(QPixmap::fromImage(thresholdedImage));

    });

    QObject::connect(&bernsenButton, &QPushButton::clicked, [&]() {
        QString fileName = QFileDialog::getOpenFileName(&mainWindow, "Open Image", "", "Images (*.png *.jpg *.bmp)");

        if (fileName.isEmpty())
            return;

        QImage originalImage(fileName);

        if (originalImage.isNull()) {
            qDebug() << "Error: Unable to load image.";
            return;
        }

        int windowSize = 5; // Размер локального окна
        int contrastThreshold = 30; // Порог контраста
        QImage thresholdedImage = applyBernsen(originalImage, windowSize, contrastThreshold);

        // Отображение обработанного изображения
        labelProcessed.setPixmap(QPixmap::fromImage(thresholdedImage));
    });

    // Слот для кнопки Apply Niblack
    QObject::connect(&niblackButton, &QPushButton::clicked, [&]() {
        QString fileName = QFileDialog::getOpenFileName(&mainWindow, "Open Image", "", "Images (*.png *.jpg *.bmp)");

        if (fileName.isEmpty())
            return;

        QImage originalImage(fileName);

        if (originalImage.isNull()) {
            qDebug() << "Error: Unable to load image.";
            return;
        }

        int windowSize = 5; // Размер локального окна
        double k = -0.2; // Параметр k
        QImage thresholdedImage = applyNiblack(originalImage, windowSize, k);

        // Отображение обработанного изображения
        labelProcessed.setPixmap(QPixmap::fromImage(thresholdedImage));
    });


    mainWindow.setCentralWidget(&centralWidget);
    mainWindow.show();

    return app.exec();
}
