/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int x;
    static int y;
    static int[][] map;
    static int[] dx = new int[]{-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dy = new int[]{-1, 0, 1, -1, 1, -1, 0, 1};
    static int result = 0; // 총 섬의 개수

    static void bfs(int n, int m) {
        map[n][m] = 0;
        for (int i = 0; i < 8; i++) {
            int midY = n + dy[i];
            int midX = m + dx[i];
            if (midX < x && midX >= 0 && midY < y && midY >= 0) {
                if (map[midY][midX] == 1) { // 주변에 섬이 있다면
                    bfs(midY, midX);
                }
            }
        }
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	    StringBuilder sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(in.readLine(), " ");
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
            
            if(x==0 && y == 0) break;
            
            map = new int[y][x];

            for (int i = 0; i < y; i++) {
                st = new StringTokenizer(in.readLine());
                for (int j = 0; j < x; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    if (map[i][j] == 1) { // 섬이 하나라도 있으면
                        bfs(i, j);
                        result += 1;
                    }
                }
            }

            System.out.println(result);
            result = 0;
        }
    }
}