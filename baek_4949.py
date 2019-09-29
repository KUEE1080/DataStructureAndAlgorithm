def filter(txt): # can be improved using regular expression
	output = []
	for t in txt:
		if t == "(" or t == ")" or t == "[" or t == "]":
			output.append(t)
	return output

result = []
while True:
	raw_input = input()
	line = filter(raw_input)
	
	if raw_input != ".":
		stack = []
		err = False
		
		for l in line:
			try:
				if l == "(" or l == "[":
					stack.append(l)
				elif l == "]":
					if stack[len(stack) - 1] == "[":
						stack.pop()
					else:
						err = True
						break
				elif l == ")":
					if stack[len(stack) - 1] == "(":
						stack.pop()
					else:
						err = True
						break
			except:
				err = True
				break
		if err == True or len(stack) != 0:
			result.append("no")
		else:
			result.append("yes")
	else:
		break

for r in result:
	print(r)
