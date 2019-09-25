N = int(input())
result = []

for i in range(N):
	data = input()
	stack = []
	flag = False
	
	for d in data:
		if d == "(":
			stack.append("(")
		else:
			try:
				stack.pop()
			except:
				flag = True
				
	if len(stack) == 0 and flag == False:
		result.append("YES")
	else:
		result.append("NO")
	
for r in result:
	print(r)
