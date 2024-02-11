#ifndef WORKER_HPP
# define WORKER_HPP

# include "Position.hpp"
# include "Statistic.hpp"
# include "Shovel.hpp"
# include "Hammer.hpp"
# include <vector>

class Worker {
    // attributes
    private:
        Position            coordonnee;
        Statistic           stat;
        std::vector<Tool *> tools;

    public:
        Worker();
        ~Worker();
    
    public:
        template <class ToolType>
        Tool *GetTool(ToolType &tool) const {
            for (std::vector<Tool *>::iterator _tool = this->tools.begin(); _tool != this->tools.end(); _tool++) {
                if (tool->getType() == (*_tool)->getType()) {
                    return (_tool);
                }
            }
            return (NULL);
        }
};

#endif
