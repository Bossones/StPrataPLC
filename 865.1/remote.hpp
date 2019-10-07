#ifndef REMOTE_HPP__
#define REMOTE_HPP__
#include "tv.hpp"

/*class TV {
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
}; */

class Remote {
private:
    friend class TV;
    enum {Normal, Interactive};
    enum {NOPE, HDMI, DVI, VGA};
    int mode;
    int connection;

public:
    Remote(TV & t) {
        mode = t.mode;
        connection = t.connection;
    }

    Remote() {
        mode = Normal;
        connection = NOPE;
    }

    bool tv_on(TV & t);
    bool tv_off(TV & t);
    void re_mode(TV & t);
    void re_connection(TV & t);
    bool volup(TV & t);
    bool voldown(TV & t);
    void chanup(TV & t);
    void chandown(TV & t);
    void set_channel(TV & t, const int & ch);
    void set_volume(TV & t, const int & vol);


};

#endif