/* LOGIC - we can sort the vector based on first index of the range. Now that they are sorted we know there is a possibility that the second range
can be contained in the first range, the third range in the second and so on but whether it contained or not is decided by the last index of the range.
If it is greater than the last index of all of its previous ranges then it is not contained else it is. Instead of checking for all previous ranges we 
can keep track of the max last index and check the current last index with that. If it smaller then this range is contained in one of the previous
ranges. Else we update the max last range. Now all of this can be done using a simple sort as it will sort the intervals vector according to 
the 0th index of range automatically. However problem may arise when 0th index of two ranges are same. In that case we need to sort in dec manner according
to 1st index of range. And that is why we use a comparator.
*/

class Solution {
public:
    static bool comparator(std::vector<int> a, std::vector<int> b){
        if(a[0]!=b[0]) return a[0]<b[0];
        else{
            return a[1] > b[1];
        }
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int _max = INT_MIN;
        int count = 0;
        std::sort(intervals.begin(), intervals.end(), comparator);
        for(int i=0; i<intervals.size(); i++){
            std::vector<int> range = intervals[i];
            if(range[1]<=_max) count++;
            else _max = range[1];
        }
        return intervals.size() - count;
    }
};
