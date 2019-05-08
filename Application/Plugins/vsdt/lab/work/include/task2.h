#ifndef TASK2_H
#define TASK2_H

#include <QQuickItem>
#include <QRegularExpression>

class Task2 : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString inputText READ inputText WRITE setInputText NOTIFY inputTextChanged)
    Q_PROPERTY(bool isInputTextCorrect READ isInputTextCorrect WRITE setIsInputTextCorrect NOTIFY
                   isInputTextCorrectChanged)
public:
    Task2();

    QString inputText() const;
    bool isInputTextCorrect() const;

signals:
    void inputTextChanged(const QString &);
    void isInputTextCorrectChanged(const bool &);

public slots:
    void setInputText(const QString &);
    void setIsInputTextCorrect(const bool &);
    void checkInputText(const QString &);

private:
    QString m_inputText;
    bool m_isInputTextCorrect;

    bool isCorrectSecondLetter(const QChar &);
    bool isRequiredFirstLetter(const QChar &);
};

#endif // TASK2_H
