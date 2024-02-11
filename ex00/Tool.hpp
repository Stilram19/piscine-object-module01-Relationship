#ifndef TOOL_HPP
# define TOOL_HPP

# include <iostream>

# define MAX_NUMBER_OF_USES 10000

class Tool {
    protected:
        std::string _type;

    public:
        Tool(const std::string &type) : _type(type) { std::cout << "Tool Constructed!" << std::endl; }
        const std::string &getType() {
            std::cout << "getType called!" << std::endl;
            return (_type);
        }
        virtual void use() = 0;
};

#endif