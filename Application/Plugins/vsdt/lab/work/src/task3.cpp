#include "task3.h"

Task3::Task3()
{
    QObject::connect(this,
                     SIGNAL(inputTextChanged(const QString &)),
                     this,
                     SLOT(getLastWordFromInputText(const QString &)));
}

QString Task3::lastWord() const
{
    return m_lastWord;
}

QString Task3::inputText() const
{
    return m_inputText;
}

void Task3::getLastWordFromInputText(const QString &inputText)
{
    QString lastWord = "";
    QRegularExpression regExp("\\w+", QRegularExpression::UseUnicodePropertiesOption);
    QRegularExpressionMatch match;
    QRegularExpressionMatchIterator matchIter = regExp.globalMatch(inputText);
    while (matchIter.hasNext())
        match = matchIter.next();
    if (match.hasMatch()) {
        lastWord = match.captured(match.lastCapturedIndex());
        qDebug() << "last word:" << lastWord;
    }
    setLastWord(lastWord);
}

void Task3::setLastWord(const QString &lastWord)
{
    if (m_lastWord == lastWord)
        return;

    m_lastWord = lastWord;
    emit lastWordChanged(m_lastWord);
}

void Task3::setInputText(const QString &inputText)
{
    if (m_inputText == inputText)
        return;

    m_inputText = inputText;
    emit inputTextChanged(m_inputText);
}
