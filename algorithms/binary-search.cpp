   int binarySearch(vector<int>& arr, int target, int start, int end){
        if (start < 0 || end >= arr.size()) {
            if(target == arr[0]) {
                return 0;
            }
            if(target == arr[arr.size() - 1]) {
                return arr.size() - 1;
            }
            
            return -1;
        }
        if (start == end) {
            if (arr[start] == target) {
                return start;
            }
            return -1;
        }
        int mid = (start + end) / 2;
        if(arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            binarySearch(arr, target, start , mid  - 1);
        }
        if (arr[mid] < target) {
           binarySearch(arr, target, mid + 1 , end); 
        }
        return -1; 
    }
