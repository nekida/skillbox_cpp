#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

static constexpr int numTracks = 5;

static std::string nameSongs[] = { "April", "Hurts", "Drop", "Bublicki", "Former" };
static size_t duration[] = {180, 123, 222, 450, 349};
static std::tm date[] = {
    {
        .tm_mon = 11,
        .tm_year = 2000
    },
    {
        .tm_mon = 5,
        .tm_year = 1990
    },
    {
        .tm_mon = 7,
        .tm_year = 1980
    },
    {
        .tm_mon = 2,
        .tm_year = 1999
    },
    {
        .tm_mon = 7,
        .tm_year = 1980
    }
};

class Track {
    std::string name;
    std::tm date;
    size_t durationInSec;
    bool flagPlayed, flagPause, flagStopped;

public:
    std::string& getName() { return name; }
    std::tm& gatDate() { return date; }
    size_t& getDurationInSec() { return durationInSec; };
    bool& isPlayed() { return flagPlayed; }
    bool& isPause() { return flagPause; }
    bool& isStopped() { return flagStopped; };
};

class Player {
    std::vector<Track> tracks;

public:
    Player();

    void play();

    void pause();

    void next();

    void stop();
};

Player::Player ()
{
    for (int i = 0; i < numTracks; ++i) {
        Track track;
        track.getName() = nameSongs[i];
        track.gatDate() = date[i];
        track.getDurationInSec() = duration[i];
        track.isPlayed() = false;
        track.isPause() = false;
        track.isStopped() = false;
        tracks.push_back(track);
    }
}

void Player::play()
{
    std::cout << "Enter the name of track" << std::endl;
    std::string name;
    std::cin >> name;
    bool isFinded = false;
    for (auto& track : tracks) {
        if (name == track.getName()) {
            if (!track.isPlayed()) {
                std::cout << "Playing the track: " << track.getName() << std::endl;
                std::cout << "Date creating of the the track: " << track.gatDate().tm_year << " year " << track.gatDate().tm_mon << " month" << std::endl;
                std::cout << "Duration of the track: " << track.getDurationInSec() << std::endl;
                track.isPlayed() = true;
            }
            isFinded = true;
        } else
            track.isPlayed() = false;
        track.isPause() = false;
        track.isStopped() = false;
    }
    if (!isFinded)
        std::cout << "No such track" << std::endl;
}

void Player::pause()
{
    for (auto& track : tracks) {
        if (track.isPlayed() && !track.isPause()) {
            std::cout << "The track: " << track.getName() << " is pause" << std::endl;
            track.isPlayed() = false;
            track.isPause() = true;
            track.isStopped() = false;
        }
    }
}

void Player::stop()
{
    for (auto& track : tracks) {
        if ((track.isPlayed() || track.isPause()) && !track.isStopped()) {
            std::cout << "The track: " << track.getName() << " is stopped" << std::endl;
            track.isPlayed() = false;
            track.isPause() = false;
            track.isStopped() = true;
        }
    }
}

void Player::next()
{
    int num = rand() % 5;
    for (int i = 0; i < tracks.size(); ++i) {
        if (i == num) {
            std::cout << "Playing the track: " << tracks[i].getName() << std::endl;
            std::cout << "Date creating of the the track: " << tracks[i].gatDate().tm_year << " year " << tracks[i].gatDate().tm_mon << " month" << std::endl;
            std::cout << "Duration of the track: " << tracks[i].getDurationInSec() << std::endl;
            tracks[i].isPlayed() = true;
        } else
            tracks[i].isPlayed() = false;
        tracks[i].isPause() = false;
        tracks[i].isStopped() = false;
    }
}

int main ()
{
    Player player;
    std::cout << "Enter the command" << std::endl;
    std::string cmd;
    std::cin >> cmd;

    while (cmd != "exit") {
        if (cmd == "play")
            player.play();
        else if (cmd == "pause")
            player.pause();
        else if (cmd == "next")
            player.next();
        else if (cmd == "stop")
            player.stop();
        else
            std::cout << "Unsupported command" << std::endl;

        std::cout << "Enter the command" << std::endl;
        std::cin >> cmd;
    }

    return 0;
}
