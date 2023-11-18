import java.util.Scanner;

class Main {
    public static void main(String[] args) {

        long startTime = System.currentTimeMillis();
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] result_lst = new int[n+1];
        result_lst[1] = 0;


        for (int i = 2; i <= n; i++) { // 작은 거부터 채워나가)
            result_lst[i] = result_lst[i - 1] + 1; // 1로 뺀 결과와 관련
            
            if (i % 2 == 0) {
                result_lst[i] = Math.min(result_lst[i / 2] + 1, result_lst[i]); // 2로 나눈 결과와 관련
            }
            if (i % 3 == 0) {
                result_lst[i] = Math.min(result_lst[i / 3] + 1, result_lst[i]); // 3으로 나눈 결과와 관련
            }

        }
        System.out.println(result_lst[n]);
    }
}