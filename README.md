# LeetCode Solutions (C++)

Solutions to the first LeetCode problems in C++17, each with example-based tests.

## Repository structure

```
leetcode/
├── 0001_two_sum/
│   ├── problem.md   # problem statement, signature, examples
│   ├── solution.h   # class Solution with the method to implement
│   ├── test.cpp     # tests from the examples + minimal runner
│   └── Makefile     # builds and runs the tests
├── 0002_add_two_numbers/
├── ...
├── 0010_regular_expression_matching/
├── parallel/                  # C++ parallel programming exercises
│   ├── 01_thread_safe_counter/
│   ├── 02_producer_consumer/
│   └── ...
└── top_interview/             # top interview questions (big-tech + RU companies)
    ├── 0026_remove_duplicates_from_sorted_array/
    ├── 0049_group_anagrams/
    └── ...
```

Each problem folder is self-contained.

- `problem.md` — problem statement, method signature and examples (as on LeetCode).
- `solution.h` — `class Solution` with the method stub marked `// TODO: implement`.
- `test.cpp` — test cases from the examples; prints `[PASS]`/`[FAIL]` and a final summary.
- `Makefile` — builds and runs the tests.

## Conventions

- LeetCode-style `class Solution` signatures (copy-paste ready for the site).
- `#pragma once` in headers.
- C++17, compiled with `g++`.
- No external test framework — each `test.cpp` has a tiny self-contained runner.

## How to run

```bash
cd 0001_two_sum
make test     # build + run tests + print result
make clean    # remove the test binary
```

Tests fail (non-zero exit) until the function is implemented — that is expected.

## Problems

| # | Folder | Problem | Method signature | Status |
|---|--------|---------|------------------|--------|
| 1 | `0001_two_sum` | Two Sum | `vector<int> twoSum(vector<int>&, int)` | [solved](#) |
| 2 | `0002_add_two_numbers` | Add Two Numbers | `ListNode* addTwoNumbers(ListNode*, ListNode*)` | [solved](#) |
| 3 | `0003_longest_substring_without_repeating_characters` | Longest Substring Without Repeating Characters | `int lengthOfLongestSubstring(string)` | [solved](#) |
| 4 | `0004_median_of_two_sorted_arrays` | Median of Two Sorted Arrays | `double findMedianSortedArrays(vector<int>&, vector<int>&)` | [solved](#) |
| 5 | `0005_longest_palindromic_substring` | Longest Palindromic Substring | `string longestPalindrome(string)` | [solved](#) |
| 6 | `0006_zigzag_conversion` | Zigzag Conversion | `string convert(string, int)` | [solved](#) |
| 7 | `0007_reverse_integer` | Reverse Integer | `int reverse(int)` | [solved](#) |
| 8 | `0008_string_to_integer_atoi` | String to Integer (atoi) | `int myAtoi(string)` | [solved](#) |
| 9 | `0009_palindrome_number` | Palindrome Number | `bool isPalindrome(int)` | [solved](#) |
| 10 | `0010_regular_expression_matching` | Regular Expression Matching | `bool isMatch(string, string)` | [solved](#) |
| 11 | `0011_container_with_most_water` | Container With Most Water | `int maxArea(vector<int>&)` | [solved](#) |
| 12 | `0012_integer_to_roman` | Integer to Roman | `string intToRoman(int)` | [solved](#) |
| 13 | `0013_roman_to_integer` | Roman to Integer | `int romanToInt(string)` | `stub` |
| 14 | `0014_longest_common_prefix` | Longest Common Prefix | `string longestCommonPrefix(vector<string>&)` | `stub` |
| 15 | `0015_3sum` | 3Sum | `vector<vector<int>> threeSum(vector<int>&)` | `stub` |
| 16 | `0016_3sum_closest` | 3Sum Closest | `int threeSumClosest(vector<int>&, int)` | `stub` |
| 17 | `0017_letter_combinations_of_a_phone_number` | Letter Combinations of a Phone Number | `vector<string> letterCombinations(string)` | `stub` |
| 18 | `0018_4sum` | 4Sum | `vector<vector<int>> fourSum(vector<int>&, int)` | `stub` |
| 19 | `0019_remove_nth_node_from_end_of_list` | Remove Nth Node From End of List | `ListNode* removeNthFromEnd(ListNode*, int)` | `stub` |
| 20 | `0020_valid_parentheses` | Valid Parentheses | `bool isValid(string)` | `stub` |

## Parallel Programming (C++)

A separate block of exercises on C++17 concurrency. Each task is a self-contained
folder under `parallel/` with the same layout (`problem.md`, `solution.h`, `test.cpp`,
`Makefile`) but compiled with `-pthread`.

Run them from the repo root with `make test` (runs both blocks), or individually:

```bash
cd parallel/01_thread_safe_counter
make test
```

| # | Folder | Task | Interface | Status |
|---|--------|------|-----------|--------|
| 1 | `01_thread_safe_counter` | Thread-safe counter (mutex vs atomic) | `MutexCounter` / `AtomicCounter` | [solved](#) |
| 2 | `02_producer_consumer` | Producer-consumer (bounded queue) | `BoundedQueue` | `stub` |
| 3 | `03_thread_pool` | Thread pool | `ThreadPool` | `stub` |
| 4 | `04_parallel_reduce` | Parallel sum (reduce) | `parallelSum(...)` | `stub` |
| 5 | `05_read_write_lock` | Read-write lock (`shared_mutex`) | `ReadWriteLockDemo` | `stub` |
| 6 | `06_two_thread_alternate` | Alternating output of two threads | `alternatePrint(...)` | `stub` |
| 7 | `07_dining_philosophers` | Dining philosophers | `DiningPhilosophers` | `stub` |

<!-- TOP_INTERVIEW_START -->
## Top Interview Questions

Top algorithms asked by big-tech companies: LeetCode Top Interview 150 / Blind 75, extended with commonly asked problems from top Russian IT companies. Problems already solved at the repository root are linked (no duplicated code); everything else lives in `top_interview/<number>_<slug>/`.

Each task is self-contained (`problem.md`, `solution.h`, `test.cpp`, `Makefile`). Run from the repo root with `make test`, or individually: `cd top_interview/<folder> && make test`.

| # | Problem | Difficulty | Topic | Where | RU companies | Status |
|---|---------|-----------|-------|-------|--------------|--------|
| 1 | Two Sum | Easy | Array/String | [0001_two_sum](../0001_two_sum/) | Яндекс, VK, Tinkoff | [solved](#) |
| 2 | Add Two Numbers | Medium | Linked List | [0002_add_two_numbers](../0002_add_two_numbers/) | Яндекс | [solved](#) |
| 3 | Longest Substring Without Repeating Characters | Medium | Sliding Window | [0003_longest_substring_without_repeating_characters](../0003_longest_substring_without_repeating_characters/) | Яндекс, Ozon | [solved](#) |
| 4 | Median of Two Sorted Arrays | Hard | Array/String | [0004_median_of_two_sorted_arrays](../0004_median_of_two_sorted_arrays/) | Яндекс | [solved](#) |
| 5 | Longest Palindromic Substring | Medium | DP | [0005_longest_palindromic_substring](../0005_longest_palindromic_substring/) | Яндекс, VK | [solved](#) |
| 6 | Zigzag Conversion | Medium | Array/String | [0006_zigzag_conversion](../0006_zigzag_conversion/) | — | [solved](#) |
| 11 | Container With Most Water | Medium | Two Pointers | [0011_container_with_most_water](../0011_container_with_most_water/) | Яндекс | [solved](#) |
| 12 | Integer to Roman | Medium | Array/String | [0012_integer_to_roman](../0012_integer_to_roman/) | — | [solved](#) |
| 13 | Roman to Integer | Easy | Array/String | [0013_roman_to_integer](../0013_roman_to_integer/) | — | `stub` |
| 14 | Longest Common Prefix | Easy | Array/String | [0014_longest_common_prefix](../0014_longest_common_prefix/) | Яндекс | `stub` |
| 15 | 3Sum | Medium | Two Pointers | [0015_3sum](../0015_3sum/) | Яндекс, Tinkoff | `stub` |
| 17 | Letter Combinations of a Phone Number | Medium | Backtracking | [0017_letter_combinations_of_a_phone_number](../0017_letter_combinations_of_a_phone_number/) | Яндекс | `stub` |
| 19 | Remove Nth Node From End of List | Medium | Linked List | [0019_remove_nth_node_from_end_of_list](../0019_remove_nth_node_from_end_of_list/) | Яндекс | `stub` |
| 20 | Valid Parentheses | Easy | Stack | [0020_valid_parentheses](../0020_valid_parentheses/) | Яндекс, Tinkoff, VK | `stub` |
| 21 | Merge Two Sorted Lists | Easy | Linked List | `0021_merge_two_sorted_lists` | Яндекс | `stub` |
| 22 | Generate Parentheses | Medium | Backtracking | `0022_generate_parentheses` | Яндекс | `stub` |
| 23 | Merge k Sorted Lists | Hard | Divide & Conquer | `0023_merge_k_sorted_lists` | Яндекс | `stub` |
| 25 | Reverse Nodes in k-Group | Hard | Linked List | `0025_reverse_nodes_in_k_group` | Яндекс | `stub` |
| 26 | Remove Duplicates from Sorted Array | Easy | Array/String | `0026_remove_duplicates_from_sorted_array` | Яндекс | `stub` |
| 27 | Remove Element | Easy | Array/String | `0027_remove_element` | Яндекс | `stub` |
| 30 | Substring with Concatenation of All Words | Hard | Sliding Window | `0030_substring_with_concatenation_of_all_words` | — | `stub` |
| 33 | Search in Rotated Sorted Array | Medium | Binary Search | `0033_search_in_rotated_sorted_array` | Яндекс | `stub` |
| 36 | Valid Sudoku | Medium | Matrix | `0036_valid_sudoku` | Яндекс | `stub` |
| 39 | Combination Sum | Medium | Backtracking | `0039_combination_sum` | Яндекс | `stub` |
| 46 | Permutations | Medium | Backtracking | `0046_permutations` | Яндекс | `stub` |
| 48 | Rotate Image | Medium | Matrix | `0048_rotate_image` | — | `stub` |
| 49 | Group Anagrams | Medium | Hashmap | `0049_group_anagrams` | Яндекс | `stub` |
| 52 | N-Queens II | Hard | Backtracking | `0052_n_queens_ii` | — | `stub` |
| 53 | Maximum Subarray | Medium | Kadane | `0053_maximum_subarray` | Яндекс, Tinkoff | `stub` |
| 54 | Spiral Matrix | Medium | Matrix | `0054_spiral_matrix` | Яндекс | `stub` |
| 55 | Jump Game | Medium | Array/String | `0055_jump_game` | Яндекс | `stub` |
| 56 | Merge Intervals | Medium | Intervals | `0056_merge_intervals` | Яндекс | `stub` |
| 57 | Insert Interval | Medium | Intervals | `0057_insert_interval` | Яндекс | `stub` |
| 58 | Length of Last Word | Easy | Array/String | `0058_length_of_last_word` | — | `stub` |
| 61 | Rotate List | Medium | Linked List | `0061_rotate_list` | — | `stub` |
| 62 | Unique Paths | Medium | DP | `0062_unique_paths` | Яндекс | `stub` |
| 63 | Unique Paths II | Medium | DP | `0063_unique_paths_ii` | — | `stub` |
| 64 | Minimum Path Sum | Medium | DP | `0064_minimum_path_sum` | Яндекс | `stub` |
| 70 | Climbing Stairs | Easy | DP | `0070_climbing_stairs` | Яндекс | `stub` |
| 71 | Simplify Path | Medium | Stack | `0071_simplify_path` | — | `stub` |
| 72 | Edit Distance | Medium | DP | `0072_edit_distance` | Яндекс | `stub` |
| 73 | Set Matrix Zeroes | Medium | Matrix | `0073_set_matrix_zeroes` | — | `stub` |
| 74 | Search a 2D Matrix | Medium | Binary Search | `0074_search_a_2d_matrix` | — | `stub` |
| 76 | Minimum Window Substring | Hard | Sliding Window | `0076_minimum_window_substring` | Яндекс | `stub` |
| 77 | Combinations | Medium | Backtracking | `0077_combinations` | — | `stub` |
| 79 | Word Search | Medium | Backtracking | `0079_word_search` | Яндекс | `stub` |
| 80 | Remove Duplicates from Sorted Array II | Medium | Array/String | `0080_remove_duplicates_from_sorted_array_ii` | Яндекс | `stub` |
| 82 | Remove Duplicates from Sorted List II | Medium | Linked List | `0082_remove_duplicates_from_sorted_list_ii` | — | `stub` |
| 84 | Largest Rectangle in Histogram | Hard | Stack | `0084_largest_rectangle_in_histogram` | Яндекс | `stub` |
| 88 | Merge Sorted Array | Easy | Array/String | `0088_merge_sorted_array` | Яндекс | `stub` |
| 91 | Decode Ways | Medium | DP | `0091_decode_ways` | Яндекс | `stub` |
| 92 | Reverse Linked List II | Medium | Linked List | `0092_reverse_linked_list_ii` | — | `stub` |
| 97 | Interleaving String | Medium | DP | `0097_interleaving_string` | — | `stub` |
| 98 | Validate Binary Search Tree | Medium | BST | `0098_validate_binary_search_tree` | Яндекс | `stub` |
| 100 | Same Tree | Easy | Binary Tree | `0100_same_tree` | — | `stub` |
| 101 | Symmetric Tree | Easy | Binary Tree | `0101_symmetric_tree` | — | `stub` |
| 102 | Binary Tree Level Order Traversal | Medium | Binary Tree BFS | `0102_binary_tree_level_order_traversal` | Яндекс | `stub` |
| 103 | Binary Tree Zigzag Level Order Traversal | Medium | Binary Tree BFS | `0103_binary_tree_zigzag_level_order_traversal` | — | `stub` |
| 104 | Maximum Depth of Binary Tree | Easy | Binary Tree | `0104_maximum_depth_of_binary_tree` | Яндекс | `stub` |
| 105 | Construct Binary Tree from Preorder and Inorder Traversal | Medium | Binary Tree | `0105_construct_binary_tree_from_preorder_and_inorder_traversal` | — | `stub` |
| 106 | Construct Binary Tree from Inorder and Postorder Traversal | Medium | Binary Tree | `0106_construct_binary_tree_from_inorder_and_postorder_traversal` | — | `stub` |
| 108 | Convert Sorted Array to Binary Search Tree | Easy | Divide & Conquer | `0108_convert_sorted_array_to_binary_search_tree` | — | `stub` |
| 112 | Path Sum | Easy | Binary Tree | `0112_path_sum` | — | `stub` |
| 114 | Flatten Binary Tree to Linked List | Medium | Binary Tree | `0114_flatten_binary_tree_to_linked_list` | — | `stub` |
| 120 | Triangle | Medium | DP | `0120_triangle` | — | `stub` |
| 121 | Best Time to Buy and Sell Stock | Easy | Array/String | `0121_best_time_to_buy_and_sell_stock` | Яндекс, Tinkoff | `stub` |
| 122 | Best Time to Buy and Sell Stock II | Medium | Array/String | `0122_best_time_to_buy_and_sell_stock_ii` | Яндекс | `stub` |
| 124 | Binary Tree Maximum Path Sum | Hard | Binary Tree | `0124_binary_tree_maximum_path_sum` | Яндекс | `stub` |
| 125 | Valid Palindrome | Easy | Two Pointers | `0125_valid_palindrome` | Яндекс | `stub` |
| 127 | Word Ladder | Hard | Graph BFS | `0127_word_ladder` | Яндекс | `stub` |
| 128 | Longest Consecutive Sequence | Medium | Hashmap | `0128_longest_consecutive_sequence` | Яндекс | `stub` |
| 129 | Sum Root to Leaf Numbers | Medium | Binary Tree | `0129_sum_root_to_leaf_numbers` | — | `stub` |
| 130 | Surrounded Regions | Medium | Graph | `0130_surrounded_regions` | — | `stub` |
| 134 | Gas Station | Medium | Array/String | `0134_gas_station` | Яндекс | `stub` |
| 135 | Candy | Hard | Array/String | `0135_candy` | — | `stub` |
| 136 | Single Number | Easy | Bit Manipulation | `0136_single_number` | Яндекс | `stub` |
| 139 | Word Break | Medium | DP | `0139_word_break` | Яндекс | `stub` |
| 141 | Linked List Cycle | Easy | Linked List | `0141_linked_list_cycle` | Яндекс | `stub` |
| 143 | Reorder List | Medium | Linked List | `0143_reorder_list` | — | `stub` |
| 146 | LRU Cache | Medium | Linked List | `0146_lru_cache` | Яндекс | `stub` |
| 148 | Sort List | Medium | Divide & Conquer | `0148_sort_list` | Яндекс | `stub` |
| 150 | Evaluate Reverse Polish Notation | Medium | Stack | `0150_evaluate_reverse_polish_notation` | Яндекс | `stub` |
| 151 | Reverse Words in a String | Medium | Array/String | `0151_reverse_words_in_a_string` | Яндекс | `stub` |
| 152 | Maximum Product Subarray | Medium | DP | `0152_maximum_product_subarray` | Яндекс | `stub` |
| 153 | Find Minimum in Rotated Sorted Array | Medium | Binary Search | `0153_find_minimum_in_rotated_sorted_array` | — | `stub` |
| 155 | Min Stack | Medium | Stack | `0155_min_stack` | Яндекс | `stub` |
| 167 | Two Sum II - Input Array Is Sorted | Medium | Two Pointers | `0167_two_sum_ii_input_array_is_sorted` | Яндекс | `stub` |
| 169 | Majority Element | Easy | Array/String | `0169_majority_element` | Яндекс, VK | `stub` |
| 173 | Binary Search Tree Iterator | Medium | BST | `0173_binary_search_tree_iterator` | — | `stub` |
| 174 | Dungeon Game | Hard | DP | `0174_dungeon_game` | — | `stub` |
| 188 | Best Time to Buy and Sell Stock IV | Hard | DP | `0188_best_time_to_buy_and_sell_stock_iv` | — | `stub` |
| 189 | Rotate Array | Medium | Array/String | `0189_rotate_array` | Яндекс | `stub` |
| 190 | Reverse Bits | Easy | Bit Manipulation | `0190_reverse_bits` | — | `stub` |
| 191 | Number of 1 Bits | Easy | Bit Manipulation | `0191_number_of_1_bits` | — | `stub` |
| 198 | House Robber | Medium | Kadane | `0198_house_robber` | Яндекс | `stub` |
| 199 | Binary Tree Right Side View | Medium | Binary Tree BFS | `0199_binary_tree_right_side_view` | Яндекс | `stub` |
| 200 | Number of Islands | Medium | Graph | `0200_number_of_islands` | Яндекс | `stub` |
| 202 | Happy Number | Easy | Hashmap | `0202_happy_number` | — | `stub` |
| 205 | Isomorphic Strings | Easy | Hashmap | `0205_isomorphic_strings` | — | `stub` |
| 206 | Reverse Linked List | Easy | Linked List | `0206_reverse_linked_list` | Яндекс, Tinkoff | `stub` |
| 207 | Course Schedule | Medium | Graph | `0207_course_schedule` | Яндекс | `stub` |
| 208 | Implement Trie (Prefix Tree) | Medium | Trie | `0208_implement_trie_prefix_tree` | Яндекс | `stub` |
| 209 | Minimum Size Subarray Sum | Medium | Sliding Window | `0209_minimum_size_subarray_sum` | Яндекс | `stub` |
| 210 | Course Schedule II | Medium | Graph | `0210_course_schedule_ii` | Яндекс | `stub` |
| 211 | Design Add and Search Words Data Structure | Medium | Trie | `0211_design_add_and_search_words_data_structure` | — | `stub` |
| 212 | Word Search II | Hard | Trie | `0212_word_search_ii` | — | `stub` |
| 213 | House Robber II | Medium | Kadane | `0213_house_robber_ii` | — | `stub` |
| 215 | Kth Largest Element in an Array | Medium | Hashmap | `0215_kth_largest_element_in_an_array` | Яндекс | `stub` |
| 217 | Contains Duplicate | Easy | Hashmap | `0217_contains_duplicate` | Wildberries, Яндекс | `stub` |
| 219 | Contains Duplicate II | Easy | Hashmap | `0219_contains_duplicate_ii` | Wildberries | `stub` |
| 221 | Maximal Square | Medium | DP | `0221_maximal_square` | — | `stub` |
| 222 | Count Complete Tree Nodes | Easy | Binary Tree | `0222_count_complete_tree_nodes` | — | `stub` |
| 224 | Basic Calculator | Hard | Stack | `0224_basic_calculator` | — | `stub` |
| 226 | Invert Binary Tree | Easy | Binary Tree | `0226_invert_binary_tree` | Яндекс | `stub` |
| 228 | Summary Ranges | Easy | Intervals | `0228_summary_ranges` | VK, Ozon | `stub` |
| 230 | Kth Smallest Element in a BST | Medium | BST | `0230_kth_smallest_element_in_a_bst` | Яндекс | `stub` |
| 231 | Power of Two | Easy | Bit Manipulation | `0231_power_of_two` | Ozon | `stub` |
| 235 | Lowest Common Ancestor of a Binary Search Tree | Easy | BST | `0235_lowest_common_ancestor_of_a_binary_search_tree` | — | `stub` |
| 236 | Lowest Common Ancestor of a Binary Tree | Medium | Binary Tree | `0236_lowest_common_ancestor_of_a_binary_tree` | Яндекс | `stub` |
| 238 | Product of Array Except Self | Medium | Array/String | `0238_product_of_array_except_self` | Яндекс | `stub` |
| 239 | Sliding Window Maximum | Hard | Sliding Window | `0239_sliding_window_maximum` | Яндекс | `stub` |
| 242 | Valid Anagram | Easy | Hashmap | `0242_valid_anagram` | Яндекс | `stub` |
| 268 | Missing Number | Easy | Bit Manipulation | `0268_missing_number` | — | `stub` |
| 274 | H-Index | Medium | Array/String | `0274_h_index` | Ozon | `stub` |
| 289 | Game of Life | Medium | Matrix | `0289_game_of_life` | — | `stub` |
| 290 | Word Pattern | Easy | Hashmap | `0290_word_pattern` | — | `stub` |
| 300 | Longest Increasing Subsequence | Medium | DP | `0300_longest_increasing_subsequence` | Яндекс | `stub` |
| 309 | Best Time to Buy and Sell Stock with Cooldown | Medium | DP | `0309_best_time_to_buy_and_sell_stock_with_cooldown` | — | `stub` |
| 322 | Coin Change | Medium | DP | `0322_coin_change` | Яндекс | `stub` |
| 338 | Counting Bits | Easy | Bit Manipulation | `0338_counting_bits` | — | `stub` |
| 347 | Top K Frequent Elements | Medium | Hashmap | `0347_top_k_frequent_elements` | Яндекс | `stub` |
| 383 | Ransom Note | Easy | Hashmap | `0383_ransom_note` | — | `stub` |
| 392 | Is Subsequence | Easy | Two Pointers | `0392_is_subsequence` | — | `stub` |
| 399 | Evaluate Division | Medium | Graph | `0399_evaluate_division` | — | `stub` |
| 416 | Partition Equal Subset Sum | Medium | DP | `0416_partition_equal_subset_sum` | Яндекс | `stub` |
| 424 | Longest Repeating Character Replacement | Medium | Sliding Window | `0424_longest_repeating_character_replacement` | — | `stub` |
| 433 | Minimum Genetic Mutation | Medium | Graph BFS | `0433_minimum_genetic_mutation` | — | `stub` |
| 452 | Minimum Number of Arrows to Burst Balloons | Medium | Intervals | `0452_minimum_number_of_arrows_to_burst_balloons` | Яндекс | `stub` |
| 513 | Find Bottom Left Tree Value | Medium | Binary Tree BFS | `0513_find_bottom_left_tree_value` | — | `stub` |
| 518 | Coin Change II | Medium | DP | `0518_coin_change_ii` | — | `stub` |
| 530 | Minimum Absolute Difference in BST | Easy | BST | `0530_minimum_absolute_difference_in_bst` | — | `stub` |
| 567 | Permutation in String | Medium | Sliding Window | `0567_permutation_in_string` | — | `stub` |
| 637 | Average of Levels in Binary Tree | Easy | Binary Tree BFS | `0637_average_of_levels_in_binary_tree` | — | `stub` |
| 704 | Binary Search | Easy | Binary Search | `0704_binary_search` | — | `stub` |
| 739 | Daily Temperatures | Medium | Stack | `0739_daily_temperatures` | Яндекс | `stub` |
| 746 | Min Cost Climbing Stairs | Easy | DP | `0746_min_cost_climbing_stairs` | — | `stub` |
| 849 | Maximize Distance to Closest Person | Medium | Array/String | `0849_maximize_distance_to_closest_person` | VK | `stub` |
| 875 | Koko Eating Bananas | Medium | Binary Search | `0875_koko_eating_bananas` | Яндекс | `stub` |
| 896 | Monotonic Array | Easy | Array/String | `0896_monotonic_array` | Ozon | `stub` |
| 909 | Snakes and Ladders | Medium | Graph BFS | `0909_snakes_and_ladders` | — | `stub` |
| 918 | Maximum Sum Circular Subarray | Medium | Kadane | `0918_maximum_sum_circular_subarray` | — | `stub` |
| 973 | K Closest Points to Origin | Medium | Hashmap | `0973_k_closest_points_to_origin` | Яндекс | `stub` |
| 1143 | Longest Common Subsequence | Medium | DP | `1143_longest_common_subsequence` | — | `stub` |

<!-- TOP_INTERVIEW_END -->
