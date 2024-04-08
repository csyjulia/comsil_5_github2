#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <typename T>
class Stack : public LinkedList<T> {
public:
	bool Delete(T& element) {
		if (this->first == 0)
			return false;
		//first가 0이면 false반환

	
		Node<T>* del = this->first;//삭제할 노드를 표현할 del 노드를 첫 번째 노드로 초기화.

		this->first = this->first->link;//첫 번째 노드를 두 번째 노드로 변경
		element = del->data;//삭제한 노드의 data 값을 element에 저장.

		delete del;//삭제한 노드의 메모리 해제
		this->current_size--;//리스트의 크기 하나 줄이기


		// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제


		return true;
	}
};
