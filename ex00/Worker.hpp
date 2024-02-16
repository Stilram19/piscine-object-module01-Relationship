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
        typedef std::vector<Tool *>::iterator tool_iterator;
        typedef std::vector<Workshop *>::iterator workshop_iterator;
        typedef std::vector<Tool *>::const_iterator const_tool_iterator;
        typedef std::vector<Workshop *>::const_iterator const_workshop_iterator;

    public:
        Worker();
        ~Worker();

    // methods
    public:
        template <class ToolType>
        Tool *GetTool() const {
            std::cout << "GetTool called!" << std::endl;
            ToolType cmp; // creating an instance of the tool type for comparison purposes.

            for (const_tool_iterator tool = this->tools.begin(); tool != this->tools.end(); tool++) {
                if (cmp.getType() == (*tool)->getType()) {
                    std::cout << "Tool Found!" << std::endl;
                    return (*tool);
                }
            }

            std::cout << "Tool Not Found!" << std::endl;
            return (NULL);
        }
    
    private:
        bool has_workshop(Workshop *workshop) const;

    public:
        Tool *takeTool(Tool *tool);
        Tool *giveToolBack(Tool *tool);
        void apply_for_work(Workshop *workshop);
        void leave_workshop(Workshop *workshop);
        void work(Workshop *workshop);
        friend std::ostream &operator<<(std::ostream &os, Worker &worker);
};

#endif
