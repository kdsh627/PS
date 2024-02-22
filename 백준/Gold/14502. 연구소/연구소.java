import java.util.*;

public class Main {
    static int n,m;
    static int[][] board;
    static int[][] copyBoard;
    static int[] dx = {-1,0,1,0};
    static int[] dy = {0,1,0,-1};
    static int answer = 0;
    static Queue<Point> q = new LinkedList<>();

    static class Point {
        int x;
        int y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static void BFS() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (board[i][j] == 2) {
                    q.offer(new Point(i,j));
                }
            }
        }

        for (int i=0; i<n; i++) {
            copyBoard[i] = board[i].clone();
        }
        while(!q.isEmpty()) {
            Point tmp = q.poll();
            for(int i=0; i<4; i++) {
                int nx = dx[i] + tmp.x;
                int ny = dy[i] + tmp.y;
                if(nx>=0 && nx<n && ny>=0 && ny<m && copyBoard[nx][ny] == 0) {
                    q.offer(new Point(nx,ny));
                    copyBoard[nx][ny] = 2;
                }
            }

        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (copyBoard[i][j] == 0) cnt++;
            }
        }
        answer = Math.max(answer, cnt);

    }

    static void DFS(int v) {
        if (v==3) {
            BFS();
            return;
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = 1;
                    DFS(v+1);
                    board[i][j] = 0;
                }
            }
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        board = new int[n][m];
        copyBoard = new int[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                board[i][j] = sc.nextInt();
            }
        }
        DFS(0);


        System.out.print(answer);
    }
}