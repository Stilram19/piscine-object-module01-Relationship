# include "Worker.hpp"

void test1() {
    Worker w;
    Workshop W;

    W.register_worker(&w);
    W.executeWorkDay();

    std::cout << W;
}

void test2() {
    Worker w;
    Workshop W;
    Hammer h;

    w.takeTool(&h);
    w.takeTool(&h);
    W.register_worker(&w);
    W.executeWorkDay();

    std::cout << W;
}

void test3() {
    Worker w;
    Workshop W;
    Shovel s;

    w.takeTool(&s);
    W.register_worker(&w);
    W.executeWorkDay();
    W.executeWorkDay();
    W.executeWorkDay();
    W.executeWorkDay();
    W.executeWorkDay();

    std::cout << W;
}

void test4() {
    Worker w;
    Workshop W;
    Shovel s;
    Hammer h;

    w.takeTool(&s);
    w.takeTool(&h);
    W.register_worker(&w);
    W.executeWorkDay();

    std::cout << W;
}

void test5() {
    Worker w;
    Workshop W;
    Shovel s;
    Hammer h;

    w.takeTool(&s);
    w.takeTool(&h);
    W.register_worker(&w);
    W.executeWorkDay();
    w.giveToolBack(&h);

    std::cout << w << W;
}

void test6() {
    Worker w;
    Workshop W;
    Shovel s;
    Hammer h;

    w.takeTool(&s);
    w.takeTool(&h);
    W.register_worker(&w);
    W.executeWorkDay();
    w.giveToolBack(&s);

    std::cout << w << W;
}

void test7() {
    Worker w;
    Workshop W;
    Shovel s;
    Hammer h;

    w.takeTool(&s);
    w.takeTool(&h);
    W.register_worker(&w);
    W.executeWorkDay();
    w.leave_workshop(&W);

    std::cout << w << W;
}

void test8() {
    Worker w;
    Workshop W;
    Shovel s;
    Hammer h;

    std::cout << w;

    w.takeTool(&s);
    w.takeTool(&h);
    w.apply_for_work(&W);

    std::cout << w << W;

    W.executeWorkDay();
    W.release_worker(&w);

    std::cout << w << W;
}

int main() {
    test8();
    return (0);
}
