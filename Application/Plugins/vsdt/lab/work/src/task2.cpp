#include "task2.h"

Task2::Task2()
{
    QObject::connect(this,
                     SIGNAL(inputTextChanged(const QString &)),
                     this,
                     SLOT(checkInputText(const QString &)));
}

QString Task2::inputText() const
{
    return m_inputText;
}

bool Task2::isInputTextCorrect() const
{
    return m_isInputTextCorrect;
}

void Task2::setInputText(const QString &inputText)
{
    if (m_inputText == inputText)
        return;

    m_inputText = inputText;
    emit inputTextChanged(m_inputText);
}

void Task2::setIsInputTextCorrect(const bool &isInputTextCorrect)
{
    if (m_isInputTextCorrect == isInputTextCorrect)
        return;

    m_isInputTextCorrect = isInputTextCorrect;
    emit isInputTextCorrectChanged(m_isInputTextCorrect);
}

void Task2::checkInputText(const QString &inputText)
{
    if (inputText.size() > 1) {
        for (int i = 0; i < inputText.size() - 1; i++) {
            QChar currentLetter = inputText[i];
            QChar nextLetter = inputText[i + 1];
            if (isRequiredFirstLetter(currentLetter) && !isCorrectSecondLetter(nextLetter)) {
                setIsInputTextCorrect(false);
                break;
            }
        }
    }
}

bool Task2::isCorrectSecondLetter(const QChar &secondLetter)
{
    QChar correctLetter = QString("а")[0];
    bool result = secondLetter == correctLetter;
    return result;
}

bool Task2::isRequiredFirstLetter(const QChar &firstLetter)
{
    QString requiredLetters = "чщ";
    bool result = firstLetter == requiredLetters[0] || firstLetter == requiredLetters[1];
    return result;
}
