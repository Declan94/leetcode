# Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

# push(x) -- Push element x onto stack.
# pop() -- Removes the element on top of the stack.
# top() -- Get the top element.
# getMin() -- Retrieve the minimum element in the stack.

class MyHeap():

	def __init__(self):
		self.list = []

	def swap(self, p, q):
		x = self.list[p]
		y = self.list[q]
		x.index = q
		y.index = p
		self.list[p] = y
		self.list[q] = x

	def floatUp(self):
		p = len(self.list)-1
		q = int(p / 2)
		while p > 0 and self.list[q].value > self.list[p].value:
			self.swap(p, q)
			p = q
			q = int(p / 2)

	def sinkDown(self, root = 0):
		i = root
		while i * 2 < len(self.list):
			if i*2+1 >= len(self.list) or self.list[i*2].value < self.list[i*2+1].value:
				self.swap(i, i*2)
			else:
				self.swap(i, i*2+1)

	def truncTail(self):
		i = len(self.list) - 1
		while i >= 0 and not self.list[i].valid:
			self.list.pop()
			i = i - 1

	def push(self, hnode):
		hnode.index = len(self.list)
		self.list.append(hnode)
		self.floatUp()

	def pop(self):
		top = self.list[0]
		self.sinkDown()
		return top

	def top(self):
		return self.list[0]

	def delete(self, hnode):
		hnode.valid = False
		self.sinkDown(hnode.index)
		self.truncTail()


class HeapNode():

	def __init__(self, value):
		self.index = -1
		self.value = value
		self.valid = True
		

class MinStack:

	def __init__(self):
		self.heap = MyHeap()
		self.stack = []

    # @param x, an integer
    # @return an integer
	def push(self, x):
		node = HeapNode(x)
		self.heap.push(node)
		self.stack.append(node)

    # @return nothing
	def pop(self):
		top = self.stack.pop()
		self.heap.delete(top)
		return top.value
        

    # @return an integer
	def top(self):
		top = self.stack[-1]
		return top.value
        

    # @return an integer
	def getMin(self):
		while not self.heap.top().valid:
			self.heap.pop()
		return self.heap.top().value



if __name__ == '__main__':
	s = MinStack()
	s.push(-2)
	s.push(0)
	s.push(1)
	print s.getMin()
	print s.top()
	s.pop()
	print s.getMin()
