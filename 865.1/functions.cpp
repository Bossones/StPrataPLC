#include "remote.hpp"
#include "tv.hpp"
#include <iostream>

// Remote::

bool Remote::tv_on(TV & t) {
    t.onoff = TV::On;
    return true;
}

bool Remote::tv_off(TV & t) {
    t.onoff = TV::Off;
    return true;
}

void Remote::re_mode(TV & t) {
    if (mode == Normal) {
        mode = Interactive;
        t.mode = TV::Interactive;
    } else {
        mode = Normal;
        t.mode = TV::Normal;
    }
}

void Remote::re_connection(TV & t) {
    int set = 0;
    std::cout << "Change the connection: " << std::endl;
    std::cout << "0 - NOPE, 1 - HDMI, 2 - DVI, 3 - VGA" << std::endl;
    std::cin >> set;
    while (set > 3 || set < 0) {
        std::cout << "Error. Please, enter again: ";
        std::cin >> set;
    }
    switch (set)
    {
    case 0:
        connection = NOPE;
        t.connection = TV::NOPE;
        break;
    case 1:
        connection = HDMI;
        t.connection = TV::HDMI;
        break;
    case 2:
        connection = DVI;
        t.connection = TV::DVI;
        break;
    case 3:
        connection = VGA;
        t.connection = TV::VGA;
        break;
    }
}

bool Remote::volup(TV & t) {
    if (t.volume == TV::VOLMAX)
        return false;
    t.volume++;
    return true;
}

bool Remote::voldown(TV & t) {
    if (t.volume == TV::VOLMIN)
        return false;
    t.volume--;
    return true;
}

void Remote::chanup(TV & t) {
    if (t.channel == TV::CHMAX)
        t.channel = TV::CHMIN;
    else
        t.channel++;
}

void Remote::chandown(TV & t) {
    if (t.channel == TV::CHMIN)
        t.channel = TV::CHMAX;
    else
        t.channel--;
}

void Remote::set_channel(TV & t, const int & ch) {
    if (ch > TV::CHMAX)
        t.channel = 1;
    else
        t.channel = ch;
}

void Remote::set_volume(TV & t, const int & vol) {
    if (vol < TV::VOLMAX)
        t.volume = vol;
}

// TV::
void TV::inc() {
    onoff == Off ? onoff = On : onoff = Off;
}

void TV::re_mode(const int & m) {
    mode = m;
}

void TV::re_connection(const int & con) {
    connection = con;
}

void TV::rem(Remote & rem) const {
    rem.connection = connection;
    rem.mode = mode;
}

bool TV::set_chan(const int & ch) {
    if (ch > CHMAX)
        return false;
    channel = ch;
    return true;
}

bool TV::volup() {
    if (volume == VOLMAX)
        return false;
    volume++;
    return true;
}

bool TV::voldown() {
    if (volume == VOLMIN)
        return false;
    volume--;
    return true;
}

void TV::chanup() {
    channel == CHMAX ? channel = CHMIN : channel++;
}

void TV::chandown() {
    channel == CHMIN ? channel = CHMAX : channel--;
}

void TV::settings() {
    int set;
    using std::cout;
    using std::endl;
    using std::cin;
    cout << "Settings for TV:" << endl;
    cout << "Change mode - 0. Set channel - 1. Change remote - 2. Change connection - 3" << endl;
    cin >> set;
    switch (set) {
        case 3: cout << "Enter connection: ";
                cout << "0 - NOPE, 1 - HDMI, 2 - DVI, 3 - VGA" << endl;
                cin >> set;
                while (set > 3 || set < 0) {
                    cout << "Error. Please, enter again: ";
                    cin >> set;
                }
                re_connection(set);
                break;
        case 1: cout << "Enter channel: ";
                cin >> set;
                set_chan(set);
                break;
        case 0: cout << "Enter mode: ";
                cout << "0 - Normal, 1 - Interactive" << endl;
                cin >> set;
                while (set > 1 || set < 0) {
                    cout << "Error. Please, enter again: ";
                    cin >> set;
                }
                re_mode(set);
                break;
        case 2:  cout << "Changing..." << endl; break;
    }
}

