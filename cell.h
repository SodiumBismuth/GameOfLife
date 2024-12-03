#ifndef CELL_H
#define CELL_H

class Cell {
private:
    int state; // 0 pour morte, 1 pour vivante

public:
    Cell();
    void set_state(int s);
    int get_state() const;
};

#endif