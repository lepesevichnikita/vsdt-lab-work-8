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
    QString sentencePattern = QString::fromLatin1("(\\.|\\?|\\!)+(\\s|\\W)*");
    QRegularExpression regExpSentence(sentencePattern);
    QStringList sentences = sourceText.split(regExpSentence);
    for (auto sentence : sentences)
        if (sentences.count() >= 2) {
            QString requiredSentence = sentences[1];
            int sentencePos = result.indexOf(sentences[1]);
            QString processedSentence = replaceTwoWordsInSentence(sentences[1], 1, 2);
            result = result.replace(sentencePos, processedSentence.length(), processedSentence);
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
    QStringList words = result.split(' ');
    if (words.count() >= secondWordPos) {
        QString firstTempWord = words[firstWordPos];
        QString secondTempWord = words[secondWordPos];
        words.replace(firstWordPos, secondTempWord);
        words.replace(secondWordPos, firstTempWord);
        result = words.join(' ');
    }
    return result;
}
