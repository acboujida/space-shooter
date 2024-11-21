#include "soundmanager.h"

SoundManager* SoundManager::instance = nullptr;
QMutex SoundManager::mutex;

SoundManager::SoundManager(QObject* parent) :
    QObject(parent),
    backgroundMusicPlayer(new QMediaPlayer(this)),
    backgroundMusicAudio(new QAudioOutput(this)) {

    backgroundMusicPlayer->setAudioOutput(backgroundMusicAudio);
}

SoundManager* SoundManager::getInstance(QObject* parent) {
    QMutexLocker locker(&mutex);
    if (!instance)
        instance = new SoundManager(parent);

    return instance;
}

void SoundManager::playBackgroundMusic(const QUrl &path) {
    backgroundMusicPlayer->setSource(path);
    backgroundMusicAudio->setVolume(100);
    backgroundMusicPlayer->setLoops(QMediaPlayer::Infinite);
    backgroundMusicPlayer->play();
}

void SoundManager::playSoundEffect(const QUrl &path) {
    QMediaPlayer* soundEffectPlayer = new QMediaPlayer(this);
    QAudioOutput* soundEffectAudio = new QAudioOutput(this);
    soundEffectPlayer->setAudioOutput(soundEffectAudio);
    soundEffectPlayer->setSource(path);
    soundEffectAudio->setVolume(50);
    soundEffectPlayer->setLoops(1);
    soundEffectPlayer->play();

    connect(soundEffectPlayer, &QMediaPlayer::playbackStateChanged, this, [=](QMediaPlayer::PlaybackState state) {
        if (state == QMediaPlayer::StoppedState) {
            delete soundEffectAudio;
            delete soundEffectPlayer;
        }
    });
}
