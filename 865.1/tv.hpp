#ifndef TV_HPP__
#define TV_HPP__

#include "remote.hpp"

class Remote;

class TV {
private:
    friend class Remote;
    enum {Normal, Interactive};
    enum {NOPE, HDMI, DVI, VGA};
    enum {VOLMIN, VOLMAX = 100};
    enum {CHMIN = 1, CHMAX = 125};
    enum {On, Off};
    int volume;
    int channel;
    int mode;
    int connection;
    int onoff;

    void re_mode(const int & m);
    void re_connection(const int & con);

    bool set_chan(const int & ch);
public:
    TV() {
        volume = 0;
        channel = 1;
        mode = Normal;
        connection = NOPE;
        onoff = Off;
    }

    void inc();
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void settings();
    void rem(Remote & rem) const;
};

#endif