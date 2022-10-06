arr = [[1,2],[0,1],[3,4],[4,6],[9,10]]
arr.sort(key = lambda x : x[0])
m = []
for i in range(len(arr)):
    if m==[] or m[-1][1] < arr[i][0]:
        v=[arr[i][0],arr[i][1]]
        m.append(v)
    else:
        m[-1][1] = max(m[-1][1],arr[i][1])
print(*m)