#pragma once
#include "priorityQueue.h"
class heapQueue :
    public priorityQueue
{
public:
	heapQueue(int* dis) : priorityQueue(dis) { }
	int pop();
	bool empty();
	void add(int n);
	void maintain(int n);
private:
	int left(int i);
	int right(int i);
	int par(int i);
	int index[100000] = { 0 };
	void heapify(int i);
	void modify(int i);
};

int heapQueue::pop()
{
	int re = _queue[1];
	_queue[1] = _queue[size];
	size--;
	heapify(1);
	return re;
}

inline bool heapQueue::empty()
{
	return size == 0;
}

inline void heapQueue::add(int n)
{
	size++;
	_queue[size] = n;
	index[n] = size;
	modify(size);
}

inline void heapQueue::maintain(int n)
{
	modify(index[n]);
}

inline int heapQueue::left(int i)
{
	return 2 * i;
}

inline int heapQueue::right(int i)
{
	return 2 * i + 1;
}

inline int heapQueue::par(int i)
{
	return i / 2;
}

inline void heapQueue::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int min = i;
	if (l < size && _dis[_queue[l]] < _dis[_queue[min]]) 
		min = l;
	if (r < size && _dis[_queue[r]] < _dis[_queue[min]])
		min = r;

	if (min != i) {
		index[_queue[i]] = min;
		index[_queue[min]] = i;
		std::swap(_queue[i], _queue[min]);
		heapify(min);
	}
}

inline void heapQueue::modify(int i)
{
	while (i > 1 && (_dis[_queue[par(i)]] > _dis[_queue[i]])) {
		index[_queue[i]] = par(i);
		index[_queue[par(i)]] = i;
		std::swap(_queue[i], _queue[par(i)]);
		i = par(i);
	}
}

