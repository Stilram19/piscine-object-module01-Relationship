# include "Position.hpp"

Position::Position() : x(0), y(0), z(0) {
    std::cout << "Position constructed by default!" << std::endl;
}

Position::Position(int x, int y, int z) : x(x), y(y), z(z) {
    std::cout << "Position constructed!" << std::endl;
}

Position::~Position() {
    std::cout << "Position destroyed!" << std::endl;
}
