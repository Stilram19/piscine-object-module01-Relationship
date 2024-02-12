#ifndef SHOVEL_HPP
# define SHOVEL_HPP

# include "Tool.hpp"

struct Shovel : public Tool {
    private:
        int numberOfUses;

    public:
        Shovel() : Tool("Shovel") { std::cout << "Shovel Constructed!" << std::endl; }

        ~Shovel() { std::cout << "Shovel destroyed!" << std::endl; }

        virtual void use() {

            if (this->numberOfUses == MAX_NUMBER_OF_USES) {
                std::cout << "Shovel cannot be used again!" << std::endl;
                return ;
            }
            this->numberOfUses++;
            std::cout << "Shovel being used!" << std::endl;
        }
};

#endif