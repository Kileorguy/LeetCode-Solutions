class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();

        int total = size1+size2;
        int skipCount;
        bool even = total % 2 == 0;

        if(even){
            skipCount = total/2-1;
        }else{
            skipCount = total/2;
        }

        cout << total << " "+to_string(skipCount) << endl;
        int l = 0;
        int r = 0;
        int count = 0;
        while(count < skipCount && l < size1 && r < size2){
            if(nums1[l] < nums2[r]){
                l++;
            }else{
                r++;
            }
            count+=1;
        }

        while(count < skipCount && l < size1){
            l++;
            count++;
        }

        while(count < skipCount && r < size2){
            r++;
            count++;
        }
        // cout<< l << " " + to_string(size1) << endl;
        // cout<< r << " " + to_string(size2) << endl;
        double ans=0;
        if(even){
            for(int i=0;i<2;i++){
                if(l < size1 && r < size2){
                    if(nums1[l] < nums2[r]){
                        ans += nums1[l];
                        l++;
                    }else{
                        ans += nums2[r];
                        r++;
                    }
                }else if(l < size1){
                    ans += nums1[l];
                    l++;
                }else if(r<size2){
                    ans+=nums2[r];
                    r++;
                }
                
            }
            ans = ans / 2.0;
        }else{
            if(l < size1 && r < size2){
                if(nums1[l] < nums2[r]){
                    ans += nums1[l];
                    l++;
                }else{
                    ans += nums2[r];
                    r++;
                }
                
            }else if(l < size1){
                ans += nums1[l];
                l++;
            }else if(r<size2){
                ans+=nums2[r];
                r++;
            }

        }
        return ans;


    }
};