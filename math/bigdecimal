import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
		int T; T = cin.nextInt();
		BigDecimal[] x = new BigDecimal[103];
		for(int kase = 1; kase <= T; ++kase){
			int n = cin.nextInt();
			boolean flag = true, allzero = true;
			for(int i = 0; i < n; ++i){
				x[i] = cin.nextBigDecimal();
				if(x[i].equals(BigDecimal.ZERO)){
					flag = false;
				}
				else{
					allzero = false;
				}
			}
			if(allzero){
				System.out.println("Yes");
				continue;
			}
			if(!flag){
				System.out.println("No");
				continue;
			}
			if(n <= 2){
				System.out.println("Yes");
				continue;
			}
			for(int i = 1; i < n - 1; ++i){
				if(x[i-1].multiply(x[i+1]).equals(x[i].multiply(x[i])) == false){
					flag = false; break;
				}//use multiply to avoid loss of precision
			}
			System.out.println(flag ? "Yes" : "No");
		}
	}
}
