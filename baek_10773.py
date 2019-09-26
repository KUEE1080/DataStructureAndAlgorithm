N = int(input())
stack = []
for i in range(N):
	data = int(input())
	if data != 0:
		stack.append(data)
	else:
		del(stack[len(stack) - 1])

print(sum(stack))
