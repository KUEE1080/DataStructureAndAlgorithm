
'''defining constant'''
CORRIDOR = 0
WALL = 1
DESTINATION = 2

VISITED = 3
BLOCKED = 4

def findpath(_maze, y, x):
    path_stack = []  # pushing the starting point to the path stack
    path_stack.append([y, x])
    _maze[y][x] = VISITED

    while True:
        coor = path_stack.pop()

        if _maze[coor[0]][coor[1] + 1] == DESTINATION or _maze[coor[0]][coor[1] - 1] == DESTINATION \
                or _maze[coor[0] + 1][coor[1]] == DESTINATION or _maze[coor[0] - 1][coor[1]] == DESTINATION:
            for n in range(len(_maze)):
                _maze[n] = [CORRIDOR if x == BLOCKED else x for x in _maze[n]]
            break
        else:
            if _maze[coor[0] + 1][coor[1]] == CORRIDOR:  # checking bottom block
                path_stack.append(coor)
                path_stack.append([coor[0] + 1, coor[1]])
                _maze[coor[0] + 1][coor[1]] = VISITED

            elif _maze[coor[0]][coor[1] + 1] == CORRIDOR:  # checking right block
                path_stack.append(coor)
                path_stack.append([coor[0], coor[1] + 1])
                _maze[coor[0]][coor[1] + 1] = VISITED

            elif _maze[coor[0]][coor[1] - 1] == CORRIDOR:  # checking left block
                path_stack.append(coor)
                path_stack.append([coor[0], coor[1] - 1])
                _maze[coor[0]][coor[1] - 1] = VISITED

            elif _maze[coor[0] - 1][coor[1]] == CORRIDOR:  # checking top block
                path_stack.append(coor)
                path_stack.append([coor[0] - 1, coor[1]])
                _maze[coor[0] - 1][coor[1]] = VISITED

            else:  # if all place is blocked
                try:
                    invalid_route = path_stack.pop()
                except:
                    return []
                _maze[invalid_route[0]][invalid_route[1]] = BLOCKED

    return _maze


if __name__ == "__main__":
    maze = [
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1],
        [1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1],
        [1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
        [1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1],
        [1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1],
        [1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1],
        [1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1],
        [1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1],
        [1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1],
        [1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1],
        [1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1],
        [1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1],
        [1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1],
        [1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1],
        [1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1],
        [1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1],
        [1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1],
        [1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1],
        [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    ]

    print(maze)
    X, Y = map(int, input("X Y 를 입력하시오 \n").split())
    new_maze = findpath(maze, Y, X)
    if new_maze != []:
        [print(i) for i in new_maze]
    else:
        print("there is no path")
