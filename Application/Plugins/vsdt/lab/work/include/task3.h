#ifndef TASK3_H
#define TASK3_H

#include <QDebug>
#include <QQuickItem>
#include <QRegularExpression>

class Task3 : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString inputText READ inputText WRITE setInputText NOTIFY inputTextChanged)
    Q_PROPERTY(QString lastWord READ lastWord WRITE setLastWord NOTIFY lastWordChanged)

public:
    Task3();
    QString lastWord() const;
    QString inputText() const;

public slots:
    void setLastWord(const QString &lastWord);
    void setInputText(const QString &inputText);

signals:
    void lastWordChanged(const QString &lastWord);
    void inputTextChanged(const QString &inputText);

private:
    QString m_lastWord;
    QString m_inputText;

private slots:
    void getLastWordFromInputText(const QString &);
};

#endif // TASK3_H
