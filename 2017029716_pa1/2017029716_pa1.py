# -*- coding: utf-8 -*-

map = [['#','#','#','#','#','#','#','#'],
       ['#','@','.','.','.','.','G','#'],
       ['#','#','.','#','#','@','#','#'],
       ['#','.','.','@','.','.','.','#'],
       ['#','@','.','.','.','.','.','#'],
       ['#','#','#','#','#','#','#','#']]

a = 3
b = 6
text = ''
checkPointCount = 0
wordList = ['first','second','third','forth']
Boolean = True

# 맵과 횟수를 프린트 해주는 함수
def printMap():
    global a,b,text
    map[a][b] = 'S'

    # 횟수를 나타내줌.
    print str(count) + '> ' + text
    text = ''

    # 맵을 출력해준다.
    for i in map:
        print '   ' + ''.join(i)

# 움직일 수 있는 방향의 보기를 만드는 함수
def checkList():
    global List
    
    # 움직일 수 있는 방향을 리스트에 넣어준다.
    List = []
    if map[a-1][b] != '#': List.append('N')
    if map[a][b+1] != '#': List.append('E')
    if map[a+1][b] != '#': List.append('S')
    if map[a][b-1] != '#': List.append('W')

# 입력을 받고 그에 따라 S를 움직여주는 함수
def control():
    print 'Input next move: (' + ','.join(List) + ')?'
    Input = raw_input().upper()

    if Input in List :

        global a, b, count, text, checkPointCount, wordList, Boolean

        # S가 있었던 자리의 값을 '.'로 바꿔준다.
        map[a][b] = '.'

        # 입력 받은 값에 따라 S의 좌표를 움직여준다.        
        if Input == "W": b = b - 1
        elif Input == "E": b = b + 1
        elif Input == "S": a = a + 1
        elif Input == "N": a = a - 1

        # @를 만나면 체크포인트를 만난 횟수를 세어준다.
        if map[a][b] == '@' :
            text = 'You have arrived the ' + wordList[checkPointCount] + ' checkpoint.'
            checkPointCount = checkPointCount + 1

        # G를 만나면 게임의 승패를 결정해준다.
        if map[a][b] == 'G' :
            if checkPointCount == 4 :
                text = 'You Win!'
                Boolean = False
                
            else :
                text = 'You Lose'
                Boolean = False
            
        # 횟수를 세어준다.
        count = count + 1

        # 20회가 넘을 경우 승패를 나타내준다.
        if count == 21 :
            text = 'You Lose'
            Boolean = False

    # 움직일 수 없는 방향을 입력 받을 경우 "Can't Move!"를 출력해준다.
    else : print "Can't Move!"
    
# 실제 게임이 돌아가는 부분
count = 0
printMap()
while Boolean == True :
    checkList()
    control()
    printMap()
