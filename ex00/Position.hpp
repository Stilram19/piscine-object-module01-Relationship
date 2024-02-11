#ifndef POSITION_HPP
# define POSITION_HPP

# include <iostream>

struct Position {
    // attributes
    private:
        int x;
        int y;
        int z;

    // Constructor & Destructor
    public:
        Position();
        Position(int x, int y, int z);
        ~Position();

};

#endif
