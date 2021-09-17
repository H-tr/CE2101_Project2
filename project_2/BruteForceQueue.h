#pragma once
#include "priorityQueue.h"
class BruteForceQueue :
    public priorityQueue
{
public:
	BruteForceQueue(int* dis) : priorityQueue(dis) { }
	int pop();
	bool empty();
	void add(int n);
};

int BruteForceQueue::pop()
{
	if (this->empty())
		return -1;
	int pos = 0;
	int min = _dis[_queue[0]];
	for (int i = 0; i < size; ++i)
		if (_dis[_queue[i]] < min) {
			pos = i;
			min = _dis[_queue[i]];
		}
	
	int res = _queue[pos];

	for (int i = pos; i < size; ++i)
		_queue[i] = _queue[i + 1];
	
	size--;
	return res;
}

inline bool BruteForceQueue::empty()
{
	return size == 0;
}

inline void BruteForceQueue::add(int n)
{
	_queue[size] = n;
	size++;
}
