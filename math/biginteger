import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	public static void main(String[] args){
		Task solver = new Task();
		solver.init();
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
		int T; T = cin.nextInt();
		for(int kase = 1; kase <= T; ++kase){
			int n = cin.nextInt();
			BigInteger k = cin.nextBigInteger();
			System.out.println(solver.dfs(n,k));
		}
	}
}

class Task {
	BigInteger mod = new BigInteger("258280327");
	BigInteger[] len = new BigInteger[1001];
	public void init(){
		len[0] = BigInteger.ZERO;
		len[1] = len[2] = BigInteger.ONE;
		for(int i = 3; i <= 1000; ++i)
			len[i] = len[i-1].add(len[i-2]);
	}
	public BigInteger dfs(int n,BigInteger k){
		if(n < 4) return BigInteger.ZERO;
		if(k.equals(len[n]))
			return len[n-2].mod(mod);
		else if(k.compareTo(len[n-1]) != 1)
			return dfs(n-1,k).mod(mod);
		else
			return k.subtract(len[n-1]).add(len[n-3]).mod(mod);
	}
}
