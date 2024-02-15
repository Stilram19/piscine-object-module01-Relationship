#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include "my_header.hpp"
# include "Worker.hpp"

class Workshop {
    private:
        std::string             necessary_tool_type;
        std::vector<Worker *>   workers;

        // types
        typedef std::vector<Worker *>::const_iterator worker_iterator;

    // Constructors & Destructor
    public:
        Workshop();
        Workshop(const std::string &necessary_tool);
        ~Workshop();

    // Methods
    private:
        bool has_worker(Worker *worker);

    public:
        Tool *get_necessary_tool(Worker *worker);
        void register_worker(Worker *worker);
        void release_worker(Worker *worker);
        void executeWorkDay();
};

#endif
