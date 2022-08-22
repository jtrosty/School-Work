#include <stdio.h>
#include <iostream>
#include <vector>
#include "addTwoNum.h"
#include "LongestSubStringNoRepeat.h"
#include "MedianTwoSortedArrays.h"
#include "LongestPalindrom.h"
#include "LeetCodeDay1.h"
#include "SolutionStringArray.h"

using std::vector;

int main(void) {
    ///////////  number to Words TEST CODE
    SolutionNumberToWords NumToWords;
    std::cout << "Num To words: " << NumToWords.numberToWords(0) << std::endl;
    std::cout << "Num To words: " << NumToWords.numberToWords(1) << std::endl;
    std::cout << "Num To words: " << NumToWords.numberToWords(100) << std::endl;
    std::cout << "Num To words: " << NumToWords.numberToWords(123) << std::endl;
    std::cout << "Num To words: " << NumToWords.numberToWords(12345) << std::endl;
    std::cout << "Num To words: " << NumToWords.numberToWords(1234567) << std::endl;
    std::cout << "Num To words: " << NumToWords.numberToWords(1234567890) << std::endl;

    /*
    ///////////  First Unique CharTEST CODE
    SolutionFirstUniqueCharacter FirstUnique;
    std::cout << "First unique char at: " << FirstUnique.firstUniqChar("leetcode") << std::endl;
    std::cout << "First unique char at: " << FirstUnique.firstUniqChar("s") << std::endl;
    std::cout << "First unique char at: " << FirstUnique.firstUniqChar("aabb") << std::endl;


    ///////////  Most Common Word TEST CODE
    SolutionMostCommonWord MostCommonWord;
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    string paragraph2 = "Bob";
    vector<string> banned {"hit"};
    std::cout << "Most commond word: " << MostCommonWord.mostCommonWord(paragraph, banned) << std::endl;
    std::cout << "Most commond word: " << MostCommonWord.mostCommonWord(paragraph2, banned) << std::endl;



    int whatIsTheHappiestNumber;
    /////////// Spiral Order TEST CODE
    SolutionSpiralOrder spiral;
    vector< vector <int> > matrix {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    auto result = spiral.spiralOrder(matrix); 
    for (int i = 0; i < result.size(); i++) {
        std::cout << result.at(i) << " ";
    }
        std::cout << std::endl;

    /////////// Happy Number TEST CODE

    SolutionLeetCode75Day1 happyNumber;
    printf("Results are: %i\n",happyNumber.isHappy(2)); 
    printf("Results are: %i\n",happyNumber.isHappy(19)); 
    printf("Results are: %i\n",happyNumber.isHappy(1)); 
    /////////// LongestPalindrome TEST CODE
    */

    /*
    SolutionLongestPalindrome testPalindrom;

    printf("Results are: %s\n", testPalindrom.longestPalindrome("xaabacxcabaaxcabaax"));
    printf("Results are: %s\n", testPalindrom.longestPalindrome("aaaaa"));
    printf("Results are: %s\n", testPalindrom.longestPalindrome("aaaa"));
    printf("Results are: %s\n", testPalindrom.longestPalindrome("babad"));
    */


    
    /////////// Median Sorted Array TEST CODE
    /*
    printf("We are running Full bore \n");
    SolutionMedianSortedArrays testCodeMedian;
    std::vector<int> nums1 = { 1};
    std::vector<int> nums2 = { 1};
    std::vector<int> nums3 = { 1, 2};
    std::vector<int> nums4 = { 3, 4};
    printf("Results are: %f\n", testCodeMedian.findMedianSortedArrays(nums1, nums2));
    printf("Results are: %f\n", testCodeMedian.findMedianSortedArrays(nums2, nums1));
    printf("Results are: %f\n", testCodeMedian.findMedianSortedArrays(nums3, nums4));
    printf("Results are: %f\n", testCodeMedian.findMedianSortedArrays(nums4, nums3));
    */
    /////////// LONGEST SUB STRING NO REPEATE TEST CODE
    /*
    Solution testCast;
    printf("Results are: %i\n", testCast.lengthOfLongestSubstring("ab"));
    printf("Results are: %i\n", testCast.lengthOfLongestSubstring("dvdf"));
    printf("Results are: %i\n", testCast.lengthOfLongestSubstring("bbbbbbb"));
    printf("Results are: %i\n", testCast.lengthOfLongestSubstring("pwwkew"));
    */
    
    /////////// ADD TWO NUMBERS TEST CODE
    /*
    SolutionAddTwoNumbers solAddTwoNum;
    SolutionAddTwoNumbers::ListNode* list2 = new SolutionAddTwoNumbers::ListNode(6);
    list2->next = new SolutionAddTwoNumbers::ListNode(4);
    list2->next->next = new SolutionAddTwoNumbers::ListNode(9);
    SolutionAddTwoNumbers::ListNode* list1 = new SolutionAddTwoNumbers::ListNode(4);
    list1->next = new SolutionAddTwoNumbers::ListNode(9);
    SolutionAddTwoNumbers::ListNode* result = solAddTwoNum.addTwoNumbers(list1, list2);

    while (result != nullptr) {
        printf("%i ", result->val);
        result = result->next;
    }
    printf("\n");
    printf("iok\n");
    */

    return 0;
}