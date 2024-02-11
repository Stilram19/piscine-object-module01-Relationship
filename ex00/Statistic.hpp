#ifndef STATISTIC_HPP
# define STATISTIC_HPP

# include <iostream>

struct Statistic {
    // attributes
    private:
        int level;
        int exp;

    // constructor & destructor
    public:
        Statistic() : level(0), exp(0) {
            std::cout << "Statistic constructed by default!" << std::endl;
        }

        Statistic(int level, int exp) : level(level), exp(exp) {
            std::cout << "Statistic constructed!" << std::endl;
        }

        ~Statistic() {
            std::cout << "Statistic destroyed!" << std::endl;
        }
};

#endif
