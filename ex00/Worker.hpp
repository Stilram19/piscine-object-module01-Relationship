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
        Position                   coordonnee;
        Statistic                  stat;
        std::vector<Tool *>        tools;
        std::vector<Workshop *>    workshops;

    public:
        Worker() {
            std::cout << "Worker constructed!" << std::endl;
        }

        ~Worker() {
            std::cout << "Worker destroyed!" << std::endl;
        }

    // methods
    public:
        template <class ToolType>
        Tool *GetTool() const {
            ToolType cmp; // creating an instance of the tool type for comparison purposes.

            for (std::vector<Tool *>::iterator tool = this->tools.begin(); tool != this->tools.end(); tool++) {
                if (cmp->getType() == (*tool)->getType()) {
                    std::cout << "Tool Found!" << std::endl;
                    return (tool);
                }
            }

            std::cout << "Tool Not Found!" << std::endl;
            return (NULL);
        }

        bool has_workshop(Workshop *workshop) {
            for (std::vector<Workshop *>::const_iterator w = this->workshops.begin(); w != this->workshops.end(); w++) {
                if (workshop == *w) {
                    return (true);
                }
            }
            return (false);
        }

        Tool *takeTool(Tool *tool) {
            if (tool == NULL) {
                throw std::runtime_error("Tool cannot be NULL!");
            }
            for (std::vector<Tool *>::const_iterator _tool = this->tools.begin(); _tool != this->tools.end(); _tool++) {
                if (tool == *_tool) {
                    std::cout << "Tool is already in possession of the worker!" << std::endl;
                    return (tool);
                }
            }
            this->tools.push_back(tool);
            std::cout << "New Tool given to worker!" << std::endl;
            return (tool);
        }

        Tool *giveToolBack(Tool *tool) {
            Tool *ret = NULL;

            for (std::vector<Tool *>::const_iterator _tool = this->tools.begin(); _tool != this->tools.end(); _tool++) {
                if (tool == *_tool) {
                    ret = *_tool;
                    this->tools.erase(_tool);
                    std::cout << "Tool taken away from worker!" << std::endl;
                    break ;
                }
            }

            if (ret == NULL) {
                std::cout << "No such tool in possession of the worker!" << std::endl;
                return (NULL);
            }

            // check if a workshop will fire the worker for losing this tool.
            for (std::vector<Workshop *>::const_iterator workshop = this->workshops.begin(); workshop != this->workshops.end(); workshop++) {
                if ((*workshop)->has_necessary_tool(this)) {
                    
                }
            }

            return (ret);
        }

        void apply_for_work(Workshop *workshop) {
            if (workshop == NULL) {
                throw std::runtime_error("workshop can't be NULL!");
            }

            // checking if worker is already registered in the workshop
            if (this->has_workshop(workshop)) {
                std::cout << "Worker is already registered in the workshop!" << std::endl;
                return ;
            }
            std::cout << "worker applied for work!" << std::endl;
            workshop->register_worker(this);
        }

        void leave_workshop(Workshop *workshop) {
            if (workshop == NULL) {
                throw std::runtime_error("workshop can't be NULL!");
            }

            if (this->has_workshop(workshop)) {

            }
        }
};

#endif
