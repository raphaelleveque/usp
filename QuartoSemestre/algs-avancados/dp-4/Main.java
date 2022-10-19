import java.util.Scanner;
class Main {
    static public int lengthOfLIS(int[] arr) {
      int dp[]=new int[arr.length];
      for(int i=0;i<dp.length;i++){
          int max=0;
          for(int j=0;j<i;j++){
              if(arr[j]<arr[i]){
                  if(dp[j]>max){
                      max=dp[j];
                  }
              }
          }
         
          dp[i]=max+1;
          
      }
        int maxans=Integer.MIN_VALUE;
        for(int i=0;i<dp.length;i++){
            maxans=Math.max(maxans,dp[i]);
        }
        return maxans;
    }
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        int n = stdin.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = stdin.nextInt();
        System.out.println(lengthOfLIS(arr));
    }
}