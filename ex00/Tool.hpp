#ifndef TOOL_HPP
# define TOOL_HPP

# include <iostream>

# define MAX_NUMBER_OF_USES 10000

// for the constraint saying that when a tool is given a worker, it is taken away from
// the worker that has it currently
// it can be resolved if the Tool has a pointer to the worker that has it.

class Tool {
    protected:
        int numberOfUses;
        std::string _type;

    public:
        Tool(const std::string &type) : numberOfUses(0), _type(type) { std::cout << "Tool Constructed!" << std::endl; }
        const std::string &getType() const {
            std::cout << "getType called!" << std::endl;
            return (_type);
        }
        virtual void use() = 0;
        friend std::ostream &operator<<(std::ostream &os, Tool &tool) {
            os << "ToolType: " << tool._type << ", ToolNumberOfUses: " << tool.numberOfUses;
            return (os);
        }
};

#endif
