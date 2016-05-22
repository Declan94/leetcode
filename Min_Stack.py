# Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

# push(x) -- Push element x onto stack.
# pop() -- Removes the element on top of the stack.
# top() -- Get the top element.
# getMin() -- Retrieve the minimum element in the stack.		

class MinStack:

	def __init__(self):
		self._stack = list()
		self._minStack = list()

    # @param x, an integer
    # @return an integer
	def push(self, x):
		if len(self._stack) == 0:
			self._minStack.append(0)
		else:
			if x < self._stack[self._minStack[-1]]:
				self._minStack.append(len(self._stack))
		self._stack.append(x)

    # @return nothing
	def pop(self):
		top = self._stack.pop()
		if self._minStack[-1] >= len(self._stack):
			self._minStack.pop()
		return top
        

    # @return an integer
	def top(self):
		top = self._stack[-1]
		return top
        

    # @return an integer
	def getMin(self):
		return self._stack[self._minStack[-1]]


if __name__ == '__main__':
	s = MinStack()
	s.push(-2)
	s.push(0)
	s.push(1)
	print s.getMin()
	print s.top()
	s.pop()
	print s.getMin()
