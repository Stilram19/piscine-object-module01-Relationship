#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include <vector>
# include "Worker.hpp"

class Workshop {
    private:
        std::string             necessary_tool_type;
        std::vector<Worker *>   workers;

    // Destructor
    public:
        ~Workshop() {
            for (std::vector<Worker *>:: const_iterator worker = this->workers.begin(); worker != this->workers.end(); worker++) {
                delete (*worker);        
            }

            std::cout << "Workshop destroyed!" << std::endl;
        }

    // methods
    public:
        bool has_necessary_tool(Worker *worker) {
            Tool *ret = NULL;

            if (this->necessary_tool_type == "Hammer") {
                ret = worker->GetTool<Hammer>();
            }

            if (this->necessary_tool_type == "Shovel") {
                ret = worker->GetTool<Shovel>();
            }
            return (ret != NULL);
        }

        void register_worker(Worker *worker) {
            if (worker == NULL) {
                throw std::runtime_error("worker can't be null");
            }

            for (std::vector<Worker *>::const_iterator w = this->workers.begin(); w != this->workers.end(); w++) {
                if (worker == *w) {
                    std::cout << "Worker already registered" << std::endl;
                    return ;
                }
            }

            // check if worker has necessary tool

            if (this->has_necessary_tool(worker) == false) {
                std::cout << "Worker hasn't necessary tool!" << std::endl;
                return ;
            }

            this->workers.push_back(worker);
            std::cout << "Worker registerd!" << std::endl;
        }

        void release_worker(Worker *worker) {
            if (worker == NULL) {
                throw std::runtime_error("worker can't be NULL!");
            }
            for (std::vector<Worker *>::const_iterator w = this->workers.begin(); w != this->workers.end(); w++) {
                if (worker == *w) {
                    this->workers.erase(w);
                    std::cout << "Worker released!" << std::endl;
                    return ;
                }
            }
        }
};

#endif
