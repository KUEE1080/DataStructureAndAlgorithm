import numpy as np

white = 0
blue = 0

def paper_split(A):
	global white, blue
	unique = np.unique(A)
	if len(unique) == 1:
		if unique[0] == 0:
			white += 1
		elif unique[0] == 1:
			blue += 1
	else:
		partition = len(A) // 2
		paper_split(A[:partition, :partition])
		paper_split(A[:partition, partition:])
		paper_split(A[partition:, :partition])
		paper_split(A[partition:, partition:])	
	return

N = int(input())
raw_data = []
for i in range(N):
	raw_data.append(list(map(int, input().split())))

data = np.array(raw_data)
paper_split(data)

print(white)
print(blue)
