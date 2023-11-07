#include <QApplication>
#include <QPushButton>
#include <QHeaderView>
#include <QTableWidget>
#include <QTableView>
#include <QMenuBar>
#include <QAction>
#include <QDebug>
#include <QFileDialog>
#include <QVBoxLayout>
#include <cmath>
#include <QDir>
#include <QDebug>

// Виджет-таблица со списком файлов и их свойствами
QTableWidget *m_pTableWidget;

// Считывание информации о заданном списке файлов и заполнение виджета таблицы
void fillInfo(QStringList fileNames)
{
    int initialSize = m_pTableWidget->rowCount();
    m_pTableWidget->setRowCount(initialSize + fileNames.size());

    for (int i = initialSize; i < m_pTableWidget->rowCount(); i++)
    {
        int idx = i - initialSize;
        // Базовую информацию получим с помощью QImage
        QImage img;
        img.load(fileNames[idx]);
        QTableWidgetItem *item = new QTableWidgetItem(QFileInfo(fileNames[idx].trimmed()).fileName());
        m_pTableWidget->setItem(i, 0, item);

        QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(img.height()));
        m_pTableWidget->setItem(i, 1, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(img.width()));
        m_pTableWidget->setItem(i, 2, item3);

        QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(img.bitPlaneCount()));
        m_pTableWidget->setItem(i, 3, item4);

        // Разрешение QImage выдает в точках на метр, переведем в дюймы
        // Полагаем что по x и y разрешение одинаковое, поэтому просто возьмем X
        QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(std::round(img.dotsPerMeterX() / 39.3701)));
        m_pTableWidget->setItem(i, 4, item5);

        QFile file(fileNames[idx]);
        file.open(QIODevice::ReadOnly);
        QTableWidgetItem *item6;

        if (fileNames[idx].toLower().endsWith("bmp") || fileNames[idx].toLower().endsWith("pcx")) {
            item6 = new QTableWidgetItem("N/A");
        }
        else {
            double pureSize = img.height() * img.width() * img.bitPlaneCount() / 8;
            int fileSize = file.size();
            float ratio = (float)((int)(pureSize / fileSize * 100 + 0.5));
            item6 = new QTableWidgetItem(QString::number(ratio / 100));
        }
        m_pTableWidget->setItem(i, 5, item6);
    }

    m_pTableWidget->resizeColumnsToContents();
    m_pTableWidget->resizeRowsToContents();
}

void chooseFolder()
{
    QString folderPath = QFileDialog::getExistingDirectory(nullptr, "Выберите папку", QDir::homePath());

    QDir dir(folderPath);
    QStringList filters;
    filters << "*.jpg" << "*.jpeg" << "*.png" << "*.bmp"; // добавляем фильтры для графических файлов
    dir.setNameFilters(filters);

    QList<QFileInfo> fileInfoList = dir.entryInfoList();

    m_pTableWidget->setRowCount(fileInfoList.count()); // устанавливаем количество строк в таблице

    int row = 0;
    foreach(QFileInfo fileInfo, fileInfoList)
    {
        QTableWidgetItem *item1 = new QTableWidgetItem(fileInfo.fileName());
        QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(fileInfo.size()));
        //QTableWidgetItem *item3 = new QTableWidgetItem(fileInfo.created().toString());
        QTableWidgetItem *item4;
        QTableWidgetItem *item5;
        QTableWidgetItem *item6;
        QImage image(fileInfo.filePath());
        if(!image.isNull())
        {
            item4 = new QTableWidgetItem(QString::number(image.bitPlaneCount())); // разрешение
            item5 = new QTableWidgetItem(QString::number(image.depth())); // глубина цвета
            if(fileInfo.suffix().toLower() == "bmp" || fileInfo.suffix().toLower() == "pcx")
            {
                item6 = new QTableWidgetItem("N/A");
            }
            else
            {
                double pureSize = image.height() * image.width() * image.bitPlaneCount() / 8;
                int fileSize = fileInfo.size();
                float ratio = (float)((int)(pureSize / fileSize * 100 + 0.5));
                item6 = new QTableWidgetItem(QString::number(ratio / 100));
            }
        }
        else
        {
            item4 = new QTableWidgetItem("");
            item5 = new QTableWidgetItem("");
            item6 = new QTableWidgetItem("");
        }

        m_pTableWidget->setItem(row, 0, item1);
        m_pTableWidget->setItem(row, 1, item2);
        //m_pTableWidget->setItem(row, 2, item3);
        m_pTableWidget->setItem(row, 3, item4);
        m_pTableWidget->setItem(row, 4, item5);
        m_pTableWidget->setItem(row, 5, item6);

        row++;
    }
}

// Реакция на действие по загрузке файлов
// - показываем диалог открытия файлов, позволяем выбрать несколько, возвращаем список выбранных
void chooseFiles()
{
    QStringList fileNames;
    fileNames = QFileDialog::getOpenFileNames(NULL, "Images", ".", "Images (*.jpg *.gif *.tif *.tiff *.bmp *.png *.pcx);;All files (*.*)");
    fillInfo(fileNames);
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget window;
    window.setMinimumSize(800, 300);

    // Таблица, где отображаем данные
    m_pTableWidget = new QTableWidget(&window);
    m_pTableWidget->setRowCount(argc - 1);
    m_pTableWidget->setColumnCount(6);
    m_pTableWidget->setColumnWidth(5, 200); // Устанавливаем ширину первой колонки в 200 пикселей

    QStringList m_TableHeader;
    m_TableHeader << "Название файла" << "Размер(высота)" << "Размер(ширина)" << "Глубина цвета" << "Разрешение" << "Коэффициент сжатия" ;
    m_pTableWidget->setHorizontalHeaderLabels(m_TableHeader);

    // Вверху окна сделаем большую кнопку для загрузки файлов
    QPushButton *m_pBtn = new QPushButton("Load Files", &window);
    QPushButton *m_pBtn1 = new QPushButton("Chose folder", &window);
    QVBoxLayout *l = new QVBoxLayout(&window);
    l->addWidget(m_pBtn);
    l->addWidget(m_pBtn1);
    l->addWidget(m_pTableWidget);

    // Для быстрого тестирования удобно передавать список файлов для отображения в командной строке
    if (argc > 1) {
        QStringList fileNames;
        for (int i = 1; i < argc; i++) {
            fileNames.append(argv[i]);
        }
        fillInfo(fileNames);
    }

    // запретим редактировать таблицу
    m_pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pTableWidget->setShowGrid(true);
    m_pTableWidget->setGeometry(10, 80, 450, 200);

    QObject::connect(m_pBtn, &QPushButton::clicked, qApp, chooseFiles);
    QObject::connect(m_pBtn1, &QPushButton::clicked, qApp, chooseFolder);

    window.show();
    return app.exec();
}
