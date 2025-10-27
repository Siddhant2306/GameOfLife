#pragma once
#include <vector>

class Cell {
private:
    bool alive;      // current state
    bool nextAlive;  // state for next generation

public:
    Cell() : alive(false), nextAlive(false) {}

    bool isAlive() const { return alive; }
    void setAlive(bool state) { alive = state; }

    void computeNextState(int liveNeighbors) {
        if (alive)
            nextAlive = (liveNeighbors == 2 || liveNeighbors == 3);
        else
            nextAlive = (liveNeighbors == 3);
    }
   
    void update() { alive = nextAlive; }
};
