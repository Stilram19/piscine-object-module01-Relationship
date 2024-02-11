#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include <vector>
# include "Worker.hpp"

class Workshop {
    private:
        std::vector<Worker *> workers;

    public:
        ~Workshop();

    public:    
        void register_worker(Worker *worker);
        void release_worker(Worker *worker);
};

#endif
