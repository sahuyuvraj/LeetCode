class Solution {
public:
    int clumsy(int n) {
// n 		c_fact(n)	Difference
// 1		1			0
// 2		2			0
// 3		6			3
// 4		7			3
// 5		7			2
// 6		8			2
// 7		6			-1
// 8		9			1
// 9		11			2
// 10		12			2
// 11		10			-1
// 12		13			1
// 13		15			2
        
        //as observed
        
        if(n<3)return n;
        if(n<5)return n+3;
         
        int r=n%4;
        if(!r)return n+1;
        
        if(r==3)return n-1;
        
        return n+2;
        
    }
};