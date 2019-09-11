import math

from random import choice

def distance(M,relay,goal):
    ##x=pow((M.intersections[relay][0]-M.intersections[goal][0]),2)
    ##y=pow((M.intersections[relay][1]-M.intersections[goal][1]),2)
    (x1,x2)=M.intersections[relay]
    (y1,y2)=M.intersections[goal]
    x=pow((x1-y1),2)
    y=pow((x2-y2),2)
    return math.sqrt(x+y)
'''
def g_score(M,start,relay):
    for relay in M.roads(relay)



def get_f(M,start,relay,goal):
    h=get_h(M,relay,goal)
    g=get_g(M,start,relay)
    path_cost[relay]=h+g
    return h+g
'''   
def minf(start,f_score,frontier):
    ##todo fix
    '''
    x=list(frontier)[0]
    min_f=f_score[list(frontier)[0]]
    #print(minf)
    for key in frontier:
        if f_score[key]<min_f:
            min_f=f_score[key]
            x=key
    
    #data=dict()
    data_f=set()
    for key in frontier:
        #data[key]=f_score[key]
        #print('frontier is',key,'f_score is',f_score[key])
        data_f.add(f_score[key])
    min_f=min(data_f)
    for key in frontier:
        if f_score[key]==min_f:
            x=key
    print(type(f_score.values()))
    print(f_score.values())
    '''
    data=dict()
    
    for key in frontier:
        data[key]=f_score[key]
    min_data,x=min(zip(data.values(),data.keys()))
    #current = min(openSet, key= lambda x: fScore.get(x))

    return x

def A(M,start,goal):
    explored=set()
    frontier={start}
    came_from=dict()

    g_score=dict()
    h_score=dict()
    f_score=dict()

    g_score[start]=0
    h_score[start]=distance(M,start,goal)
    f_score[start]=h_score[start]

    while not isempty(frontier):
        x=minf(start,f_score,frontier)
        #print('minf_point is ',x)
        #print('minf is ',min_f)
        if x==goal:
            #print (came_from)
            return reconstruct_path(came_from,start,goal)
            
        frontier.remove(x)
        #print(frontier)
        explored.add(x)
        for y in M.roads[x]:
            #print(y)
            if y in explored:
                continue
            tentative_g_score=g_score[x]+distance(M,x,y)
            #print(tentative_g_score)
            if y not in frontier:
                frontier.add(y)
                #print(frontier)
                tentative_is_better=True
            elif tentative_g_score<g_score[y]:##如果起点到y的距离小于y的实际距离
                tentative_is_better=True
            else:
                tentative_is_better=False
            if tentative_is_better==True:
                came_from[y]=x
                #print()
                #print('came_from is',came_from)
                #print()
                g_score[y]=tentative_g_score
                h_score[y]=distance(M,y,goal)
                f_score[y]=g_score[y]+h_score[y]
            #print('frontier is',frontier)
    return -1


def reconstruct_path(came_from, start, goal):
    current = goal
    path = []
    while current != start:
        path.append(current)
        current = came_from[current]
    path.append(start) # optional
    path.reverse() # optional
    return path    
    '''
def reconstruct_path(came_from,current_node):
    
    if current_node in came_from:
        p=reconstruct_path(came_from,came_from[current_node])
        return (p+[current_node])
    else:
        return [current_node]
        '''

    '''
    if type(came_from[current_node])==dict:
        p=reconstruct_path(came_from,came_from[current_node])
        return (p+current_node)
    else:
        return current_node

    p=reconstruct_path(came_from,came_from[current_node])
    return (p+current_node)
'''

def isempty(set_data):
    if len(set_data)==0:
        return True
    return False


def shortest_path(M,start,goal):
    


    



    print("shortest path called")
    return A(M,start,goal)