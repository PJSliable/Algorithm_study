for _ in range(4):
    x1, y1, p1, q1, x2, y2, p2, q2 = map(int, input().split())
    # 공유하는 x좌표와 y좌표를 각각 찾는다.
    set_x = {x for x in range(x1, p1+1)} & {x for x in range(x2, p2+1)}
    set_y = {y for y in range(y1, q1+1)} & {y for y in range(y2, q2+1)}
    if len(set_x) == 0 or len(set_y) == 0:
        print('d')
    elif len(set_x) == 1 and len(set_y) == 1:
        print('c')
    elif len(set_x) >= 2 and len(set_y) >= 2:
        print('a')
    else:
        print('b')