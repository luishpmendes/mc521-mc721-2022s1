#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

int main() {
    unsigned n, c, x, num_equals;
    std::vector<unsigned> output, stack_output, queue_output, priority_queue_output;
    std::stack<unsigned> stack;
    std::queue<unsigned> queue;
    std::priority_queue<unsigned> priority_queue;
    bool is_stack, is_queue, is_priority_queue,
         can_be_stack, can_be_queue, can_be_priority_queue;

    while (std::cin >> n) {
        num_equals = 0;
        output.clear();
        stack_output.clear();
        queue_output.clear();
        priority_queue_output.clear();
        stack = std::stack<unsigned>();
        queue = std::queue<unsigned>();
        priority_queue = std::priority_queue<unsigned>();
        is_stack = is_queue = is_priority_queue = false;
        can_be_stack = can_be_queue = can_be_priority_queue = true;

        while (n--) {
            std::cin >> c >> x;

            if (c == 1) {
                stack.push(x);
                queue.push(x);
                priority_queue.push(x);
            } else { // c == 2
                output.push_back(x);
                if (!stack.empty()) {
                    stack_output.push_back(stack.top());
                    stack.pop();
                } else {
                    can_be_stack = false;
                }

                if (!queue.empty()) {
                    queue_output.push_back(queue.front());
                    queue.pop();
                } else {
                    can_be_queue = false;
                }

                if (!priority_queue.empty()) {
                    priority_queue_output.push_back(priority_queue.top());
                    priority_queue.pop();
                } else {
                    can_be_priority_queue = false;
                }
            }
        }

        if (can_be_stack && std::equal(output.begin(), output.end(), stack_output.begin())) {
            is_stack = true;
            num_equals++;
        }

        if (can_be_queue && std::equal(output.begin(), output.end(), queue_output.begin())) {
            is_queue = true;
            num_equals++;
        }

        if ( can_be_priority_queue && std::equal(output.begin(), output.end(), priority_queue_output.begin())) {
            is_priority_queue = true;
            num_equals++;
        }

        if (num_equals == 0) {
            std::cout << "impossible" << std::endl;
        } else if (num_equals > 1) {
            std::cout << "not sure" << std::endl;
        } else {
            if (is_stack) {
                std::cout << "stack" << std::endl;
            } else if (is_queue) {
                std::cout << "queue" << std::endl;
            } else {
                std::cout << "priority queue" << std::endl;
            }
        }
    }

    return 0;
}
