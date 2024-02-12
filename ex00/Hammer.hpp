#ifndef HAMMER_HPP
# define HAMMER_HPP

# include "Tool.hpp"

struct Hammer : public Tool {
    private:
        int numberOfUses;

    public:
        Hammer() : Tool("Hammer") { std::cout << "Hammer Constructed!" << std::endl; }

        ~Hammer() { std::cout << "Hammer destroyed!" << std::endl; }

        virtual void use() {

            if (this->numberOfUses == MAX_NUMBER_OF_USES) {
                std::cout << "Hammer cannot be used again!" << std::endl;
                return ;
            }
            this->numberOfUses++;
            std::cout << "Hammer being used!" << std::endl;
        }
};

#endif