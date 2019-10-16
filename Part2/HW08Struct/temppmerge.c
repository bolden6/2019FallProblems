// Implimentation of the Merge Sort Algorithm
// with O(nlogn) complexity in the worst case
// and  O(nlogn) complexity in the best case
template <typename T>
void List<T>::merge_sort(int left, int right){
    T temp;
​
    comparisons_++;
    if(left < right){
​
        int mid = left + (right - left) / 2; // prevents overflow
​
        loops_++;
        merge_sort(left, mid);
        merge_sort(mid+1, right);
​
        vector<T> tempLeft, tempRight;
​
        int ls = mid - left + 1;
        int rs = right - mid;

        for(int l = 0; l < ls; l++){
            swaps_++;
            tempLeft.push_back(list_[left+l]);
        }
        for(int r = 0; r < rs; r++){
            swaps_++;
            tempRight.push_back(list_[mid+r+1]);
        }

        int i = 0;
        int j = 0;
        int k = left;

        while(i < ls && j < rs){
            comparisons_++;
            if(tempLeft[i] <= tempRight[j]){
                list_[k] = tempLeft[i];
                i++;
            }
            else{
                list_[k] = tempRight[j];
                j++;
            }
            k++;
        }
​
        // add leftovers
        while(i < ls){
            list_[k] = tempLeft[i];
            i++;
            k++;
        }
        while(j < rs){
            list_[k] = tempRight[j];
            j++;
            k++;
        }
​
    }
​
