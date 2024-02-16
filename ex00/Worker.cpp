# include "Worker.hpp"

// Constructor & Destructor

Worker::Worker() {
    std::cout << "Worker constructed!" << std::endl;
}

Worker::~Worker() {
    std::cout << "Worker destroyed!" << std::endl;
}

// Methods

bool Worker::has_workshop(Workshop *workshop) const {
    std::cout << "has_workshop called!" << std::endl;
    for (const_workshop_iterator w = this->workshops.begin(); w != this->workshops.end(); w++) {
        if (workshop == *w) {
            return (true);
        }
    }
    return (false);
}

Tool *Worker::takeTool(Tool *tool) {
    if (tool == NULL) {
        throw std::runtime_error("Tool cannot be NULL!");
    }

    for (tool_iterator _tool = this->tools.begin(); _tool != this->tools.end(); _tool++) {
        if (tool == *_tool) {
            std::cout << "Tool is already in possession of the worker!" << std::endl;
            return (tool);
        }
    }

    this->tools.push_back(tool);
    std::cout << "New Tool given to worker!" << std::endl;
    return (tool);
}

Tool *Worker::giveToolBack(Tool *tool) {
    Tool *ret = NULL;

    if (tool == NULL) {
        throw std::runtime_error("Tool can't be NULL!");
    }

    for (tool_iterator _tool = this->tools.begin(); _tool != this->tools.end(); _tool++) {
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
    for (workshop_iterator workshop = this->workshops.begin(); workshop != this->workshops.end(); workshop++) {
        if (!(*workshop)->get_necessary_tool(this)) {
            this->leave_workshop(*workshop);
            workshop--;
        }
    }

    return (ret);
}

void Worker::apply_for_work(Workshop *workshop) {
    if (workshop == NULL) {
        throw std::runtime_error("workshop can't be NULL!");
    }

    // checking if worker is already registered in the workshop
    if (this->has_workshop(workshop)) {
        std::cout << "Worker is already registered in the workshop!" << std::endl;
        return ;
    }

    this->workshops.push_back(workshop);
    std::cout << "worker applied for work! " << std::endl;

    if (workshop->register_worker(this) == false) {
        this->workshops.pop_back();
        std::cout << "worker got rejected!" << std::endl;
        return ;
    }

    std::cout << "worker got accepted!" << std::endl;
}

void Worker::leave_workshop(Workshop *workshop) {
    if (workshop == NULL) {
        throw std::runtime_error("workshop can't be NULL!");
    }

    if (!this->has_workshop(workshop)) {
        std::cout << "worker doesn't work for this workshop!" << std::endl;
        return ;
    }

    for (workshop_iterator w = this->workshops.begin(); w != this->workshops.end(); w++) {
        if (workshop == *w) {
            this->workshops.erase(w);
            std::cout << "worker left the workshop!" << std::endl;
            workshop->release_worker(this);
            break ;
        }
    }
}

void Worker::work(Workshop *workshop) {
    if (workshop == NULL) {
        throw std::runtime_error("workshop can't be NULL!");
    }

    if (!this->has_workshop(workshop)) {
        throw std::runtime_error("worker doesn't work for this workshop");
    }

    Tool *tool = workshop->get_necessary_tool(this);

    std::cout << "worker is working!" << std::endl;

    tool->use();

    this->stat.levelUp();

    std::cout << stat;
}

std::ostream &operator<<(std::ostream &os, Worker &worker) {
    os << "**********WORKER**********" << std::endl;
    os << worker.stat;
    os << "Number of workshops: " << worker.workshops.size() << std::endl;
    os << "Tools: [";

    for (Worker::tool_iterator tool = worker.tools.begin(); tool != worker.tools.end(); tool++) {
        os << "{" << (**tool) << "}";
        if (tool + 1 != worker.tools.end()) {
            os << ", ";
        }
    }

    os << "]" << std::endl;
    return (os);
}
