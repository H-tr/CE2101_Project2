#pragma once
class priorityQueue
{
public:
	priorityQueue(int* dis) {
		this->_dis = dis;
	}

	virtual int pop() = 0;
	virtual bool empty() = 0;
	virtual void add(int n) = 0;
protected:
	int _queue[1000] = { 0 };
	int* _dis;
	int size;
};