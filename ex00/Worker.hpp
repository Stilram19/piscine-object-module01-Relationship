#ifndef WORKER_HPP
# define WORKER_HPP

# include "my_header.hpp"
# include "Workshop.hpp"

class Worker {
    private:
        Position                   coordonnee;
        Statistic                  stat;
        std::vector<Tool *>        tools;
        std::vector<Workshop *>    workshops;

        //types
        typedef std::vector<Tool *>::const_iterator tool_iterator;
        typedef std::vector<Workshop *>::const_iterator workshop_iterator;

    public:
        Worker();
        ~Worker();

    // methods
    public:
        template <class ToolType>
        Tool *GetTool() const {
            ToolType cmp; // creating an instance of the tool type for comparison purposes.

            for (tool_iterator tool = this->tools.begin(); tool != this->tools.end(); tool++) {
                if (cmp->getType() == (*tool)->getType()) {
                    std::cout << "Tool Found!" << std::endl;
                    return (tool);
                }
            }

            std::cout << "Tool Not Found!" << std::endl;
            return (NULL);
        }

    private:
        bool has_workshop(Workshop *workshop);

    public:
        Tool *takeTool(Tool *tool);
        Tool *giveToolBack(Tool *tool);
        void apply_for_work(Workshop *workshop);
        void leave_workshop(Workshop *workshop);
        void work(Workshop *workshop);
};

#endif
