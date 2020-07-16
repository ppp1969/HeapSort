/*

힙(heap)은 최댓값 및 최솟값을 찾아내는 연산을 빠르게 하기 위해 고안된 
완전이진트리(Complete binary tree)를 기본으로 한 자료구조.

	힙은 두가지 조건을 만족하는 자료구조다.

		1. 구조조건 - 완전이진트리

		2. 순서조건 - Partial Order를 만족한다.

	완전 이진 트리가 될 조건은 기본적으로 이진트리여야 하며, 
	마지막 레벨을 제외한 각 레벨이 빠짐없이 채워져 있고, 
	마지막 레벨은 중간에 빈칸이 없이 왼쪽부터 노드들로 채워져 있어야 하며, 
	포화이진트리 역시 완전이진트리라고 했다.

	부모노드의 키값이 자식노드의 키값보다 항상 큰 힙을 '최대 힙'
	부모노드의 키값이 자식노드의 키값보다 항상 작은 힙을 '최소 힙'

	완전이진트리를 배열로 구현했을 때 정말 좋은 장점 : 인덱스로 접근이 직접적으로 가능함.



출처: https://zeddios.tistory.com/56 [ZeddiOS]
*/

#include<stdio.h>
//코드 참조 : https://m.blog.naver.com/ndb796/221228342808
//최대힙을 활용한 알고리즘. 후에 함수로 구현해볼 예정
//힙정렬은 병합정렬과 다르게 별도의 추가적인 배열이 필요하지 않은 점에서 메모리 사용 효율이 뛰어남.
//또한 항상 시간복작도 O(N * log N)를 보장할 수 있기에 강력한 정렬 알고리즘 중 하나.
int number = 9;
int heap[9] = {4,3,2,6,1,7,8,9,6};

int main(void){
	//힙구성
	for(int i = 1; i< number; i++){
		int c = i;

		do{
			int root = (c-1)/2;
			if(heap[root] < heap[c]){
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		}while(c != 0);
	}
	//점진적으로 크기 줄이며 힙 구성 반복.
	for( int i = number -1; i>=0;i--){
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;

		int root = 0;
		int c = 1;

		do{
			c = 2 * root + 1;
			//자식노드중 더 큰 값을 찾기

			if(c < i - 1 && heap[c] < heap[c + 1]){
				c++;
			}
			//루트보다 자식이 크면 교환
			if(c < i && heap[root] < heap[c]){
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		}while(c < i);
	}

	for(int i = 0; i < number; i++){
		printf("%d", heap[i]);
	}
	return 0;
}
