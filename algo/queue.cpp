#include "queue.hpp"

namespace randydsa
{
    queue_array::queue_array()
    {
        count = 0;
        front = 0;
        back = queue_size -1;
    }

    bool queue_array::is_empty() const
    {
        return count == 0;
    }

    bool queue_array::is_full() const
    {
        return count == queue_size;
    }

    char queue_array::get_front() const
    {
        if (!is_empty())
            return data[front];
        else
            return -1;
    }

    char queue_array::get_back() const
    {
        if (!is_empty())
            return data[back];
        else
            return -1;
    }

    char queue_array::enqueue(char c)
    {
        if (!is_full())
        {
            back = (back + 1) % queue_size;
            data[back] = c;
            ++count;
        }

        return c;
    }

    char queue_array::dequeue()
    {
        char d = data[front];

        if (!is_empty())
        {
            front = (front + 1) % queue_size;
            --count;
        }

        return d;
    }

    void queue_array::clear()
    {
        count = 0;
        front = 0;
        back = queue_size -1;
    }
}