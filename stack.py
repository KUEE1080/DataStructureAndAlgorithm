N = int(input())
stack = []
result = []
for i in range(N):
	command = input()
	if command == "top":
		if len(stack) != 0:
			result.append(stack[len(stack) - 1])
		else:
			result.append(-1)
	elif command == "empty":
		if len(stack) == 0:
			result.append(1)
		else:
			result.append(0)
	elif command == "size":
		result.append(len(stack))
	elif command == "pop":
		if len(stack) != 0:
			result.append(stack[len(stack) - 1])
			del(stack[len(stack) - 1])
		else:
			result.append(-1)
	else:
		data = int(command.split()[1])
		stack.append(data)
		
for r in result:
	print(r)
