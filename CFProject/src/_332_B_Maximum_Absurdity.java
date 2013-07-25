import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.util.Collections.*;
import java.io.*;

public class _332_B_Maximum_Absurdity {
	//->solution screencast http://youtu.be/oHg5SJYRHA0
	public void solve() {
		int n = ni(), k=ni();
		int []s= na(n);
		
		long [] cum = new long [n];
		cum[0]=s[0];
		for (int i = 1; i< n; i++) {
			cum[i] = cum[i-1]+s[i];
		}
		pr(cum);
		this.cum=cum;
		node ansIdx = new node(n-2*k,n-k);
		node ansCum = new node(sum(n-2*k, n-k-1),sum(n-k,n-1));
		long cumb= cum[n-1]-cum[n-k-1];
		node max=new node(sum(n-k,n-1),n-k);//val,idx
//		long maxB=ansCum.b;
		pr(cum, ansIdx, ansCum, max);
		for (int i = n-k-1; i >=k; i--) {
			long cur = sum(i,i+k-1);
			if(cur>=max.a){
				max.a=cur;
				max.b=i;
			}
			pr(max);
			if(ansCum.a+ansCum.b <= sum(i-k,i-1)+max.a){
				ansCum.a=sum(i-k,i-1);
				ansCum.b=max.a;
				ansIdx.a=i-k;
				ansIdx.b=max.b;
			}
		}
		out.println((ansIdx.a+1)+" "+(ansIdx.b+1));
	}
	long[] cum;
	long sum( int a, int b){
		return a<=0?cum[b]:cum[b]-cum[a-1];
	}
	class node {
		long a; long b;
		public node(long a, long b) {
			this.a=a;
			this.b=b;
		}
		@Override
		public String toString() {
			// TODO Auto-generated method stub
			return a+" "+b;
		}
		
	}
	
	// IO methods
		
	void run() throws Exception {
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		pr(System.currentTimeMillis() - s + "ms");
	}
	public static void main(String[] args) throws Exception {new _332_B_Maximum_Absurdity().run();}

	InputStream in=System.in;
	PrintWriter out=new PrintWriter(System.out);
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;

	private int readByte() {
		if (lenbuf == -1)
			throw new InputMismatchException();
		if (ptrbuf >= lenbuf) {
			ptrbuf = 0;
			try {
				lenbuf = in.read(inbuf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (lenbuf <= 0)
				return -1;
		}
		return inbuf[ptrbuf++];
	}

	private boolean isSpaceChar(int c) {return !(c >= 33 && c <= 126);}
	private int skip() {int b;while ((b = readByte()) != -1 && isSpaceChar(b));return b;}

	public String ns() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != // ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	public char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	public int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}
	
	
	public int ni() {
		int num = 0, b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}

		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	public long nl(){
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	void pr(Object... ob) {if (!oj)System.out.println(Arrays.deepToString(ob).replace("],", "],\n"));}
}

