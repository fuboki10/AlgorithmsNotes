template<class T>
class monotonic_queue {
    stack<pair<T, pair<T, T>>> s1, s2;

    void add(stack<pair<T, pair<T, T>>>& s, T v) {
        T mx = std::max(v, s.top().Y.X);
        T mn = std::min(v, s.top().Y.Y);

        s.push({ v, { mx, mn } });
    }

    void flip() {
        if (s2.size() > 1) {
            return;
        }
        
        while (s1.size() > 1) {
            add(s2, s1.top().X);
            s1.pop();
        }
    }

public:
    monotonic_queue() {
        s1.push({ INT_MIN, { INT_MIN, INT_MAX } });
        s2.push({ INT_MIN, { INT_MIN, INT_MAX } });
    }

    void push(T v) {
        add(s1, v);
    }

    void pop() {
        flip();
        s2.pop();
    }

    T front() {
        flip();
        return s2.top().X;
    }

    T max() {
        return std::max(s1.top().Y.X, s2.top().Y.X);
    }

    T min() {
        return std::min(s1.top().Y.Y, s2.top().Y.Y);
    }

    T size() {
        return s1.size() + s2.size() - 2;
    }
};