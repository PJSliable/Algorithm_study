T = int(input())
for _ in range(T):
    N = int(input())
    i = 0
    j = 0
    cnt = 1
    order = [int(x/2) for x in range(2*N,1,-1)] # order list를 별도로 만듦
    move_order = [(0,1), (1,0), (0,-1), (-1,0)]
    move_cnt = 0
    board=[]
    for z in range(N):
        board.append([0]*N)
    for x in order:
        for y in range(x):
            board[i][j] = cnt
            cnt += 1
            if y == x-1:
                move_cnt = (move_cnt + 1) % 4
            i += move_order[move_cnt][0]
            j += move_order[move_cnt][1]
    print("#{0}".format(_+1))
    for k in range(N):
        print(' '.join(map(str, board[k])))