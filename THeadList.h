#include "TList.h" 
template <class T> 
class THeadList :public TList<T> { 
protected: 
	TLink<T> *pHead; 
public: 
	THeadList():TList<T>(){ 
		TLink<T> *tmp = new TLink<T>; 
		pHead = tmp; 
		pHead->pNext = pHead; 
		pStop = pHead; 
	} 

	~THeadList() { 
		TList<T>::~TList(); 
		delete pHead; 
	} 

	virtual void InsFirst(T a) { 
		TList<T>::InsFirst(a); 
		pHead->pNext = pFirst; 
	} 

	virtual void delFirst() { 
		TList<T>::delFirst(); 
		pHead->pNext = pFirst; 
	} 

};

