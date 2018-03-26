
public class Fibonacci {
static int a = 1;
static int b = 0;
static String ret = "";


public static String fib(int limit)
{

for (int i = 1; i <= limit; i++) 
   {
    b = b + a;
    a = b - a;
    ret += b + " ";
   }
return ret;
}

}
