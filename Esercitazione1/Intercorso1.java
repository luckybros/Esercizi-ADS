package Esercitazione1;

public class Intercorso1 {

    public void MergeSort(int[] array, int l, int r) {
        if(l < r) {
            int q = (l+r)/2;
            MergeSort(array, l, q);
            MergeSort(array, q+1, r);
            Merge(array, l, q, r);
        }
    }

    public void Merge(int[] array, int l, int q, int r) {
        int n1 = q - l + 1;
        int n2 = r - q;

        int lowHalf[] = new int[n1];
        int highHalf[] = new int[n2];

        int k = l;
        int i, j;

        for (i = 0; i < n1; i++) {
            lowHalf[i] = array[k];
            k++;
        }

        for (j = 0; j < n2; j++) {
            highHalf[j] = array[k];
            k++;
        }

        k = l;
        i = j = 0;

        while (i < n1 && j < n2) {
            if (lowHalf[i] <= highHalf[j]) {
                array[k] = lowHalf[i];
                i++;
            } else {
                array[k] = highHalf[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            array[k] = lowHalf[i];
            i++;
            k++;
        }

        while (j < n2) {
            array[k] = highHalf[j];
            j++;
            k++;
        }
    }

    public int MedianCalculate(int[] nums) {
        int median;
        int distanceSum;
       
        median = Median(nums);
        distanceSum = DistanceSum(nums, median);

        return distanceSum;
    }

    public int Median(int[] nums) {
        int median;
        int size = nums.length;
        if(size % 2 == 0) 
            median = (nums[(size)/2] + nums[((size)/2)-1])/2;
        else 
            median = nums[size/2];
        return median;
    }

    public int DistanceSum(int[] nums, int a) {
        int distanceSum = 0;
        for(int i = 0; i < nums.length; i++) 
            distanceSum += Math.abs(nums[i] - a);
        
        return distanceSum;
    }
    public static void main(String[] arg) {
        Intercorso1 solution = new Intercorso1();

        int array1[] = {2, 4};
        int array2[] = {1, 2, 4, 3};

        solution.MergeSort(array2, 0, array2.length-1);

        for(int i = 0; i < array2.length; i++)
            System.out.println(array2[i]);

        System.out.println(solution.MedianCalculate(array1));
        System.out.println(solution.MedianCalculate(array2));
    }
}
