def solve(starty, lasty, startx, lastx):
    global arr
    if starty == lasty and startx == lastx:
        return str(arr[starty][startx])

    lefttop = solve(starty, (lasty + starty) // 2, startx, (lastx + startx) // 2)
    righttop = solve(starty, (lasty + starty) // 2, (lastx + startx) // 2 + 1, lastx)
    leftbot = solve((lasty + starty) // 2 + 1, lasty, startx, (lastx + startx) // 2)
    rightbot = solve((lasty + starty) // 2 + 1, lasty, (lastx + startx) // 2 + 1, lastx)
    if lefttop == '0' and righttop == '0' and leftbot == '0' and rightbot == '0':
        return '0'
    elif lefttop == '1' and righttop == '1' and leftbot == '1' and rightbot == '1':
        return '1'
    else:
        return '(' + str(lefttop) + str(righttop) + str(leftbot) + str(rightbot) + ')'


n = int(input())
arr = [[0 for i in range(n)] for i in range(n)]
for i in range(n):
    arr[i] = list(map(int, input().format()))

print(solve(0, n - 1, 0, n - 1))
