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
        Position() : x(0), y(0), z(0) {
            std::cout << "Position constructed by default!" << std::endl;
        }

        Position(int x, int y, int z) : x(x), y(y), z(z) {
            std::cout << "Position constructed!" << std::endl;
        }

        ~Position() {
            std::cout << "Position destroyed!" << std::endl;
        }
};

#endif
