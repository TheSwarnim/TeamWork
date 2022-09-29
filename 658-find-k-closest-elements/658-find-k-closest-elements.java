class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int i = 0, j = arr.length - 1;
        
        while(i < j && x >= arr[i]){
            i++;
        }
        i--;
        j = i+1;
        
        LinkedList<Integer> res = new LinkedList<>();
        while(k-- > 0){
            if(i < 0){
                res.addLast(arr[j++]);
            } else if(j >= arr.length){
                res.addFirst(arr[i--]);
            } else {
                // System.out.println(k + " " + arr[i] + " " + arr[j] + " " + x);
                if((x - arr[i]) <= (arr[j] - x)){
                    res.addFirst(arr[i--]);
                } else {
                    res.addLast(arr[j++]);
                }
            }
        }
        
        return res;
    }
}