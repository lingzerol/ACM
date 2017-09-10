/*快速幂程序及详解*/

unsigned Power(unsigned n, unsigned p)  
{ // 计算n的p次方    
 unsigned odd = 1; //oddk用来计算“剩下的”乘积     
 while (p > 1)   
   { // 一直计算到指数小于或等于1        
   	if (( p & 1 )!=0)      
    { // 判断p是否奇数，偶数的最低位必为0             
     odd *= n; // 若odd为奇数，则把“剩下的”乘起来     
 }      
        n *= n; // 主体乘方      
         p /= 2; // 指数除以2     
     }    
           return n * odd; // 最后把主体和“剩下的”乘起来作为结果 
       } 

