#include <stdio.h>

int gcd(int a, int b)
{
if (b)
return gcd(b, a % b);
else
return a;

}

int pseudo(int r, int n)
{
/* Integer N′ in [0, R − 1] such that NN′ ≡ −1 mod R,*/
for(int i = 0; i < r - 1 ; i++)
{

   if(n * i == -1 % r)
   {
       return i;
       break;
   }

}

return 0;
}

void monto(int r, int n)
{

    /*what curve are we going to use? The user will give the values */

int nx;


int T;

/*  Integer T in the range [0, RN − 1].*/
T = (r*n) - 1;

/*nx must be a pseudo prime*/
nx = pseudo(r, n);

/*These values will be used as storage for answers*/
int s, t, m;

float fx = (float) T;






/*Integers R and N with gcd(R, N) = 1*/
/*we will add the one if statement line later*/




if(gcd(r, n) == 1)
{
    
    /* m ← ((T mod R)N′) mod R*/
    m = ((T % r ) * nx) % r;
    
    /*  t ← (T + mN) / R*/
    t = ((T + (m * n)) / r);
    
    if(t >= n)
    {

    s = t - n;
        
    }
    else
    {
        
    s = t;

    }
    
}


if(s <= n - 1 && 0 <= s && s == (int) (1 / (float) r * fx) % n && s % 2 == 1)
{
    printf("%d", s);
}
}

void main()
{

monto(5, 4);
}
