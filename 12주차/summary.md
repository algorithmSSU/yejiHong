# 8. 트리

> **개념 및 용어정리**
> 

트리란, 계층적인 자료를 표현하는데 이용되는 자료구조이다.

![[https://medium.com/quantum-ant/트리-tree-cec69cfddb14](https://medium.com/quantum-ant/%ED%8A%B8%EB%A6%AC-tree-cec69cfddb14)](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/012d7e73-79c2-478b-9b65-f16590d6ac0d/Untitled.png)

[https://medium.com/quantum-ant/트리-tree-cec69cfddb14](https://medium.com/quantum-ant/%ED%8A%B8%EB%A6%AC-tree-cec69cfddb14)

- **루트** : 가장 최상위 노드
- **서브 트리** : 루트를 제외한 나머지 노드
- **단말노드** : 자식이 없는 노드
- **비단말노드** : 자식이 있는 노드
- **간선** : 루트와 서브트리를 연결하는 선
- **차수** : 노드가 가지고 있는 자식노드 수
- **레벨** : 각 층에 번호를 매긴 것
    
    루트의 레벨은 1 이며, 내려갈 때마다 레벨 증가함.
    
- **트리의 높이** : 트리가 가지고 있는 최대 레벨

---

> **이진트리**
> 

이진트리(binary search)는 모든 노드가 2개의 서브 트리를 가지고 있는 트리

- 이진트리의 서브트리는 공집합일 수 있다. 즉 0~2개의 자식 노드가 존재할 수 있음(최대 2개) → 모든 노드의 차수는 2이하.
- 이진트리의 서브트리간 순서가 존재함.
    
    오른쪽 서브트리/ 왼쪽 서브트리
    

### 이진트리와 일반트리의 차이점

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/dc238bce-d236-4eb3-bde5-6f7c4617640e/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/91b87e43-b855-42aa-a3a0-b575ef5d7cea/Untitled.png)

- 한 레벨에 최소 하나의 노드는 존재해야 하므로, 최소 노드를 가지는 경우 높이만큼의 노드를 가진다.

- 하나의 노드는 최대 2개의 자식을 가지기 때문에, 레벨 i에서의 노드는 최대 2^h-1이다.

- n개의 노드를 가지는 이진 트리의 높이는 최대 n 이거나 최소 log2(n+1)

---

> **이진 트리 - 표현법**
> 

1. **배열표현법**

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/561e47e5-3dbf-481b-9a6e-7aca9b2d737c/Untitled.png)

부모와 자식의 인덱스 사이의 관계

- 노드 i의 부모 노드 인덱스 = i/2
- 노드 i의 왼쪽 자식 노드 인덱스 = 2*i
- 노드 i의 오른쪽 노드 인덱스 = 2*i+1

→ 하지만 배열로 표현하게 되면 완전이진트리가 아닌 경우 메모리가 낭비된당

1. **링크 표현법**

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d31c677c-4125-4c3e-bbed-32692c5548de/Untitled.png)

링크 표현법에는 노드가 구조체로 표현.

노드가 가진 포인터를 이용해서 노드끼리 연결

---

> **순회**
> 

이진 트리를 순회한다는 것은 트리에 속하는 모든 노드를 한번씩 방문하여 탐색하는 것을 의미

이진트리는 최대 차수(자식노드의 수)가 2 이며, 서브트리간 순서가 있는 것을 이용해서 순회를 세가지 방식으로 분류함.

1. **전위 순회**

: 중간 → 왼 → 오

1. **중위 순회**

: 왼 → 중간 → 오

1. **후위 순회**

: 왼 → 오 → 중간