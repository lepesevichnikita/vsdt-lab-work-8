#ifndef TASK1_H
#define TASK1_H

#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QRegularExpression>
#include <QUrl>

class Task1 : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sourceText READ sourceText WRITE setSourceText NOTIFY sourceTextChanged)
    Q_PROPERTY(QString resultText READ resultText WRITE setResultText NOTIFY resultTextChanged)
    Q_PROPERTY(QUrl outputFilePath READ outputFilePath WRITE setOutputFilePath NOTIFY
                   outputFilePathChanged)

public:
    explicit Task1(QObject *parent = nullptr);

    QString sourceText() const;
    QString resultText() const;
    QUrl outputFilePath() const;

    Q_INVOKABLE void writeResultToFile();

signals:

    void sourceTextChanged(const QString &sourceText);
    void resultTextChanged(const QString &resultText);
    void outputFilePathChanged(const QUrl &outputFilePath);

public slots:

    void setSourceText(const QString &sourceText);
    void setResultText(const QString &resultText);
    void setOutputFilePath(const QUrl &outputFilePath);

private:
    QString m_sourceText;
    QString m_resultText;
    QUrl m_outputFilePath;

    void replaceRefByWord(QString &, const QStringRef &, const QString &);
    QString replaceTwoWordsInSentence(const QString &, const int &, const int &);

private slots:
    void calculateResult(const QString &);
};

#endif // TASK1_H
