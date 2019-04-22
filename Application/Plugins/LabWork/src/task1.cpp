#include "task1.h"

Task1::Task1(QObject *parent)
    : QObject(parent)
{
    QObject::connect(this,
                     SIGNAL(sourceTextChanged(const QString &)),
                     this,
                     SLOT(calculateResult(const QString &)));
}

QString Task1::sourceText() const
{
    return m_sourceText;
}

QString Task1::resultText() const
{
    return m_resultText;
}

QUrl Task1::outputFilePath() const
{
    return m_outputFilePath;
}

void Task1::writeResultToFile()
{
    QFile fout(m_outputFilePath.toLocalFile());
    if (fout.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QDataStream out(&fout);
        out << m_resultText;
        fout.flush();
    }
}

void Task1::calculateResult(const QString &sourceText)
{
    QString result = sourceText;
    QRegularExpression regExpSentence("\\b((?!=|\\!|\?|\\.).)+(.)\\b");
    QRegularExpressionMatch match = regExpSentence.match(sourceText);
    if (match.hasMatch()) {
        QStringRef sentence = match.capturedRef(2);
        QString sentenceCopy = (*sentence.string());
        if (!sentence.isEmpty()) {
            sentenceCopy = replaceTwoWordsInSentence(sentenceCopy, 2, 3);
        }
        replaceRefByWord(result, sentence, sentenceCopy);
    }
    setResultText(result);
}

void Task1::setSourceText(const QString &sourceText)
{
    if (m_sourceText == sourceText)
        return;

    m_sourceText = sourceText;
    emit sourceTextChanged(m_sourceText);
}

void Task1::setResultText(const QString &resultText)
{
    if (m_resultText == resultText)
        return;

    m_resultText = resultText;
    emit resultTextChanged(m_resultText);
}

void Task1::setOutputFilePath(const QUrl &outputFilePath)
{
    if (m_outputFilePath == outputFilePath)
        return;

    m_outputFilePath = outputFilePath;
    emit outputFilePathChanged(m_outputFilePath);
}

void Task1::replaceRefByWord(QString &sourceText,
                             const QStringRef &replacedRef,
                             const QString &after)
{
    sourceText.replace(replacedRef.position(), replacedRef.length(), after);
}

QString Task1::replaceTwoWordsInSentence(const QString &sourceText,
                                         const int &firstWordPos,
                                         const int &secondWordPos)
{
    QString result = sourceText;
    QRegularExpression regExpWord("\\w+");
    QRegularExpressionMatch wordMatch = regExpWord.match(result);
    if (wordMatch.hasMatch()) {
        QStringRef firstWordRef = wordMatch.capturedRef(firstWordPos);
        if (!firstWordRef.isEmpty()) {
            QString firstWordCopy = *firstWordRef.string();
            QString secondWord = wordMatch.captured(secondWordPos);
            if (!secondWord.isEmpty()) {
                replaceRefByWord(result, firstWordRef, secondWord);
                wordMatch = regExpWord.match(result);
                if (wordMatch.hasMatch()) {
                    QStringRef secondWordRef = wordMatch.capturedRef(secondWordPos);
                    replaceRefByWord(result, secondWordRef, firstWordCopy);
                }
            }
        }
    }
    return result;
}
