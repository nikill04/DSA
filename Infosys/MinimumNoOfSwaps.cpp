/* MINIMUM NO OF ADJACENT SWAPS TO CONVERT A STRING INTO IT'S ANAGRAM

we have two strings A and B, each of same length N. and no string has repeating characters. Now we have to do adjacent swaps in string A such that it should be transformed into string B. (Adjacent Swaps are swapping adjacent characters in the string, only adjacent swaps are allowed here). we should return minimum no of adjacent swaps. if not possible should return -1;   */

// ANAGRAM : A word or phrase that's formed by rearranging the letters of another word or phrase.


// Function that returns true if A and B are anagrams of each other
bool isAnagram(vector<int> & A, vector<int> & B) {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	if(A == B) return true;
	return false;
}

int minSwaps(vector<int> & A, vector<int> B, int N) {
	if(!isAnagram(A, B)) return -1;
	
	int i = 0, j = 0;
	int result = 0;

    // Iterate over the first string and convert every element equal to the second string
	while(j < N) {		
		i = j;

        // Find index element of first string which is equal to the ith element of second string
		while(A[i] != B[j]) {
			i++;
		}
		
        // Swap adjacent elements in first string so that element at ith position becomes equal
		while(i > j) {
			char temp = A[i];
			A[i] = A[i - 1];
			A[i - 1] = temp;
			
			i--;
			result++;
		}

		j++;
	}
	return result;
}





// The Below recursion logic is not correct and also not optimal. Need to implement using greedy approach.
// int mini = INT_MAX;

// void helper(vector<int> A, vector<int> & B, int maxRecur, int noOfSwaps, int index) {
//     if(A == B) {
//         mini = min(mini, noOfSwaps);
//         return;
//     } 
//     if(maxRecur == 0) {
//         return;
//     }

//     int backIndex = A.size() - 1 - index;
//     int temp1 = A[index];
//     int temp2 = A[index + 1];
//     int temp3 = A[backIndex];
//     int temp4 = A[backIndex - 1];

//     if(index != A.size() - 1) {
//         helper(A, B, maxRecur, noOfSwaps, index + 1);

//         A[index] = temp2;
//         A[index + 1] = temp1;
//         helper(A, B, maxRecur - 1, noOfSwaps + 1, index + 1);
//     }
//     if(backIndex != 0) {
//         helper(A, B, maxRecur, noOfSwawps, backIndex - 1);

//         A[backIndex] = temp4;
//         A[backIndex - 1] = temp3;
//         helper(A, B, maxRecur - 1, noOfSwaps + 1, backIndex - 1);
//     }

//     return;
// }

// int minSwaps(vector<int> & A, vector<int> & B, int N) {
//     map<char, int> mpp1;
//     map<char, int> mpp2;

//     for(auto num : A) {
//         mpp1[num]++;
//     }
//     for(auto num : B) {
//         mpp2[num]++;
//     }

//     if(mpp1 != mpp2) {
//         return -1;
//     } else {
//         helper(A, B, 3 * N, 0, 0);
//         return mini;
//     }
// }