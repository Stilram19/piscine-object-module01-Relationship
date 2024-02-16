# include "Workshop.hpp"

Workshop::Workshop() : necessary_tool_type("Shovel") {
    std::cout << "Workshop constructed, necessary tool is Shovel!" << std::endl;
}

Workshop::Workshop(const std::string &necessary_tool) {
    if (necessary_tool != "Shovel" && necessary_tool != "Hammer") {
        throw std::runtime_error("necessary tool can be either Shovel or Hammer!");
    }
    std::cout << "Workshop constructed, necessary tool is " << necessary_tool << "!" << std::endl;
}

Workshop::~Workshop() {
    std::cout << "Workshop destroyed!" << std::endl;
}

bool Workshop::has_worker(Worker *worker) const {
    std::cout << "has_worker called!" << std::endl;
    for (const_worker_iterator w = this->workers.begin(); w != this->workers.end(); w++) {
        if (worker == *w) {
            return (true);
        }
    }
    return (false);
}

Tool *Workshop::get_necessary_tool(Worker *worker) const {
    std::cout << "get_necessary_tool called!" << std::endl;
    Tool *ret = worker->GetTool<Hammer>();

    if (this->necessary_tool_type == "Shovel") {
        ret = worker->GetTool<Shovel>();
    }
    return (ret);
}

bool Workshop::register_worker(Worker *worker) {
    if (worker == NULL) {
        throw std::runtime_error("worker can't be null");
    }

    if (this->has_worker(worker)) {
        std::cout << "Worker already registered" << std::endl;
        return (true);
    }

    // check if worker has necessary tool
    if (this->get_necessary_tool(worker) == NULL) {
        std::cout << "Worker hasn't necessary tool!" << std::endl;
        return (false);
    }

    this->workers.push_back(worker);
    std::cout << "Worker registered!" << std::endl;

    // just to make sure that the worker adds the workshop to his list, if this function
    // was called from somewhere else than worker::apply_for_work();
    worker->apply_for_work(this);

    return (true);
}

void Workshop::release_worker(Worker *worker) {
    if (worker == NULL) {
        throw std::runtime_error("worker can't be NULL!");
    }

    if (!this->has_worker(worker)) {
        std::cout << "Workshop doesn't have such a worker!" << std::endl;
        return ;
    }

    for (worker_iterator w = this->workers.begin(); w != this->workers.end(); w++) {
        if (worker == *w) {
            this->workers.erase(w);
            worker->leave_workshop(this);
            std::cout << "Worker released!" << std::endl;
            break ;
        }
    }
}

void Workshop::executeWorkDay() {
    if (this->workers.size() != 0) {
        std::cout << "Launching the work day!" << std::endl;
    }

    for (worker_iterator worker = this->workers.begin(); worker != this->workers.end(); worker++) {
        (*worker)->work(this);
    }
}

std::ostream &operator<<(std::ostream &os, Workshop &workshop) {
    os << "**********WORKSHOP**********" << std::endl;
    os << "Workshop necessary tool: " << workshop.necessary_tool_type << std::endl;
    os << "Workers: <<< ";
    for (Workshop::worker_iterator worker = workshop.workers.begin(); worker != workshop.workers.end(); worker++) {
       os << (**worker);
        if (worker + 1 != workshop.workers.end())
            os << ", ";
    }
    os << " >>>" << std::endl;
    return (os);
}
