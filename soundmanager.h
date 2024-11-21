#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMutex>

class SoundManager : public QObject {
    Q_OBJECT

    static SoundManager* instance;
    static QMutex mutex;

    QMediaPlayer* backgroundMusicPlayer;
    QAudioOutput* backgroundMusicAudio;

    SoundManager(QObject* = nullptr);
public:
    static SoundManager* getInstance(QObject* = nullptr);
    void playBackgroundMusic(const QUrl&);
    void playSoundEffect(const QUrl&);
};

#endif // SOUNDMANAGER_H
