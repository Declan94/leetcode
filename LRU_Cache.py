class Link:
	
	head = None
	tail = None
	node_cnt = 0

	def __init__(self):
		self.node_cnt = 0
		
	def insert(self, node):
		self.node_cnt = self.node_cnt + 1
		if self.head == None:
			self.head = node
			self.tail = node
			node.prev = None
			node.next = None
		else:
			node.next = self.head
			node.prev = None
			node.next.prev = node
			self.head = node
			

	def delete(self, node):
		self.node_cnt = self.node_cnt - 1
		if self.head == node:
			self.head = node.next
			if node.next:
				node.next.prev = None
		if self.tail == node:
			self.tail = node.prev
			if node.prev:
				node.prev.next = None
		else:
			if node.prev:
				node.prev.next = node.next
			if node.next:
				node.next.prev = node.prev
		node.prev = None
		node.next = None



class LinkNode:

	def __init__(self, value):
		self.prev = None
		self.next = None
		self.val = value




class LRUCache:

	capacity = 0
	data = None
	nodes = None
	link = None

    # @param capacity, an integer
	def __init__(self, capacity):
		self.capacity = capacity
		self.data = dict()
		self.nodes = dict()
		self.link = Link()
	
	def get(self, key):
		if key in self.data:
			n = self.nodes[key]
			self.link.delete(n)
			self.link.insert(n)
			return self.data[key]
		return -1

    # @param key, an integer
    # @param value, an integer
    # @return nothing
	def set(self, key, value):
		if key in self.data:
			self.data[key] = value
			n = self.nodes[key]
			self.link.delete(n)
			self.link.insert(n)
			return
		if self.link.node_cnt == self.capacity:
			to_del = self.link.tail
			k = to_del.val
			del(self.data[k])
			del(self.nodes[k])
			self.link.delete(to_del)
		n = LinkNode(key)
		self.nodes[key] = n
		self.link.insert(n)
		self.data[key] = value

if __name__ == '__main__':
	cache = LRUCache(3)
	cache.set(1, 1)
	cache.set(2, 2)
	cache.set(3, 3)
	cache.set(4, 4)
	cache.set(4, 5)
	cache.set(4, 6)
	cache.set(4, 7)
	print cache.get(4)



        