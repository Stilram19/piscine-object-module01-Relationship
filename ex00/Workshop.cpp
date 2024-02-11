# include "Workshop.hpp"

Workshop::~Workshop() {
    for (std::vector<Worker *>:: const_iterator worker = this->workers.begin(); worker != this->workers.end(); worker++) {
        delete (*worker);        
    }

    std::cout << "Workshop destroyed!" << std::endl;
}

void Workshop::register_worker(Worker *worker) {
    if (worker == NULL) {
        throw std::runtime_error("worker pointer can't be null");
    }

    this->workers.push_back(worker);
    std::cout << "Worker registerd!" << std::endl;
}

void Workshop::release_worker(Worker *worker) {
    for (std::vector<Worker *>::const_iterator w = this->workers.begin(); w != this->workers.end(); w++) {
        if (worker == *w) {
            this->workers.erase(w);
            return ;
        }
    }
    std::cout << "Worker released!" << std::endl;
}
