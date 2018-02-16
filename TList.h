#pragma once
#include <iostream>

template <class T>
struct TLink {
	T value;
	TLink *pNext;
};

template <class T>
class TList {
	int Size;
	int Pos;
//	TLink <T> *pFirst, *pLast, *pCurrent, *pPrevious, *pStop;
public:
		TLink <T> *pFirst, *pLast, *pCurrent, *pPrevious, *pStop;
	TList() {
		pFirst = pLast = pCurrent = pPrevious = pStop = NULL;
		Size = 0;
		Pos = -1;
	}

	void InsFirst(T a) {
		TLink<T>*tmp = new TLink<T>;
		tmp->value = a;
		if (Size == 0) {
			pFirst = pLast = tmp;
			tmp->pNext = pStop;
		}
		else {
			tmp->pNext = pFirst;
			pFirst = tmp;
			Pos++;
		}
		Size++;
	}

	void InsCurrent(T a) {
		if (pCurrent == pFirst) {
			InsFirst(a);
		}
		else{
		TLink<T> *tmp = new TLink<T>;
		tmp->value = a;
		tmp->pNext = pCurrent;
		pPrevious->pNext = tmp;
		pCurrent = tmp;
		}
		Size++;
	}

	void InsLast(T a) {
		TLink<T> *tmp = new TLink<T>;
		tmp->value = a;
		tmp->pNext = pStop;
		if (pFirst == pStop) {
			pFirst = pLast = pCurrent = tmp;
			Pos = 0;
		}
		else {
			pLast->pNext = tmp;
			pLast = tmp;
		}
		Size++;
	}

	void delFirst() {
		if (Size == 1) {
			delete pFirst;
			pFirst = pLast = pCurrent = pPrevious = pStop;
		}
		else {
			TLink <T> * tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		Size--;
		Pos--;
	}

	void delCurrent() {
		if (pCurrent == pFirst)  delFirst;
		else {
			pCurrent = pCurrent->pNext;
			delete pPrevious->pNext;
			pPrevious->pNext = pCurrent;
			Size--;
		}
	}

	void Reset() {
		pCurrent = pFirst;
		Pos = 0;
		pPrevious = pStop;
	}

	void GoNext() {
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
		Pos++;
	}

	bool isEnd() {
		if (pCurrent == pStop) return true;
		else return false;
	}

	T GetCurrentValue() {
		return pCurrent->value;
	}

	T GetNextValue() {
		return pNext->value;
	}

	void Sort(T a) {
		TList<int> l;
		if (pFirst == pStop || a < pFirst->value ) {
			InsFirst(a); return;
		}
		if (a >= pLast->value) {
			InsLast(a); return;
		}
		for (Reset(); !isEnd(); GoNext()) {
			if (pCurrent->value > a) {
				InsCurrent(a);
				return;
			}
		}
	}

};