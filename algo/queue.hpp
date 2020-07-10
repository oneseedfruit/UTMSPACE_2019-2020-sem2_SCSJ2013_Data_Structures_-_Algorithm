#ifndef QUEUE_HPP
#define QUEUE_HPP

namespace randydsa
{
    const int queue_size = 10;

    class queue_array
    {
    private:
        int count;
        int front;
        int back;
        char data[queue_size];

    public:
        queue_array();
        bool is_empty() const;
        bool is_full() const;
        char get_front() const;
        char get_back() const;
        char enqueue(char);
        char dequeue();
        void clear();
    };

    class queue_linkedlist
    {

    };
}

#endif