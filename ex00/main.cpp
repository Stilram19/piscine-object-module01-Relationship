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

void test9() {
    Worker w1, w2, w3;
    Workshop W1, W2("Hammer"), W3;
    Shovel s1, s2, s3;
    Hammer h1, h2, h3;

    std::cout << W1 << W2 << W3;

    w1.apply_for_work(&W1);
    W1.register_worker(&w1);
    w1.leave_workshop(&W1);
    W1.release_worker(&w1);

    std::cout << W1 << W2 << W3;

    w1.takeTool(&s1);
    w2.takeTool(&s2);
    w3.takeTool(&s3);

    w1.apply_for_work(&W1);
    w2.apply_for_work(&W2);
    w3.apply_for_work(&W3);

    std::cout << W1 << W2 << W3;

    w2.apply_for_work(&W1);

    std::cout << W1 << W2 << W3;

    w1.takeTool(&h1);
    w2.takeTool(&h2);
    w3.takeTool(&h3);

    W2.register_worker(&w1);
    W2.register_worker(&w2);
    W2.register_worker(&w3);

    std::cout << W1 << W2 << W3;

    w2.leave_workshop(&W2);
    w1.leave_workshop(&W3);
    w1.leave_workshop(&W3);
    w1.leave_workshop(&W3);

    std::cout << W1 << W2 << W3;

    w3.giveToolBack(&h3);
    w2.giveToolBack(&h2);
    w3.giveToolBack(&s3);

    std::cout << W1 << W2 << W3;
}

int main() {
    try {
        test9();
    }
    catch (const std::runtime_error &e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
    catch (const std::bad_alloc &e) {
        std::cout << "SORRY WE'RE OUT OF MEMORY" << std::endl;
    }
    return (0);
}
