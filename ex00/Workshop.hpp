#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include "my_header.hpp"
# include "Worker.hpp"

class Workshop {
    private:
        std::string             necessary_tool_type;
        std::vector<Worker *>   workers;

        // types
        typedef std::vector<Worker *>::iterator worker_iterator;
        typedef std::vector<Worker *>::const_iterator const_worker_iterator;

    // Constructors & Destructor
    public:
        Workshop();
        Workshop(const std::string &necessary_tool);
        ~Workshop();

    // Methods
    private:
        bool has_worker(Worker *worker) const;

    public:
        Tool *get_necessary_tool(Worker *worker) const;
        bool register_worker(Worker *worker);
        void release_worker(Worker *worker);
        void executeWorkDay();
        friend std::ostream &operator<<(std::ostream &os, Workshop &workshop);
};

#endif
