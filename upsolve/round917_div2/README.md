# Div 2 - Round 917

## Problem C - Watering an Array

### TLDR

Brute force , Iterate through all days find what the answer would be if that day was chosen for adding to the score , this question required removing extra details and simplifying the solution.

## Description

If you consider the array to be all zeroes then the max score you can add will be one as any operation will not make the array into strictly increasing which is required to attain a score greater than 1 . So the max score you can get is one and the you reset and again you add one and so on. This removes one layer of complexity

Another observation is that you need not go through all days , you only need to check the first 2 x n days . To prove this first understand that the maximum score that you can attain on any day is n , so if you do not attain a score of n in the first 2n days then another strategy could be you reset the array on the first day , then after 2n days you will get a score of n added by the alternating operations strategy.

These two observations will lead you to the brute force solution.
