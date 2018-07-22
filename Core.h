//
// Created by hugo on 22/07/18.
//

#ifndef INVADER_CORE_H
#define INVADER_CORE_H


class Core {

private:

public:
    Core();
    ~Core();

    bool initMap();
    bool initPlayers();
    void startGame();
};


#endif //INVADER_CORE_H
