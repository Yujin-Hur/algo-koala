def dfs(graph, start_node):
     
    ## 기본은 항상 두개의 리스트를 별도로 관리해주는 것
    need_visited, visited = list(), list()
 
    ## 시작 노드를 시정하기 
    need_visited.append(start_node)
    
    ## 만약 아직도 방문이 필요한 노드가 있다면,
    while need_visited:
 
        ## 그 중에서 가장 마지막 데이터를 추출 (스택 구조의 활용)
        node = need_visited.pop()
        
        ## 만약 그 노드가 방문한 목록에 없다면
        if node not in visited:
 
            ## 방문한 목록에 추가하기 
            visited.append(node)
            print(node, end = '')
 
            ## 그 노드에 연결된 노드를 
            need_visited.extend(graph[node])
            
    return visited

graph = dict()
 
graph['A'] = ['B', 'C']
graph['B'] = ['A', 'D']
graph['C'] = ['A', 'G', 'H', 'I']
graph['D'] = ['B', 'E', 'F']
graph['E'] = ['D']
graph['F'] = ['D']
graph['G'] = ['C']
graph['H'] = ['C']
graph['I'] = ['C', 'J']
graph['J'] = ['I']


dfs(graph,'A')

visited = []
def dfs_recursive(graph, start):
    # 이미 방문한 노드라면 탐색 종료
    if start in visited:
        return
    
    # 방문 표시
    visited.append(start)
    print(start, end=' ')

    # 인접 정점들에 대해 재귀 호출
    for now in graph[start]:
        dfs_recursive(graph, now)