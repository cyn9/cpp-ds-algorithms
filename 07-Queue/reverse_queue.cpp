#include <iostream>
#include <queue>
#include <stack>

template<typename T>
void reverse(std::queue<T> &);

int main() {
    constexpr auto q_size {10};
    std::queue<int> q;
    
    for (std::size_t i = 1; i <= q_size; i++) {
        q.push(10*i);
    }

    reverse(q);

    std::cout << "Reversed >> ";
    for (std::size_t i = 0; i < q_size; i++) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << '\n';

    return 0;
}

template<typename T>
void reverse(std::queue<T> &q) {
    std::stack<T> s;

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}
