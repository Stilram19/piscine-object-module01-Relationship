#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include <vector>
# include "Worker.hpp"

class Workshop {
    private:
        std::string             necessary_tool_type;
        std::vector<Worker *>   workers;

        // types
        typedef std::vector<Worker *>::const_iterator worker_iterator;

    // Destructor
    public:
        ~Workshop() {
            for (worker_iterator worker = this->workers.begin(); worker != this->workers.end(); worker++) {
                delete (*worker);        
            }

            std::cout << "Workshop destroyed!" << std::endl;
        }

    // methods
    public:
        Tool *get_necessary_tool(Worker *worker) {
            Tool *ret = worker->GetTool<Hammer>();

            if (this->necessary_tool_type == "Shovel") {
                ret = worker->GetTool<Shovel>();
            }
            return (ret);
        }

        void register_worker(Worker *worker) {
            if (worker == NULL) {
                throw std::runtime_error("worker can't be null");
            }

            for (worker_iterator w = this->workers.begin(); w != this->workers.end(); w++) {
                if (worker == *w) {
                    std::cout << "Worker already registered" << std::endl;
                    return ;
                }
            }

            // check if worker has necessary tool

            if (this->get_necessary_tool(worker) == NULL) {
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
            for (worker_iterator w = this->workers.begin(); w != this->workers.end(); w++) {
                if (worker == *w) {
                    this->workers.erase(w);
                    worker->leave_workshop(this);
                    std::cout << "Worker released!" << std::endl;
                    return ;
                }
            }
        }

        void executeWorkDay() {
            if (this->workers.size() != 0) {
                std::cout << "Launching the work day!" << std::endl;
            }

            for (worker_iterator worker = this->workers.begin(); worker != this->workers.end(); worker++) {
                (*worker)->work(this);
            }
        }
};

#endif
