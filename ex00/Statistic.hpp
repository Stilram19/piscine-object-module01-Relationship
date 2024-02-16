#ifndef STATISTIC_HPP
# define STATISTIC_HPP

# include <iostream>

# define MAX_LEVEL 100

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

        ~Statistic() {
            std::cout << "Statistic destroyed!" << std::endl;
        }

        void levelUp() {
            std::cout << "Worker is ready to level up" << std::endl;
            this->exp++;

            if (this->exp == 100 && this->level < MAX_LEVEL) {
                this->exp = 0;
                this->level++;
            }
        }

        friend std::ostream &operator<<(std::ostream &os, Statistic &stat) {
            os << "level: " << stat.level << ", exp: " << stat.exp << std::endl;
            return (os);
        }
};

#endif
