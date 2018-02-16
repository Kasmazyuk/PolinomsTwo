#pragma once 
#include "THeadList.h" 

struct TMonom { 
	double coeff; 
	int x, y, z; 
}; 

template <class T> 
class TPolinom:public THeadList<TMonom> { 
public: 
	TPolinom() :THeadList<TMonom>() {
		pHead->value.coeff = 0; 
		pHead->value.z = -1; 
	}


	TPolinom(TMonom *mas, int size):THeadList<TMonom>(){ 
		for (int i = 0; i < size; i++) { 
			Sort(mas[i]); 
		}
	} 

	void operator *=(double k) { 
		for (Reset(); IsEnd(); GoNext()) { 
			pCurrent->val.coeff *= k; 
		} 
	} 

	void InsMonom(TMonom monom) { 
		for (Reset(); IsEnd(); GoNext()) { 
			if (monom == pCurrent->value) { 
				pCurrent->value.coeff += monom.coeff; 
		} 
			if (pCurrent->value.coeff == 0) { 
				delCurrent(); 
			return; 
		} 
		else { 
			if (monom > pCurrent->value) { 
				InsCurrent(monom); 
			return; 
			} 
		} 
	} 
	InsLast(monom); 
	} 

	void operator +=(TPolinom Q) { 
		for (Q.Reset; Q.IsEnd(); Q.GoNext()) { 
			InsMonom(Q.pCurrent->value); 
		} 
	}

};

